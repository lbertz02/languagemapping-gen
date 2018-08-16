@copyright

#include <errno.h>

#include "packet_filters.h"
#include "gtpv2c_set_ie.h"
#include "../cp_dp_api/vepc_cp_dp_api.h"

/** Information Elements in create_bearer_request */
struct parse_create_bearer_request_t {
	gtpv2c_ie *procedure_transaction_id_;
	gtpv2c_ie *linked_eps_bearer_id_;
	gtpv2c_ie *protocol_configuration_options_;
	gtpv2c_ie *bearer_contexts;
	gtpv2c_ie *pgw_fq_csid;
	gtpv2c_ie *sgw_fq_csid;
	gtpv2c_ie *change_reporting_action;
	gtpv2c_ie *csg_information_reporting_action;
	gtpv2c_ie *h_enb_information_reporting;
	gtpv2c_ie *presence_reporting_area_action;
	gtpv2c_ie *indication_flags;
	gtpv2c_ie *pgw_node_level_load_control_information;
	gtpv2c_ie *pgw_apn_level_load_control_information;
	gtpv2c_ie *sgw_node_level_load_control_information;
	gtpv2c_ie *pgw_overload_control_information;
	gtpv2c_ie *sgw_overload_control_information;
	gtpv2c_ie *nbifom_container;
	gtpv2c_ie *private_extension;
};

static int
parse_create_bearer_request(gtpv2c_header *gtpv2c_rx,
          struct parse_create_bearer_request_t *cbr)
{
    gtpv2c_ie *current_ie;
    gtpv2c_ie *current_group_ie;
    gtpv2c_ie *limit_ie;
    gtpv2c_ie *limit_group_ie;
    
    FOR_EACH_GTPV2C_IE(gtpv2c_rx, current_ie, limit_ie)
    {
		if (current_ie->type == IE_PROCEDURE_TRANSACTION_ID &&
			current_ie->instance == 0) {
			cbr->procedure_transaction_id_ = current_ie;
		} else if (current_ie->type == IE_EPS_BEARER_ID &&
			current_ie->instance == 0) {
			cbr->linked_eps_bearer_id_ = current_ie;
		} else if (current_ie->type == IE_PROTOCOL_CONFIGURATION_OPTIONS &&
			current_ie->instance == 0) {
			cbr->protocol_configuration_options_ = current_ie;
		} else if (current_ie->type == IE_BEARER_CONTEXT &&
			current_ie->instance == 0) {
			cbr->bearer_contexts = current_ie;
		} else if (current_ie->type == IE_FQ_CSID &&
			current_ie->instance == 0) {
			cbr->pgw_fq_csid = current_ie;
		} else if (current_ie->type == IE_FQ_CSID &&
			current_ie->instance == 1) {
			cbr->sgw_fq_csid = current_ie;
		} else if (current_ie->type == IE_CHANGE_REPORTING_ACTION &&
			current_ie->instance == 0) {
			cbr->change_reporting_action = current_ie;
		} else if (current_ie->type == IE_CSG_REPORTING_ACTION &&
			current_ie->instance == 0) {
			cbr->csg_information_reporting_action = current_ie;
		} else if (current_ie->type == IE_H_E_NB_INFORMATION_REPORTING &&
			current_ie->instance == 0) {
			cbr->h_enb_information_reporting = current_ie;
		} else if (current_ie->type == IE_PRESENCE_REPORTING_AREA_ACTION &&
			current_ie->instance == 0) {
			cbr->presence_reporting_area_action = current_ie;
		} else if (current_ie->type == IE_INDICATION &&
			current_ie->instance == 0) {
			cbr->indication_flags = current_ie;
		} else if (current_ie->type == IE_LOAD_CONTROL_INFORMATION &&
			current_ie->instance == 0) {
			cbr->pgw_node_level_load_control_information = current_ie;
		} else if (current_ie->type == IE_LOAD_CONTROL_INFORMATION &&
			current_ie->instance == 1) {
			cbr->pgw_apn_level_load_control_information = current_ie;
		} else if (current_ie->type == IE_LOAD_CONTROL_INFORMATION &&
			current_ie->instance == 2) {
			cbr->sgw_node_level_load_control_information = current_ie;
		} else if (current_ie->type == IE_OVERLOAD_CONTROL_INFORMATION &&
			current_ie->instance == 0) {
			cbr->pgw_overload_control_information = current_ie;
		} else if (current_ie->type == IE_OVERLOAD_CONTROL_INFORMATION &&
			current_ie->instance == 1) {
			cbr->sgw_overload_control_information = current_ie;
		} else if (current_ie->type == IE_FULLY_QUALIFIED_CONTAINER &&
			current_ie->instance == 0) {
			cbr->nbifom_container = current_ie;
		} else if (current_ie->type == IE_PRIVATE_EXTENSION) {
			cbr->private_extension = current_ie;
		}

    }
    
	if (!cbr->linked_eps_bearer_id_
		|| !cbr->bearer_contexts) {
		fprintf(stderr, "Dropping packet\n");
		return -EPERM;
	}

    return 0;
}

// TODO
static void
set_create_bearer_request() {
    /* TODO */
}

int
process_create_bearer_request(gtpv2c_header *gtpv2c_rx,
                               gtpv2c_header *gtpv2c_tx)
{
    /* TODO */
}
