@copyright

#include <errno.h>

#include "packet_filters.h"
#include "gtpv2c_set_ie.h"
#include "../cp_dp_api/vepc_cp_dp_api.h"

/** Information Elements in modify_bearer_response */
struct parse_modify_bearer_response_t {
	gtpv2c_ie *cause;
	gtpv2c_ie *msisdn;
	gtpv2c_ie *linked_eps_bearer_id;
	gtpv2c_ie *apn_restriction;
	gtpv2c_ie *protocol_configuration_options;
	gtpv2c_ie *bearer_contexts_modified;
	gtpv2c_ie *bearer_contexts_marked_for_removal;
	gtpv2c_ie *change_reporting_action;
	gtpv2c_ie *csg_information_reporting_action;
	gtpv2c_ie *h_enb_information_reporting;
	gtpv2c_ie *charging_gateway_name;
	gtpv2c_ie *charging_gateway_address;
	gtpv2c_ie *pgw_fq_csid;
	gtpv2c_ie *sgw_fq_csid;
	gtpv2c_ie *recovery;
	gtpv2c_ie *sgw_ldn;
	gtpv2c_ie *pgw_ldn;
	gtpv2c_ie *indication_flags;
	gtpv2c_ie *presence_reporting_area_action;
	gtpv2c_ie *pgw_node_level_load_control_information;
	gtpv2c_ie *pgw_apn_level_load_control_information;
	gtpv2c_ie *sgw_node_level_load_control_information;
	gtpv2c_ie *pgw_overload_control_information;
	gtpv2c_ie *sgw_overload_control_information;
	gtpv2c_ie *pdn_connection_charging_id;
	gtpv2c_ie *private_extension;
};

static int
parse_modify_bearer_response(gtpv2c_header *gtpv2c_rx,
          struct parse_modify_bearer_response_t *mbr)
{
    gtpv2c_ie *current_ie;
    gtpv2c_ie *current_group_ie;
    gtpv2c_ie *limit_ie;
    gtpv2c_ie *limit_group_ie;
    
    FOR_EACH_GTPV2C_IE(gtpv2c_rx, current_ie, limit_ie)
    {
		if (current_ie->type == IE_CAUSE &&
			current_ie->instance == 0) {
			mbr->cause = current_ie;
		} else if (current_ie->type == IE_MSISDN &&
			current_ie->instance == 0) {
			mbr->msisdn = current_ie;
		} else if (current_ie->type == IE_EPS_BEARER_ID &&
			current_ie->instance == 0) {
			mbr->linked_eps_bearer_id = current_ie;
		} else if (current_ie->type == IE_ACCESS_POINT_NAME_RESTRICTION &&
			current_ie->instance == 0) {
			mbr->apn_restriction = current_ie;
		} else if (current_ie->type == IE_PROTOCOL_CONFIGURATION_OPTIONS &&
			current_ie->instance == 0) {
			mbr->protocol_configuration_options = current_ie;
		} else if (current_ie->type == IE_BEARER_CONTEXT &&
			current_ie->instance == 0) {
			mbr->bearer_contexts_modified = current_ie;
		} else if (current_ie->type == IE_BEARER_CONTEXT &&
			current_ie->instance == 1) {
			mbr->bearer_contexts_marked_for_removal = current_ie;
		} else if (current_ie->type == IE_CHANGE_REPORTING_ACTION &&
			current_ie->instance == 0) {
			mbr->change_reporting_action = current_ie;
		} else if (current_ie->type == IE_CSG_REPORTING_ACTION &&
			current_ie->instance == 0) {
			mbr->csg_information_reporting_action = current_ie;
		} else if (current_ie->type == IE_H_E_NB_INFORMATION_REPORTING &&
			current_ie->instance == 0) {
			mbr->h_enb_information_reporting = current_ie;
		} else if (current_ie->type == IE_FULLY_QUALIFIED_DOMAIN_NAME &&
			current_ie->instance == 0) {
			mbr->charging_gateway_name = current_ie;
		} else if (current_ie->type == IE_IP_ADDRESS &&
			current_ie->instance == 0) {
			mbr->charging_gateway_address = current_ie;
		} else if (current_ie->type == IE_FQ_CSID &&
			current_ie->instance == 0) {
			mbr->pgw_fq_csid = current_ie;
		} else if (current_ie->type == IE_FQ_CSID &&
			current_ie->instance == 1) {
			mbr->sgw_fq_csid = current_ie;
		} else if (current_ie->type == IE_RECOVERY_RESTART_COUNTER &&
			current_ie->instance == 0) {
			mbr->recovery = current_ie;
		} else if (current_ie->type == IE_LOCAL_DISTINGUISHED_NAME &&
			current_ie->instance == 0) {
			mbr->sgw_ldn = current_ie;
		} else if (current_ie->type == IE_LOCAL_DISTINGUISHED_NAME &&
			current_ie->instance == 1) {
			mbr->pgw_ldn = current_ie;
		} else if (current_ie->type == IE_INDICATION &&
			current_ie->instance == 0) {
			mbr->indication_flags = current_ie;
		} else if (current_ie->type == IE_PRESENCE_REPORTING_AREA_ACTION &&
			current_ie->instance == 0) {
			mbr->presence_reporting_area_action = current_ie;
		} else if (current_ie->type == IE_LOAD_CONTROL_INFORMATION &&
			current_ie->instance == 0) {
			mbr->pgw_node_level_load_control_information = current_ie;
		} else if (current_ie->type == IE_LOAD_CONTROL_INFORMATION &&
			current_ie->instance == 1) {
			mbr->pgw_apn_level_load_control_information = current_ie;
		} else if (current_ie->type == IE_LOAD_CONTROL_INFORMATION &&
			current_ie->instance == 2) {
			mbr->sgw_node_level_load_control_information = current_ie;
		} else if (current_ie->type == IE_OVERLOAD_CONTROL_INFORMATION &&
			current_ie->instance == 0) {
			mbr->pgw_overload_control_information = current_ie;
		} else if (current_ie->type == IE_OVERLOAD_CONTROL_INFORMATION &&
			current_ie->instance == 1) {
			mbr->sgw_overload_control_information = current_ie;
		} else if (current_ie->type == IE_CHARGING_ID &&
			current_ie->instance == 0) {
			mbr->pdn_connection_charging_id = current_ie;
		} else if (current_ie->type == IE_PRIVATE_EXTENSION) {
			mbr->private_extension = current_ie;
		}

    }
    
	if (!mbr->cause) {
		fprintf(stderr, "Dropping packet\n");
		return -EPERM;
	}

    return 0;
}

// TODO
static void
set_modify_bearer_response() {
    /* TODO */
}

int
process_modify_bearer_response(gtpv2c_header *gtpv2c_rx,
                               gtpv2c_header *gtpv2c_tx)
{
    /* TODO */
}
