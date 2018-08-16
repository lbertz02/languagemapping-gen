@copyright

#include <errno.h>

#include "packet_filters.h"
#include "gtpv2c_set_ie.h"
#include "../cp_dp_api/vepc_cp_dp_api.h"

/** Information Elements in mbms_session_start_request */
struct parse_mbms_session_start_request_t {
	gtpv2c_ie *sender_fully_qualified_tunnel_endpoint_identifier_for_control_plane;
	gtpv2c_ie *temporary_mobile_group_identity;
	gtpv2c_ie *mbms_session_duration;
	gtpv2c_ie *mbms_service_area;
	gtpv2c_ie *mbms_session_identifier;
	gtpv2c_ie *mbms_flow_identifier;
	gtpv2c_ie *qos_profile;
	gtpv2c_ie *mbms_ip_multicast_distribution;
	gtpv2c_ie *recovery;
	gtpv2c_ie *mbms_time_to_data_transfer;
	gtpv2c_ie *mbms_data_transfer_start;
	gtpv2c_ie *mbms_flags;
	gtpv2c_ie *mbms_alternative_ip_multicast_distribution;
	gtpv2c_ie *mbms_cell_list;
	gtpv2c_ie *private_extension;
};

static int
parse_mbms_session_start_request(gtpv2c_header *gtpv2c_rx,
          struct parse_mbms_session_start_request_t *mssr)
{
    gtpv2c_ie *current_ie;
    gtpv2c_ie *current_group_ie;
    gtpv2c_ie *limit_ie;
    gtpv2c_ie *limit_group_ie;
    
    FOR_EACH_GTPV2C_IE(gtpv2c_rx, current_ie, limit_ie)
    {
		if (current_ie->type == IE_FULLY_QUALIFIED_TUNNEL_ENDPOINT_IDENTIFIER &&
			current_ie->instance == 0) {
			mssr->sender_fully_qualified_tunnel_endpoint_identifier_for_control_plane = current_ie;
		} else if (current_ie->type == IE_TMGI &&
			current_ie->instance == 0) {
			mssr->temporary_mobile_group_identity = current_ie;
		} else if (current_ie->type == IE_MBMS_SESSION_DURATION &&
			current_ie->instance == 0) {
			mssr->mbms_session_duration = current_ie;
		} else if (current_ie->type == IE_MBMS_SERVICE_AREA &&
			current_ie->instance == 0) {
			mssr->mbms_service_area = current_ie;
		} else if (current_ie->type == IE_MBMS_SESSION_IDENTIFIER &&
			current_ie->instance == 0) {
			mssr->mbms_session_identifier = current_ie;
		} else if (current_ie->type == IE_MBMS_FLOW_IDENTIFIER &&
			current_ie->instance == 0) {
			mssr->mbms_flow_identifier = current_ie;
		} else if (current_ie->type == IE_BEARER_QUALITY_OF_SERVICE &&
			current_ie->instance == 0) {
			mssr->qos_profile = current_ie;
		} else if (current_ie->type == IE_MBMS_IP_MULTICAST_DISTRIBUTION &&
			current_ie->instance == 0) {
			mssr->mbms_ip_multicast_distribution = current_ie;
		} else if (current_ie->type == IE_RECOVERY_RESTART_COUNTER &&
			current_ie->instance == 0) {
			mssr->recovery = current_ie;
		} else if (current_ie->type == IE_MBMS_TIME_TO_DATA_TRANSFER &&
			current_ie->instance == 0) {
			mssr->mbms_time_to_data_transfer = current_ie;
		} else if (current_ie->type == IE_ABSOLUTE_TIME_OF_MBMS_DATA_TRANSFER &&
			current_ie->instance == 0) {
			mssr->mbms_data_transfer_start = current_ie;
		} else if (current_ie->type == IE_MBMS_FLAGS &&
			current_ie->instance == 0) {
			mssr->mbms_flags = current_ie;
		} else if (current_ie->type == IE_MBMS_IP_MULTICAST_DISTRIBUTION &&
			current_ie->instance == 1) {
			mssr->mbms_alternative_ip_multicast_distribution = current_ie;
		} else if (current_ie->type == IE_ECGI_LIST &&
			current_ie->instance == 0) {
			mssr->mbms_cell_list = current_ie;
		} else if (current_ie->type == IE_PRIVATE_EXTENSION) {
			mssr->private_extension = current_ie;
		}

    }
    
	if (!mssr->sender_fully_qualified_tunnel_endpoint_identifier_for_control_plane
		|| !mssr->temporary_mobile_group_identity
		|| !mssr->mbms_session_duration
		|| !mssr->mbms_service_area
		|| !mssr->qos_profile
		|| !mssr->mbms_ip_multicast_distribution) {
		fprintf(stderr, "Dropping packet\n");
		return -EPERM;
	}

    return 0;
}

// TODO
static void
set_mbms_session_start_request() {
    /* TODO */
}

int
process_mbms_session_start_request(gtpv2c_header *gtpv2c_rx,
                               gtpv2c_header *gtpv2c_tx)
{
    /* TODO */
}
