@copyright

#include <errno.h>

#include "packet_filters.h"
#include "gtpv2c_set_ie.h"
#include "../cp_dp_api/vepc_cp_dp_api.h"

/** Information Elements in create_session_response */
struct parse_create_session_response_t {
	gtpv2c_ie *cause;
	gtpv2c_ie *change_reporting_action_;
	gtpv2c_ie *csg_information_reporting_action;
	gtpv2c_ie *h_enb_information_reporting;
	gtpv2c_ie *sender_f_teid_for_control_plane;
	gtpv2c_ie *pgw_s5s8_s2as2b_f_teid_for_pmip_based_interface_or_for_gtp_based_control_plane_interface;
	gtpv2c_ie *pdn_address_allocation_;
	gtpv2c_ie *apn_restriction;
	gtpv2c_ie *aggregate_maximum_bit_rate_;
	gtpv2c_ie *linked_eps_bearer_id;
	gtpv2c_ie *protocol_configuration_options_;
	gtpv2c_ie *bearer_contexts_created;
	gtpv2c_ie *bearer_contexts_marked_for_removal;
	gtpv2c_ie *recovery;
	gtpv2c_ie *charging_gateway_name;
	gtpv2c_ie *charging_gateway_address;
	gtpv2c_ie *pgw_fq_csid;
	gtpv2c_ie *sgw_fq_csid;
	gtpv2c_ie *sgw_ldn;
	gtpv2c_ie *pgw_ldn;
	gtpv2c_ie *pgw_back_off_time;
	gtpv2c_ie *additional_protocol_configuration_options_;
	gtpv2c_ie *trusted_wlan_ipv4_parameters_;
	gtpv2c_ie *indication_flags;
	gtpv2c_ie *presence_reporting_area_action;
	gtpv2c_ie *pgw_node_level_load_control_information;
	gtpv2c_ie *pgw_apn_level_load_control_information;
	gtpv2c_ie *sgw_node_level_load_control_information;
	gtpv2c_ie *pgw_overload_control_information;
	gtpv2c_ie *sgw_overload_control_information;
	gtpv2c_ie *nbifom_container;
	gtpv2c_ie *pdn_connection_charging_id;
	gtpv2c_ie *extended_protocol_configuration_options_;
	gtpv2c_ie *private_extension;
};

static int
parse_create_session_response(gtpv2c_header *gtpv2c_rx,
          struct parse_create_session_response_t *csr)
{
    gtpv2c_ie *current_ie;
    gtpv2c_ie *current_group_ie;
    gtpv2c_ie *limit_ie;
    gtpv2c_ie *limit_group_ie;
    
    FOR_EACH_GTPV2C_IE(gtpv2c_rx, current_ie, limit_ie)
    {
		if (current_ie->type == IE_CAUSE &&
			current_ie->instance == 0) {
			csr->cause = current_ie;
		} else if (current_ie->type == IE_CHANGE_REPORTING_ACTION &&
			current_ie->instance == 0) {
			csr->change_reporting_action_ = current_ie;
		} else if (current_ie->type == IE_CSG_REPORTING_ACTION &&
			current_ie->instance == 0) {
			csr->csg_information_reporting_action = current_ie;
		} else if (current_ie->type == IE_H_E_NB_INFORMATION_REPORTING &&
			current_ie->instance == 0) {
			csr->h_enb_information_reporting = current_ie;
		} else if (current_ie->type == IE_FULLY_QUALIFIED_TUNNEL_ENDPOINT_IDENTIFIER &&
			current_ie->instance == 0) {
			csr->sender_f_teid_for_control_plane = current_ie;
		} else if (current_ie->type == IE_FULLY_QUALIFIED_TUNNEL_ENDPOINT_IDENTIFIER &&
			current_ie->instance == 1) {
			csr->pgw_s5s8_s2as2b_f_teid_for_pmip_based_interface_or_for_gtp_based_control_plane_interface = current_ie;
		} else if (current_ie->type == IE_PDN_ADDRESS_ALLOCATION &&
			current_ie->instance == 0) {
			csr->pdn_address_allocation_ = current_ie;
		} else if (current_ie->type == IE_ACCESS_POINT_NAME_RESTRICTION &&
			current_ie->instance == 0) {
			csr->apn_restriction = current_ie;
		} else if (current_ie->type == IE_AGGREGATE_MAXIMUM_BIT_RATE &&
			current_ie->instance == 0) {
			csr->aggregate_maximum_bit_rate_ = current_ie;
		} else if (current_ie->type == IE_EPS_BEARER_ID &&
			current_ie->instance == 0) {
			csr->linked_eps_bearer_id = current_ie;
		} else if (current_ie->type == IE_PROTOCOL_CONFIGURATION_OPTIONS &&
			current_ie->instance == 0) {
			csr->protocol_configuration_options_ = current_ie;
		} else if (current_ie->type == IE_BEARER_CONTEXT &&
			current_ie->instance == 0) {
			csr->bearer_contexts_created = current_ie;
		} else if (current_ie->type == IE_BEARER_CONTEXT &&
			current_ie->instance == 1) {
			csr->bearer_contexts_marked_for_removal = current_ie;
		} else if (current_ie->type == IE_RECOVERY_RESTART_COUNTER &&
			current_ie->instance == 0) {
			csr->recovery = current_ie;
		} else if (current_ie->type == IE_FULLY_QUALIFIED_DOMAIN_NAME &&
			current_ie->instance == 0) {
			csr->charging_gateway_name = current_ie;
		} else if (current_ie->type == IE_IP_ADDRESS &&
			current_ie->instance == 0) {
			csr->charging_gateway_address = current_ie;
		} else if (current_ie->type == IE_FQ_CSID &&
			current_ie->instance == 0) {
			csr->pgw_fq_csid = current_ie;
		} else if (current_ie->type == IE_FQ_CSID &&
			current_ie->instance == 1) {
			csr->sgw_fq_csid = current_ie;
		} else if (current_ie->type == IE_LOCAL_DISTINGUISHED_NAME &&
			current_ie->instance == 0) {
			csr->sgw_ldn = current_ie;
		} else if (current_ie->type == IE_LOCAL_DISTINGUISHED_NAME &&
			current_ie->instance == 1) {
			csr->pgw_ldn = current_ie;
		} else if (current_ie->type == IE_EPC_TIMER &&
			current_ie->instance == 0) {
			csr->pgw_back_off_time = current_ie;
		} else if (current_ie->type == IE_ADDITIONAL_PROTOCOL_CONFIGURATION_OPTIONS &&
			current_ie->instance == 0) {
			csr->additional_protocol_configuration_options_ = current_ie;
		} else if (current_ie->type == IE_IPV4_CONFIGURATION_PARAMETERS &&
			current_ie->instance == 0) {
			csr->trusted_wlan_ipv4_parameters_ = current_ie;
		} else if (current_ie->type == IE_INDICATION &&
			current_ie->instance == 0) {
			csr->indication_flags = current_ie;
		} else if (current_ie->type == IE_PRESENCE_REPORTING_AREA_ACTION &&
			current_ie->instance == 0) {
			csr->presence_reporting_area_action = current_ie;
		} else if (current_ie->type == IE_LOAD_CONTROL_INFORMATION &&
			current_ie->instance == 0) {
			csr->pgw_node_level_load_control_information = current_ie;
		} else if (current_ie->type == IE_LOAD_CONTROL_INFORMATION &&
			current_ie->instance == 1) {
			csr->pgw_apn_level_load_control_information = current_ie;
		} else if (current_ie->type == IE_LOAD_CONTROL_INFORMATION &&
			current_ie->instance == 2) {
			csr->sgw_node_level_load_control_information = current_ie;
		} else if (current_ie->type == IE_OVERLOAD_CONTROL_INFORMATION &&
			current_ie->instance == 0) {
			csr->pgw_overload_control_information = current_ie;
		} else if (current_ie->type == IE_OVERLOAD_CONTROL_INFORMATION &&
			current_ie->instance == 1) {
			csr->sgw_overload_control_information = current_ie;
		} else if (current_ie->type == IE_FULLY_QUALIFIED_CONTAINER &&
			current_ie->instance == 0) {
			csr->nbifom_container = current_ie;
		} else if (current_ie->type == IE_CHARGING_ID &&
			current_ie->instance == 0) {
			csr->pdn_connection_charging_id = current_ie;
		} else if (current_ie->type == IE_EXTENDED_PROTOCOL_CONFIGURATION_OPTIONS &&
			current_ie->instance == 0) {
			csr->extended_protocol_configuration_options_ = current_ie;
		} else if (current_ie->type == IE_PRIVATE_EXTENSION) {
			csr->private_extension = current_ie;
		}

    }
    
	if (!csr->cause
		|| !csr->bearer_contexts_created) {
		fprintf(stderr, "Dropping packet\n");
		return -EPERM;
	}

    return 0;
}

// TODO
static void
set_create_session_response() {
    /* TODO */
}

int
process_create_session_response(gtpv2c_header *gtpv2c_rx,
                               gtpv2c_header *gtpv2c_tx)
{
    /* TODO */
}
