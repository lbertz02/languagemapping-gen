"""ngic style gtp ie output plugin
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

def pyang_plugin_init():
    plugin.register_plugin(gtp2ngicMessagePlugin())

class gtp2ngicMessagePlugin(plugin.PyangPlugin):
    def add_output_format(self, fmts):
        fmts['ngic-message'] = self

    def add_opts(self, optparser):
        optlist = [
            optparse.make_option('--ngic-message-debug',
                                 dest='ngic_debug',
                                 action="store_true",
                                 help='NGIC Message Generator debug'),
            optparse.make_option('--ngic-message-path',
                                 dest='gen_path',
                                 help='NGIC Message Generator path'),
            optparse.make_option('--ngic-message-title',
                                 dest='gen_title',
                                 help='NGIC Message Generator title')
            ]

        group = optparser.add_option_group("NGIC Message Generator specific options")
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
        result = "/* GTP Message Type Values */\n"

        # Produce Registry values
        msgs = []
        msg_reg = {}
        counter = 1000
        if root_stmt.i_groupings is not None and len(root_stmt.i_groupings) > 0:
            msgs = [x for x in root_stmt.i_groupings.values() if is_message(x)]
            for stmt in msgs:
                try:
                    w = int(get_substmt( (u'ts29274-messages-f40', u'messageTypeValue'), stmt).arg)
                except ValueError:
                    w = counter
                    counter += 1
                msg_reg[w] = stmt.arg
            if len(msgs) > 0:
                for key in sorted(msg_reg.iterkeys()):
                    result += "{:<75}".format("#define GTP_" + msg_reg[key].upper()) + "(" + str(key) +")\n"

        # Only used for cross checking the file in the log debug.  It is very helpful though.
        generated_msgs = []
        for msg in msgs:
            if msg.arg not in generated_msgs:
                (name, type, typeValue) = get_message_info(msg)
                basename = "_".join( name.lower().split("_")[:-1] )
                companion_message = None
                for x in msgs:
                    if x.arg.startswith(basename) and x.arg != name:
                        companion_message = x
                        logging.debug("Found %s companion message for %s", x.arg, name)
                if companion_message is None:
                    logging.debug("Did not find companion message for %s", name)
                        #else:
                #(headerlist, basetext) = produce_message(msg)

                generated_msgs.append(msg.arg)
                if companion_message is not None:
                    generated_msgs.append(companion_message.arg)
        
        for msg in msgs:
            template_file = open("message_proto.c","r")
            template = template_file.read()
            template_file.close()
            produce_message(msg, template)

        hdr_file = open("gtpv2.h","w")
        hdr_file.write(result)
        hdr_file.close()

        fd.write( "Processing Complete" )

def produce_message(stmt, template):
    template = template.replace("AAA",stmt.arg.lower())
    
    x_val = stmt.arg.lower().split("_")
    var_name = ""
    for z in x_val:
        var_name += z[0]
    template = template.replace("VVV", var_name)

    if_stmts = []
    mandatory_checks = []
    member_defs = []
    members = {}
    for x in stmt.substmts:
        if x.keyword == 'container':
            (m_name, m_order, m_mandatory, m_instance_no, m_uses) = get_message_member_info(x)
            members[int(m_order)] = (m_name, m_order, m_mandatory, m_instance_no, m_uses)
    for key in sorted(members.iterkeys()):
        (m_name, m_order, m_mandatory, m_instance_no, m_uses) = members[key]
        
        member_defs.append( "gtpv2c_ie *" + m_name + ";" )
        
        ie_cap_nm = m_uses.arg
        if ":" in ie_cap_nm:
            ie_cap_nm = ie_cap_nm.split(":")[1:][0]
        ie_cap_nm = "IE_" + ie_cap_nm.upper()
        logging.debug("IE Name = %s", ie_cap_nm)
        if_txt = "if (current_ie->type == " + ie_cap_nm
        if m_instance_no is None:
            if_txt += ") {"
        else:
            if_txt += " &&\n\t\t\tcurrent_ie->instance == " + str(m_instance_no) + ") {"
        if_txt += "\n\t\t\t" + var_name + "->" + m_name + " = current_ie;\n\t\t}"
        if_stmts.append(if_txt)

        if m_mandatory:
            logging.debug("Appending a mandatory check for %s", var_name)
            mandatory_checks.append( "!" + var_name + "->" + m_name )

    template = template.replace( "BBB", "\t" + "\n\t".join(member_defs) )
    template = template.replace( "CCC", "\t\t" + " else ".join(if_stmts) + "\n")
    checks = ""
    if len(mandatory_checks) > 0:
        checks = "\tif (" + "\n\t\t|| ".join(mandatory_checks) + ") {\n"
        checks += "\t\tfprintf(stderr, \"Dropping packet\\n\");\n\t\treturn -EPERM;\n\t}\n"
    logging.debug("Checks value is %s", checks)
    template = template.replace( "DDD", checks )

    fname = "messages/" + stmt.arg.lower() + ".c"
    logging.debug("Creating Message file - %s", fname)
    logging.debug("File Contents are %s", template)
    msg_file = open(fname,"w")
    msg_file.write(template)
    msg_file.close()

def get_message_member_info(stmt):
    mand = get_substmt((u'ts29274-messages-f40', u'iemandatory'), stmt)
    mandatory = True if mand is not None else False
    order = int( get_substmt((u'ts29274-ies-f40', u'order'), stmt).arg )
    instance_num = get_substmt((u'ts29274-messages-f40', u'intsancenum'), stmt)
    instance_no = None if instance_num is None else int(instance_num.arg)
    logging.debug( "message_member_info: (%s, %s, %s, %s, %s)", stmt.arg, str(order), mandatory, str(instance_no), get_substmt('uses', stmt).arg )
    return ( stmt.arg, order, mandatory, instance_no, get_substmt('uses', stmt) )

def get_substmts(name, stmt):
    if hasattr(stmt, 'substmts'):
        return [x for x in stmt.substmts if x.keyword == name]
    return []

def get_substmt(name, stmt):
    x = get_substmts(name, stmt)
    if len(x) > 0:
        return x[0]
    return None

def is_message(stmt):
    if hasattr(stmt, 'substmts'):
        y = [x for x in stmt.substmts if x.keyword == (u'ts29274-messages-f40', u'messageType') ]
        if len(y) > 0:
            return True
    return False

def get_message_info(stmt):
    return ( stmt.arg, get_substmt((u'ts29274-messages-f40', u'messageType'), stmt), get_substmt((u'ts29274-messages-f40', u'messageTypeValue'), stmt) )
