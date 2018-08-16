@copyright

#include <errno.h>

#include "packet_filters.h"
#include "gtpv2c_set_ie.h"
#include "../cp_dp_api/vepc_cp_dp_api.h"

/** Information Elements in delete_bearer_request */
struct parse_delete_bearer_request_t {
	gtpv2c_ie *eps_bearer_ids;
	gtpv2c_ie *failed_bearer_contexts;
	gtpv2c_ie *procedure_transaction_id;
	gtpv2c_ie *protocol_configuration_options;
	gtpv2c_ie *pgw_fq_csid;
	gtpv2c_ie *sgw_fq_csid;
	gtpv2c_ie *indication_flags;
	gtpv2c_ie *pgw_node_level_load_control_information;
	gtpv2c_ie *pgw_apn_level_load_control_information;
	gtpv2c_ie *sgw_node_level_load_control_information;
	gtpv2c_ie *pgw_overload_control_information;
	gtpv2c_ie *sgw_overload_control_information;
	gtpv2c_ie *nbifom_container;
	gtpv2c_ie *extended_protocol_configuration_options;
	gtpv2c_ie *private_extension;
};

static int
parse_delete_bearer_request(gtpv2c_header *gtpv2c_rx,
          struct parse_delete_bearer_request_t *dbr)
{
    gtpv2c_ie *current_ie;
    gtpv2c_ie *current_group_ie;
    gtpv2c_ie *limit_ie;
    gtpv2c_ie *limit_group_ie;
    
    FOR_EACH_GTPV2C_IE(gtpv2c_rx, current_ie, limit_ie)
    {
		if (current_ie->type == IE_EPS_BEARER_ID &&
			current_ie->instance == 1) {
			dbr->eps_bearer_ids = current_ie;
		} else if (current_ie->type == IE_BEARER_CONTEXT &&
			current_ie->instance == 0) {
			dbr->failed_bearer_contexts = current_ie;
		} else if (current_ie->type == IE_PROCEDURE_TRANSACTION_ID &&
			current_ie->instance == 0) {
			dbr->procedure_transaction_id = current_ie;
		} else if (current_ie->type == IE_PROTOCOL_CONFIGURATION_OPTIONS &&
			current_ie->instance == 0) {
			dbr->protocol_configuration_options = current_ie;
		} else if (current_ie->type == IE_FQ_CSID &&
			current_ie->instance == 0) {
			dbr->pgw_fq_csid = current_ie;
		} else if (current_ie->type == IE_FQ_CSID &&
			current_ie->instance == 1) {
			dbr->sgw_fq_csid = current_ie;
		} else if (current_ie->type == IE_INDICATION &&
			current_ie->instance == 0) {
			dbr->indication_flags = current_ie;
		} else if (current_ie->type == IE_LOAD_CONTROL_INFORMATION &&
			current_ie->instance == 0) {
			dbr->pgw_node_level_load_control_information = current_ie;
		} else if (current_ie->type == IE_LOAD_CONTROL_INFORMATION &&
			current_ie->instance == 1) {
			dbr->pgw_apn_level_load_control_information = current_ie;
		} else if (current_ie->type == IE_LOAD_CONTROL_INFORMATION &&
			current_ie->instance == 2) {
			dbr->sgw_node_level_load_control_information = current_ie;
		} else if (current_ie->type == IE_OVERLOAD_CONTROL_INFORMATION &&
			current_ie->instance == 0) {
			dbr->pgw_overload_control_information = current_ie;
		} else if (current_ie->type == IE_OVERLOAD_CONTROL_INFORMATION &&
			current_ie->instance == 1) {
			dbr->sgw_overload_control_information = current_ie;
		} else if (current_ie->type == IE_FULLY_QUALIFIED_CONTAINER &&
			current_ie->instance == 0) {
			dbr->nbifom_container = current_ie;
		} else if (current_ie->type == IE_EXTENDED_PROTOCOL_CONFIGURATION_OPTIONS &&
			current_ie->instance == 0) {
			dbr->extended_protocol_configuration_options = current_ie;
		} else if (current_ie->type == IE_PRIVATE_EXTENSION) {
			dbr->private_extension = current_ie;
		}

    }
    

    return 0;
}

// TODO
static void
set_delete_bearer_request() {
    /* TODO */
}

int
process_delete_bearer_request(gtpv2c_header *gtpv2c_rx,
                               gtpv2c_header *gtpv2c_tx)
{
    /* TODO */
}
