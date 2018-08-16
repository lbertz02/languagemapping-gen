@copyright

#include <errno.h>

#include "packet_filters.h"
#include "gtpv2c_set_ie.h"
#include "../cp_dp_api/vepc_cp_dp_api.h"

/** Information Elements in delete_bearer_response */
struct parse_delete_bearer_response_t {
	gtpv2c_ie *cause;
	gtpv2c_ie *linked_eps_bearer_id;
	gtpv2c_ie *bearer_context;
	gtpv2c_ie *recovery;
	gtpv2c_ie *mme_fq_csid;
	gtpv2c_ie *sgw_fq_csid;
	gtpv2c_ie *epdg_fq_csid;
	gtpv2c_ie *twan_fq_csid;
	gtpv2c_ie *protocol_configuration_options;
	gtpv2c_ie *ue_time_zone;
	gtpv2c_ie *user_location_information;
	gtpv2c_ie *uli_timestamp;
	gtpv2c_ie *twan_identifier;
	gtpv2c_ie *twan_identifier_timestamp;
	gtpv2c_ie *mmes4_sgsn_overload_control_information;
	gtpv2c_ie *sgw_overload_control_information;
	gtpv2c_ie *mmes4_sgsn_identifier;
	gtpv2c_ie *twanepdg_overload_control_information;
	gtpv2c_ie *wlan_location_information;
	gtpv2c_ie *wlan_location_timestamp;
	gtpv2c_ie *ue_local_ip_address;
	gtpv2c_ie *ue_udp_port;
	gtpv2c_ie *nbifom_container;
	gtpv2c_ie *ue_tcp_port;
	gtpv2c_ie *secondary_rat_usage_data_report;
	gtpv2c_ie *private_extension;
};

static int
parse_delete_bearer_response(gtpv2c_header *gtpv2c_rx,
          struct parse_delete_bearer_response_t *dbr)
{
    gtpv2c_ie *current_ie;
    gtpv2c_ie *current_group_ie;
    gtpv2c_ie *limit_ie;
    gtpv2c_ie *limit_group_ie;
    
    FOR_EACH_GTPV2C_IE(gtpv2c_rx, current_ie, limit_ie)
    {
		if (current_ie->type == IE_CAUSE &&
			current_ie->instance == 0) {
			dbr->cause = current_ie;
		} else if (current_ie->type == IE_EPS_BEARER_ID &&
			current_ie->instance == 0) {
			dbr->linked_eps_bearer_id = current_ie;
		} else if (current_ie->type == IE_BEARER_CONTEXT &&
			current_ie->instance == 0) {
			dbr->bearer_context = current_ie;
		} else if (current_ie->type == IE_RECOVERY_RESTART_COUNTER &&
			current_ie->instance == 0) {
			dbr->recovery = current_ie;
		} else if (current_ie->type == IE_FQ_CSID &&
			current_ie->instance == 0) {
			dbr->mme_fq_csid = current_ie;
		} else if (current_ie->type == IE_FQ_CSID &&
			current_ie->instance == 1) {
			dbr->sgw_fq_csid = current_ie;
		} else if (current_ie->type == IE_FQ_CSID &&
			current_ie->instance == 2) {
			dbr->epdg_fq_csid = current_ie;
		} else if (current_ie->type == IE_FQ_CSID &&
			current_ie->instance == 3) {
			dbr->twan_fq_csid = current_ie;
		} else if (current_ie->type == IE_PROTOCOL_CONFIGURATION_OPTIONS &&
			current_ie->instance == 0) {
			dbr->protocol_configuration_options = current_ie;
		} else if (current_ie->type == IE_UE_TIME_ZONE &&
			current_ie->instance == 0) {
			dbr->ue_time_zone = current_ie;
		} else if (current_ie->type == IE_USER_LOCATION_INFORMATION &&
			current_ie->instance == 0) {
			dbr->user_location_information = current_ie;
		} else if (current_ie->type == IE_ULI_TIMESTAMP &&
			current_ie->instance == 0) {
			dbr->uli_timestamp = current_ie;
		} else if (current_ie->type == IE_TWAN_IDENTIFIER &&
			current_ie->instance == 0) {
			dbr->twan_identifier = current_ie;
		} else if (current_ie->type == IE_TWAN_IDENTIFIER_TIMESTAMP &&
			current_ie->instance == 0) {
			dbr->twan_identifier_timestamp = current_ie;
		} else if (current_ie->type == IE_OVERLOAD_CONTROL_INFORMATION &&
			current_ie->instance == 0) {
			dbr->mmes4_sgsn_overload_control_information = current_ie;
		} else if (current_ie->type == IE_OVERLOAD_CONTROL_INFORMATION &&
			current_ie->instance == 1) {
			dbr->sgw_overload_control_information = current_ie;
		} else if (current_ie->type == IE_IP_ADDRESS &&
			current_ie->instance == 0) {
			dbr->mmes4_sgsn_identifier = current_ie;
		} else if (current_ie->type == IE_OVERLOAD_CONTROL_INFORMATION &&
			current_ie->instance == 2) {
			dbr->twanepdg_overload_control_information = current_ie;
		} else if (current_ie->type == IE_TWAN_IDENTIFIER &&
			current_ie->instance == 1) {
			dbr->wlan_location_information = current_ie;
		} else if (current_ie->type == IE_TWAN_IDENTIFIER_TIMESTAMP &&
			current_ie->instance == 1) {
			dbr->wlan_location_timestamp = current_ie;
		} else if (current_ie->type == IE_IP_ADDRESS &&
			current_ie->instance == 0) {
			dbr->ue_local_ip_address = current_ie;
		} else if (current_ie->type == IE_PORT_NUMBER &&
			current_ie->instance == 0) {
			dbr->ue_udp_port = current_ie;
		} else if (current_ie->type == IE_FULLY_QUALIFIED_CONTAINER &&
			current_ie->instance == 0) {
			dbr->nbifom_container = current_ie;
		} else if (current_ie->type == IE_PORT_NUMBER &&
			current_ie->instance == 1) {
			dbr->ue_tcp_port = current_ie;
		} else if (current_ie->type == IE_SECONDARY_RAT_USAGE_DATA_REPORT &&
			current_ie->instance == 0) {
			dbr->secondary_rat_usage_data_report = current_ie;
		} else if (current_ie->type == IE_PRIVATE_EXTENSION) {
			dbr->private_extension = current_ie;
		}

    }
    
	if (!dbr->cause) {
		fprintf(stderr, "Dropping packet\n");
		return -EPERM;
	}

    return 0;
}

// TODO
static void
set_delete_bearer_response() {
    /* TODO */
}

int
process_delete_bearer_response(gtpv2c_header *gtpv2c_rx,
                               gtpv2c_header *gtpv2c_tx)
{
    /* TODO */
}
