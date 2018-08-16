@copyright

#include <errno.h>

#include "packet_filters.h"
#include "gtpv2c_set_ie.h"
#include "../cp_dp_api/vepc_cp_dp_api.h"

/** Information Elements in modify_access_bearers_request */
struct parse_modify_access_bearers_request_t {
	gtpv2c_ie *indication_flags;
	gtpv2c_ie *sender_fully_qualified_tunnel_endpoint_identifier_for_control_plane;
	gtpv2c_ie *delay_downlink_packet_notification_request;
	gtpv2c_ie *bearer_contexts_to_be_modified;
	gtpv2c_ie *bearer_contexts_to_be_removed;
	gtpv2c_ie *recovery;
	gtpv2c_ie *secondary_rat_usage_data_report;
	gtpv2c_ie *private_extension;
};

static int
parse_modify_access_bearers_request(gtpv2c_header *gtpv2c_rx,
          struct parse_modify_access_bearers_request_t *mabr)
{
    gtpv2c_ie *current_ie;
    gtpv2c_ie *current_group_ie;
    gtpv2c_ie *limit_ie;
    gtpv2c_ie *limit_group_ie;
    
    FOR_EACH_GTPV2C_IE(gtpv2c_rx, current_ie, limit_ie)
    {
		if (current_ie->type == IE_INDICATION &&
			current_ie->instance == 0) {
			mabr->indication_flags = current_ie;
		} else if (current_ie->type == IE_FULLY_QUALIFIED_TUNNEL_ENDPOINT_IDENTIFIER &&
			current_ie->instance == 0) {
			mabr->sender_fully_qualified_tunnel_endpoint_identifier_for_control_plane = current_ie;
		} else if (current_ie->type == IE_DELAY_VALUE &&
			current_ie->instance == 0) {
			mabr->delay_downlink_packet_notification_request = current_ie;
		} else if (current_ie->type == IE_BEARER_CONTEXT &&
			current_ie->instance == 0) {
			mabr->bearer_contexts_to_be_modified = current_ie;
		} else if (current_ie->type == IE_BEARER_CONTEXT &&
			current_ie->instance == 1) {
			mabr->bearer_contexts_to_be_removed = current_ie;
		} else if (current_ie->type == IE_RECOVERY_RESTART_COUNTER &&
			current_ie->instance == 0) {
			mabr->recovery = current_ie;
		} else if (current_ie->type == IE_SECONDARY_RAT_USAGE_DATA_REPORT &&
			current_ie->instance == 0) {
			mabr->secondary_rat_usage_data_report = current_ie;
		} else if (current_ie->type == IE_PRIVATE_EXTENSION) {
			mabr->private_extension = current_ie;
		}

    }
    

    return 0;
}

// TODO
static void
set_modify_access_bearers_request() {
    /* TODO */
}

int
process_modify_access_bearers_request(gtpv2c_header *gtpv2c_rx,
                               gtpv2c_header *gtpv2c_tx)
{
    /* TODO */
}
