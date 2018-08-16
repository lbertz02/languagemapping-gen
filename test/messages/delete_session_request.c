@copyright

#include <errno.h>

#include "packet_filters.h"
#include "gtpv2c_set_ie.h"
#include "../cp_dp_api/vepc_cp_dp_api.h"

/** Information Elements in delete_session_request */
struct parse_delete_session_request_t {
	gtpv2c_ie *linked_eps_bearer_id;
	gtpv2c_ie *user_location_information;
	gtpv2c_ie *indication_flags;
	gtpv2c_ie *protocol_configuration_options;
	gtpv2c_ie *originating_node;
	gtpv2c_ie *sender_f_teid_for_control_plane;
	gtpv2c_ie *ue_time_zone;
	gtpv2c_ie *uli_timestamp;
	gtpv2c_ie *ran_nas_release_cause;
	gtpv2c_ie *twan_identifier;
	gtpv2c_ie *twan_identifier_timestamp;
	gtpv2c_ie *mmes4_sgsn_overload_control_information;
	gtpv2c_ie *sgw_overload_control_information;
	gtpv2c_ie *twanepdg_overload_control_information;
	gtpv2c_ie *wlan_location_information;
	gtpv2c_ie *wlan_location_timestamp;
	gtpv2c_ie *ue_local_ip_address;
	gtpv2c_ie *ue_udp_port;
	gtpv2c_ie *extended_protocol_configuration_options;
	gtpv2c_ie *ue_tcp_port;
	gtpv2c_ie *secondary_rat_usage_data_report;
	gtpv2c_ie *private_extension;
};

static int
parse_delete_session_request(gtpv2c_header *gtpv2c_rx,
          struct parse_delete_session_request_t *dsr)
{
    gtpv2c_ie *current_ie;
    gtpv2c_ie *current_group_ie;
    gtpv2c_ie *limit_ie;
    gtpv2c_ie *limit_group_ie;
    
    FOR_EACH_GTPV2C_IE(gtpv2c_rx, current_ie, limit_ie)
    {
		if (current_ie->type == IE_EPS_BEARER_ID &&
			current_ie->instance == 0) {
			dsr->linked_eps_bearer_id = current_ie;
		} else if (current_ie->type == IE_USER_LOCATION_INFORMATION &&
			current_ie->instance == 0) {
			dsr->user_location_information = current_ie;
		} else if (current_ie->type == IE_INDICATION &&
			current_ie->instance == 0) {
			dsr->indication_flags = current_ie;
		} else if (current_ie->type == IE_PROTOCOL_CONFIGURATION_OPTIONS &&
			current_ie->instance == 0) {
			dsr->protocol_configuration_options = current_ie;
		} else if (current_ie->type == IE_NODE_TYPE &&
			current_ie->instance == 0) {
			dsr->originating_node = current_ie;
		} else if (current_ie->type == IE_FULLY_QUALIFIED_TUNNEL_ENDPOINT_IDENTIFIER &&
			current_ie->instance == 0) {
			dsr->sender_f_teid_for_control_plane = current_ie;
		} else if (current_ie->type == IE_UE_TIME_ZONE &&
			current_ie->instance == 0) {
			dsr->ue_time_zone = current_ie;
		} else if (current_ie->type == IE_ULI_TIMESTAMP &&
			current_ie->instance == 0) {
			dsr->uli_timestamp = current_ie;
		} else if (current_ie->type == IE_RAN_NAS_CAUSE &&
			current_ie->instance == 0) {
			dsr->ran_nas_release_cause = current_ie;
		} else if (current_ie->type == IE_TWAN_IDENTIFIER &&
			current_ie->instance == 0) {
			dsr->twan_identifier = current_ie;
		} else if (current_ie->type == IE_TWAN_IDENTIFIER_TIMESTAMP &&
			current_ie->instance == 0) {
			dsr->twan_identifier_timestamp = current_ie;
		} else if (current_ie->type == IE_OVERLOAD_CONTROL_INFORMATION &&
			current_ie->instance == 0) {
			dsr->mmes4_sgsn_overload_control_information = current_ie;
		} else if (current_ie->type == IE_OVERLOAD_CONTROL_INFORMATION &&
			current_ie->instance == 1) {
			dsr->sgw_overload_control_information = current_ie;
		} else if (current_ie->type == IE_OVERLOAD_CONTROL_INFORMATION &&
			current_ie->instance == 2) {
			dsr->twanepdg_overload_control_information = current_ie;
		} else if (current_ie->type == IE_TWAN_IDENTIFIER &&
			current_ie->instance == 1) {
			dsr->wlan_location_information = current_ie;
		} else if (current_ie->type == IE_TWAN_IDENTIFIER_TIMESTAMP &&
			current_ie->instance == 1) {
			dsr->wlan_location_timestamp = current_ie;
		} else if (current_ie->type == IE_IP_ADDRESS &&
			current_ie->instance == 0) {
			dsr->ue_local_ip_address = current_ie;
		} else if (current_ie->type == IE_PORT_NUMBER &&
			current_ie->instance == 0) {
			dsr->ue_udp_port = current_ie;
		} else if (current_ie->type == IE_EXTENDED_PROTOCOL_CONFIGURATION_OPTIONS &&
			current_ie->instance == 0) {
			dsr->extended_protocol_configuration_options = current_ie;
		} else if (current_ie->type == IE_PORT_NUMBER &&
			current_ie->instance == 1) {
			dsr->ue_tcp_port = current_ie;
		} else if (current_ie->type == IE_SECONDARY_RAT_USAGE_DATA_REPORT &&
			current_ie->instance == 0) {
			dsr->secondary_rat_usage_data_report = current_ie;
		} else if (current_ie->type == IE_PRIVATE_EXTENSION) {
			dsr->private_extension = current_ie;
		}

    }
    

    return 0;
}

// TODO
static void
set_delete_session_request() {
    /* TODO */
}

int
process_delete_session_request(gtpv2c_header *gtpv2c_rx,
                               gtpv2c_header *gtpv2c_tx)
{
    /* TODO */
}
