@copyright

#include <errno.h>

#include "packet_filters.h"
#include "gtpv2c_set_ie.h"
#include "../cp_dp_api/vepc_cp_dp_api.h"

/** Information Elements in mbms_session_update_request */
struct parse_mbms_session_update_request_t {
	gtpv2c_ie *mbms_service_area;
	gtpv2c_ie *temporary_mobile_group_identity;
	gtpv2c_ie *sender_f_teid_for_control_plane;
	gtpv2c_ie *mbms_session_duration;
	gtpv2c_ie *qos_profile;
	gtpv2c_ie *mbms_session_identifier;
	gtpv2c_ie *mbms_flow_identifier;
	gtpv2c_ie *mbms_time_to_data_transfer;
	gtpv2c_ie *mbms_data_transfer_start_update_stop;
	gtpv2c_ie *mbms_cell_list;
	gtpv2c_ie *private_extension;
};

static int
parse_mbms_session_update_request(gtpv2c_header *gtpv2c_rx,
          struct parse_mbms_session_update_request_t *msur)
{
    gtpv2c_ie *current_ie;
    gtpv2c_ie *current_group_ie;
    gtpv2c_ie *limit_ie;
    gtpv2c_ie *limit_group_ie;
    
    FOR_EACH_GTPV2C_IE(gtpv2c_rx, current_ie, limit_ie)
    {
		if (current_ie->type == IE_MBMS_SERVICE_AREA &&
			current_ie->instance == 0) {
			msur->mbms_service_area = current_ie;
		} else if (current_ie->type == IE_TMGI &&
			current_ie->instance == 0) {
			msur->temporary_mobile_group_identity = current_ie;
		} else if (current_ie->type == IE_FULLY_QUALIFIED_TUNNEL_ENDPOINT_IDENTIFIER &&
			current_ie->instance == 0) {
			msur->sender_f_teid_for_control_plane = current_ie;
		} else if (current_ie->type == IE_MBMS_SESSION_DURATION &&
			current_ie->instance == 0) {
			msur->mbms_session_duration = current_ie;
		} else if (current_ie->type == IE_BEARER_QUALITY_OF_SERVICE &&
			current_ie->instance == 0) {
			msur->qos_profile = current_ie;
		} else if (current_ie->type == IE_MBMS_SESSION_IDENTIFIER &&
			current_ie->instance == 0) {
			msur->mbms_session_identifier = current_ie;
		} else if (current_ie->type == IE_MBMS_FLOW_IDENTIFIER &&
			current_ie->instance == 0) {
			msur->mbms_flow_identifier = current_ie;
		} else if (current_ie->type == IE_MBMS_TIME_TO_DATA_TRANSFER &&
			current_ie->instance == 0) {
			msur->mbms_time_to_data_transfer = current_ie;
		} else if (current_ie->type == IE_ABSOLUTE_TIME_OF_MBMS_DATA_TRANSFER &&
			current_ie->instance == 0) {
			msur->mbms_data_transfer_start_update_stop = current_ie;
		} else if (current_ie->type == IE_ECGI_LIST &&
			current_ie->instance == 0) {
			msur->mbms_cell_list = current_ie;
		} else if (current_ie->type == IE_PRIVATE_EXTENSION) {
			msur->private_extension = current_ie;
		}

    }
    
	if (!msur->temporary_mobile_group_identity
		|| !msur->mbms_session_duration
		|| !msur->qos_profile) {
		fprintf(stderr, "Dropping packet\n");
		return -EPERM;
	}

    return 0;
}

// TODO
static void
set_mbms_session_update_request() {
    /* TODO */
}

int
process_mbms_session_update_request(gtpv2c_header *gtpv2c_rx,
                               gtpv2c_header *gtpv2c_tx)
{
    /* TODO */
}
