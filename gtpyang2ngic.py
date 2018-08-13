"""ngic style gtp output plugin
"""

# pylint: disable=C0111

from __future__ import print_function

import optparse
import logging
import numbers

from pyang import plugin
from pyang import statements
from pyang import types
from pyang import error

logging.basicConfig(filename="test.log", level=logging.DEBUG)

#Used to capture refcounts for reporting
refcounts = {}
unknown_refs = []

def pyang_plugin_init():
    plugin.register_plugin(gtp2ngicPlugin())

class gtp2ngicPlugin(plugin.PyangPlugin):
    def add_output_format(self, fmts):
        fmts['ngic'] = self

    def add_opts(self, optparser):
        optlist = [
            optparse.make_option('--ngic-debug',
                                 dest='schema_debug',
                                 action="store_true",
                                 help='NGIC Generator debug'),
            optparse.make_option('--ngic-path',
                                 dest='schema_path',
                                 help='NGIC Generator path'),
            optparse.make_option('--ngic-title',
                                 dest='schema_title',
                                 help='NGIC Generator title')
            ]

        group = optparser.add_option_group("NGIC Generator specific options")
        group.add_options(optlist)

    def setup_ctx(self, ctx):
        ctx.opts.stmts = None

    def setup_fmt(self, ctx):
        ctx.implicit_errors = False

    def emit(self, ctx, modules, fd):
        root_stmt = modules[0]
        if ctx.opts.schema_debug:
            logging.basicConfig(level=logging.DEBUG)
            print("")
        if ctx.opts.schema_path is not None:
            logging.debug("schema_path: %s", ctx.opts.schema_path)
            path = ctx.opts.schema_path
            root_stmt = find_stmt_by_path(modules[0], path)
        else:
            path = None

        if ctx.opts.schema_title is not None:
            schema_title = ctx.opts.schema_title
        else:
            schema_title = root_stmt.arg

        description_str = "Generated by pyang from module %s" % modules[0].arg
        result = "/* Information Element type values according to 3GPP TS 29.274 Table 8.1-1 */\n"

        #Process IEs first
        # Produce Registry values
        ie_reg = {}
        counter = 1000
        if root_stmt.i_groupings is not None and len(root_stmt.i_groupings) > 0:
            ies = [x for x in root_stmt.i_groupings.values() if is_ie(x)]
            for stmt in ies:
                try:
                    w = int(get_substmt( (u'ts29274-ies-f40', u'ie-type'), stmt).arg)
                except ValueError:
                    w = counter
                    counter += 1
                ie_reg[w] = stmt.arg
            if len(ies) > 0:
                for key in sorted(ie_reg.iterkeys()):
                    result += "{:<65}".format("#define IE_" + ie_reg[key].upper()) + "(" + str(key) +")\n"
        fd.write( result )

def is_ie(stmt):
    if hasattr(stmt, 'substmts'):
        y = [x for x in stmt.substmts if x.keyword == (u'ts29274-ies-f40', u'ie-type')]
        if len(y) > 0:
            return True
    return False

def get_substmts(name, stmt):
    if hasattr(stmt, 'substmts'):
        return [x for x in stmt.substmts if x.keyword == name]
    return []

def get_substmt(name, stmt):
    x = get_substmts(name, stmt)
    if len(x) > 0:
        return x[0]
    return None

"""
def xxx():
    if root_stmt.i_typedefs is not None and len(root_stmt.i_typedefs) > 0:
        result['definitions']['type-definitions'] = { }
        for stmt in modules[0].i_typedefs.values():
            if should_emit(stmt):
                type_definition = produce_typedef(stmt)
                result['definitions']['type-definitions'].update(type_definition)
                refcounts['type-definitions/#/definitions/type-definition/' + type_definition.iterkeys().next()] = 0

    schema = produce_schema(root_stmt)
    result["properties"].update(schema)

    dump_stats()

    fd.write(json.dumps(result, indent=2))

def should_emit(stmt):
    return false if get_substmt("status", stmt) == 'deprecated' else true

def find_stmt_by_path(module, path):
    logging.debug("in find_stmt_by_path with: %s %s path: %s", module.keyword, module.arg, path)

    if path is not None:
        spath = path.split("/")
        if spath[0] == '':
            spath = spath[1:]

    children = [child for child in module.i_children
                if child.keyword in statements.data_definition_keywords]

    while spath is not None and len(spath) > 0:
        match = [child for child in children if child.arg == spath[0]
                 and child.keyword in statements.data_definition_keywords]
        if len(match) > 0:
            logging.debug("Match on: %s, path: %s", match[0].arg, spath)
            spath = spath[1:]
            children = match[0].i_children
            logging.debug("Path is now: %s", spath)
        else:
            logging.debug("Miss at %s, path: %s", children, spath)
            raise error.EmitError("Path '%s' does not exist in module" % path)

    logging.debug("Ended up with %s %s", match[0].keyword, match[0].arg)
    return match[0]

def produce_schema(root_stmt):
    logging.debug("in produce_schema: %s %s", root_stmt.keyword, root_stmt.arg)
    result = {}

    for child in root_stmt.i_children:
        if child.keyword in statements.data_definition_keywords:
            if child.keyword in producers:
                logging.debug("keyword hit on: %s %s", child.keyword, child.arg)
                add = producers[child.keyword](child)
                result.update(add)
            else:
                logging.debug("keyword miss on: %s %s", child.keyword, child.arg)
        else:
            logging.debug("keyword not in data_definition_keywords: %s %s", child.keyword,
                          child.arg)
    return result

def produce_type(type_stmt):
    logging.debug("In produce_type with: %s %s", type_stmt.keyword, type_stmt.arg)
    type_id = type_stmt.arg

    if types.is_base_type(type_id):
        if type_id in _numeric_type_trans_tbl:
            type_str = _numeric_type_trans_tbl[type_id]
        elif type_id in _other_type_trans_tbl:
            type_str = other_type_trans(type_id, type_stmt)
        else:
            logging.debug("Missing mapping of base type: %s %s",
                          type_stmt.keyword, type_stmt.arg)
            type_str = {"type": "string"}
    elif hasattr(type_stmt, "i_typedef") and type_stmt.i_typedef is not None:
        logging.debug("Found typedef type in: %s %s (typedef) %s",
                      type_stmt.keyword, type_stmt.arg, type_stmt.i_typedef)
        type_name = type_stmt.arg.split(':')[-1]
        type_str = { "$ref" : ("#/definitions/type-definitions/definitions/%s" % type_name) }
        update_stats(type_name, 'type-definitions')
    else:
        logging.debug("Missing mapping of: %s %s",
                      type_stmt.keyword, type_stmt.arg, type_stmt.i_typede)
        type_str = {"type": "string"}
    return type_str

def produce_leaf(stmt):
    logging.debug("in produce_leaf: %s %s", stmt.keyword, stmt.arg)
    arg = qualify_name(stmt)

    type_stmt = stmt.search_one('type')
    type_str = produce_type(type_stmt)

    return {arg: type_str}

def produce_list(stmt):
    logging.debug("in produce_list: %s %s", stmt.keyword, stmt.arg)
    arg = qualify_name(stmt)

    result = { arg: {"type": "array", "items": { "type" : "object", "properties":{} }  } }

    if hasattr(stmt, 'substmts'):
        for child in stmt.substmts:
            if child.keyword in producers:
                logging.debug("keyword hit on: %s %s", child.keyword, child.arg)
                x = producers[child.keyword](child)
                if child.keyword == 'container':
                    logging.debug("Adding the following to list = %s" % str(x))
                result[arg]["items"]["properties"].update(producers[child.keyword](child))
            else:
                logging.debug("keyword miss on: %s %s", child.keyword, child.arg)
    logging.debug("In produce_list for %s, returning %s", stmt.arg, result)
    return result

def produce_leaf_list(stmt):
    logging.debug("in produce_leaf_list: %s %s", stmt.keyword, stmt.arg)
    arg = qualify_name(stmt)
    type_stmt = stmt.search_one('type')
    type_id = type_stmt.arg

    if types.is_base_type(type_id) or type_id in _other_type_trans_tbl:
        type_str = produce_type(type_stmt)
        result = {arg: {"type": "array", "items": [type_str]}}
    else:
        logging.debug("Missing mapping of base type: %s %s, type: %s",
                      stmt.keyword, stmt.arg, type_id)
        result = {arg: {"type": "array", "items": [{"type": "string"}]}}
    return result

def produce_container(stmt):
    logging.debug("in produce_container: %s %s", stmt.keyword, stmt.arg)
    arg = qualify_name(stmt)

    result = {arg: {"type": "object", "properties": {}}}

    if hasattr(stmt, 'substmts'):
        for child in stmt.substmts:
            if child.keyword in producers:
                logging.debug("keyword hit on: %s %s", child.keyword, child.arg)
                result[arg]["properties"].update(producers[child.keyword](child))
            else:
                logging.debug("keyword miss on: %s %s", child.keyword, child.arg)
    logging.debug("In produce_container, returning %s", result)
    return result

def produce_choice(stmt):
    logging.debug("in produce_choice: %s %s", stmt.keyword, stmt.arg)

    result = {}

    # https://tools.ietf.org/html/rfc6020#section-7.9.2
    for case in stmt.search("case"):
        if hasattr(case, 'substmts'):
            for child in case.substmts:
                if child.keyword in producers:
                    logging.debug("keyword hit on (long version): %s %s", child.keyword, child.arg)
                    result.update(producers[child.keyword](child))
                else:
                    logging.debug("keyword miss on: %s %s", child.keyword, child.arg)

    # Short ("case-less") version
    #  https://tools.ietf.org/html/rfc6020#section-7.9.2
    for child in stmt.substmts:
        logging.debug("checking on keywords with: %s %s", child.keyword, child.arg)
        if child.keyword in ["container", "leaf", "list", "leaf-list"]:
            logging.debug("keyword hit on (short version): %s %s", child.keyword, child.arg)
            result.update(producers[child.keyword](child))

    logging.debug("In produce_choice, returning %s", result)
    return result

_numeric_type_trans_tbl = {
    # https://tools.ietf.org/html/draft-ietf-netmod-yang-json-02#section-6
    "int8": { "type":"integer", "minimum":-128, "maximum":127 },
    "int16": { "type":"integer", "minimum":-32768, "maximum":32767 },
    "int32": { "type":"integer", "minimum":-2147483648, "maximum":2147483647 },
    "int64": { "type":"integer", "minimum":-9223372036854775808, "maximum":9223372036854775807 },
    "uint8": { "type":"integer", "minimum":0, "maximum":255 },
    "uint16": { "type":"integer", "minimum":0, "maximum":65535 },
    "uint32": { "type":"integer", "minimum":0, "maximum":4294967295 },
    "uint64": { "type":"integer", "minimum":0, "maximum":18446744073709551615 }
    }

def string_trans(stmt):
    logging.debug("in string_trans with stmt %s %s", stmt.keyword, stmt.arg)
    result = {"type": "string"}
    return result

def enumeration_trans(stmt):
    logging.debug("in enumeration_trans with stmt %s %s", stmt.keyword, stmt.arg)
    result = {"type": "string", "enum": [] }
    for enum in stmt.search("enum"):
        result["enum"].append(enum.arg)
    logging.debug("In enumeration_trans for %s, returning %s", stmt.arg, result)
    return result

def bits_trans(stmt):
    logging.debug("in bits_trans with stmt %s %s", stmt.keyword, stmt.arg)
    bitslength = 0
    result = {"type": "string"}
    for child in stmt.substmts:
        if child.keyword == "bit":
            incremented = False
            y = get_substmt("position", child)
            if y is not None:
                if (bitslength < y.arg):
                    bitslength = int(y.arg)
                    incremented = True
            if not incremented:
                bitslength += 1
    if bitslength > 0:
        result["pattern"] = ("[01]{%d}" % bitslength)
    return result

def boolean_trans(stmt):
    logging.debug("in boolean_trans with stmt %s %s", stmt.keyword, stmt.arg)
    result = {"type": "boolean"}
    return result

def empty_trans(stmt):
    logging.debug("in empty_trans with stmt %s %s", stmt.keyword, stmt.arg)
    result = {"type": "array", "items": [{"type": "null"}]}
    # Likely needs more/other work per:
    #  https://tools.ietf.org/html/draft-ietf-netmod-yang-json-10#section-6.9
    return result

def union_trans(stmt):
    logging.debug("in union_trans with stmt %s %s", stmt.keyword, stmt.arg)
    result = {"oneOf": []}
    for member in stmt.search("type"):
        member_type = produce_type(member)
        result["oneOf"].append(member_type)
    return result

def instance_identifier_trans(stmt):
    logging.debug("in instance_identifier_trans with stmt %s %s", stmt.keyword, stmt.arg)
    result = {"type": "string"}
    return result

def leafref_trans(stmt):
    logging.debug("in leafref_trans with stmt %s %s", stmt.keyword, stmt.arg)
    # TODO: Need to resolve i_leafref_ptr here 
    result = {"type": "string"}
    return result

_other_type_trans_tbl = {
    # https://tools.ietf.org/html/draft-ietf-netmod-yang-json-02#section-6
    "string":                   string_trans,
    "enumeration":              enumeration_trans,
    "bits":                     bits_trans,
    "boolean":                  boolean_trans,
    "empty":                    empty_trans,
    "union":                    union_trans,
    "instance-identifier":      instance_identifier_trans,
    "leafref":                  leafref_trans,
    "binary":                   binary_trans
}

def other_type_trans(dtype, stmt):
    return _other_type_trans_tbl[dtype](stmt)

def qualify_name(stmt):
    # From: draft-ietf-netmod-yang-json
    # A namespace-qualified member name MUST be used for all members of a
    # top-level JSON object, and then also whenever the namespaces of the
    # data node and its parent node are different.  In all other cases, the
    # simple form of the member name MUST be used.
    if stmt.parent.parent is None: # We're on top
        pfx = stmt.i_module.arg
        logging.debug("In qualify_name with: %s %s on top", stmt.keyword, stmt.arg)
        return pfx + ":" + stmt.arg
    if stmt.top.arg != stmt.parent.top.arg: # Parent node is different
        pfx = stmt.top.arg
        logging.debug("In qualify_name with: %s %s and parent is different", stmt.keyword, stmt.arg)
        return pfx + ":" + stmt.arg
    return stmt.arg

def produce_grouping(stmt):
    # Like produce_container but will add the children to "definitions" as opposed to 'properties'
    container_form = produce_container(stmt)
    qname = qualify_name(stmt)
    return { str(stmt.arg) : { 'definitions' : container_form[qname].pop('properties') } }

def produce_typedef(stmt):
    logging.debug("in produce_typedef: %s %s", stmt.keyword, stmt.arg)
    type_stmt = stmt.search_one('type')
    type_str = produce_type(type_stmt)
    x = stmt.arg.split(':')
    if 'properties' in type_str:
        if 'type' in type_str['properties']:
            type_str = { x[-1:][0] : type_str['properties']['type'] }
    return { x[-1:][0]: type_str}

def produce_uses(stmt,prefix="#/definitions/groupings/definitions/"):
    logging.debug("in produce_uses: %s %s", stmt.keyword, stmt.arg)
    val = ("%s/%s/definitions" % (prefix, qualify_name(stmt) )).replace("//", "/")
    
    target_name = stmt.arg if ':' not in stmt.arg else stmt.arg.split(':')[1]
    update_stats(target_name,'groupings')
    
    logging.debug("Statement Target Name = %s & Main Module = %s" % (target_name, str(stmt.main_module().arg)) )
    
    # Locate the grouping
    mod = stmt.i_module.i_ctx.get_module(stmt.arg.split(':')[0])
    if mod is None:
        mod = stmt.main_module()
    match = [child for child in mod.substmts if child.arg == target_name and child.keyword == 'grouping']

    result = { }
    if len(match) == 0:
        logging.debug("Grouping NOT found for %s" % stmt.arg)
        result = {
            "$ref" : val
            }
        update_stats(val)
    else:
        qpath = prefix + stmt.arg.split(':')[-1] + '/definitions'
        logging.debug("Grouping found for %s" % stmt.arg)
        for child in match[0].substmts:
            rpath = ''
            if child.keyword in statements.data_definition_keywords or \
                child.keyword in [ 'choice', 'case' ]:
                logging.debug("SEARCHING %s %s" % (child.keyword, child.arg))
                value = producers[child.keyword](child)
                for (k,v) in value.items():
                    logging.debug("Producing Uses child of %s" % str(k))
                    if k != '$ref':
                        result[k.split('/')[-1]] = { "$ref" : ("%s" % str(qpath + '/' + k) )}
                        val = str(qpath + '/' + k)
                    else:
                        result[k] = v
                        val = v
                    update_stats(val,val=v)
            elif child.keyword == 'uses':
                value = produce_uses(child, qpath)
                for (k,v) in value.items():
                    logging.debug("Producing Uses / Uses child of %s" % str(k))
                    result[k] = v

    logging.debug("In produce_uses, returning %s", result)
    return result

def produce_copy(stmt):
    return { stmt.keyword : stmt:arg }

def produce_status(stmt):
    val = 'true' if stmt.arg == 'current' else 'false'
    return { "deprecated" : val} 

producers = {
    # "module":     produce_module,
    "container":    produce_container,
    "list":         produce_list,
    "leaf-list":    produce_leaf_list,
    "leaf":         produce_leaf,
    "choice":       produce_choice,
    "uses":         produce_uses,
    "description":  produce_copy,
    "status": produce_status
}

def update_stats(ref,type=None, val=None):
    if type is not None:
        if type == 'type-definitions':
            name = "type-definitions/#/definitions/type-definition/definitions/" + ref
        elif type == 'groupings':
            name = "groupings/#/definitions/groupings/definitions/" + ref
        else:
            raise Exception("Unknown Statistic type %s" % type)
    else:
        if 'type-definition' in ref:
            name = 'type-definitions/' + ref
        elif 'groupings' in ref:
            name = 'groupings/' + ref
        else:
            name = 'unknown/' + ref
            logging.debug("Unknown ref %s: %s" % (str(ref), str(val)))
            unknown_refs.append(ref)
    val = 1 if name not in refcounts else (refcounts[name] + 1)
    refcounts[name] = val
"""

def dump_stats():
    logging.debug("\n\n\n>>>>>>>>>>>>>>>> Reference Statistics <<<<<<<<<<<<<<<<<<<<\n\n")
    for k,v in sorted(refcounts.iteritems(), key=lambda (k,v): (v,k)):
            logging.debug("%s: %s" % (str(k), str(v)))
    logging.debug("\n\nUnknown Items\n\n")
    for i in unknown_refs:
        logging.debug("%s\n" % str(i))
    logging.debug("\n\n")
    


