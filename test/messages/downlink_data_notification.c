@copyright

#include <errno.h>

#include "packet_filters.h"
#include "gtpv2c_set_ie.h"
#include "../cp_dp_api/vepc_cp_dp_api.h"

/** Information Elements in downlink_data_notification */
struct parse_downlink_data_notification_t {
	gtpv2c_ie *cause;
	gtpv2c_ie *eps_bearer_id;
	gtpv2c_ie *allocation_retention_priority;
	gtpv2c_ie *imsi;
	gtpv2c_ie *sender_f_teid_for_control_plane;
	gtpv2c_ie *indication_flags;
	gtpv2c_ie *sgw_node_level_load_control_information;
	gtpv2c_ie *sgw_overload_control_information;
	gtpv2c_ie *paging_and_service_information;
	gtpv2c_ie *private_extension;
};

static int
parse_downlink_data_notification(gtpv2c_header *gtpv2c_rx,
          struct parse_downlink_data_notification_t *ddn)
{
    gtpv2c_ie *current_ie;
    gtpv2c_ie *current_group_ie;
    gtpv2c_ie *limit_ie;
    gtpv2c_ie *limit_group_ie;
    
    FOR_EACH_GTPV2C_IE(gtpv2c_rx, current_ie, limit_ie)
    {
		if (current_ie->type == IE_CAUSE &&
			current_ie->instance == 0) {
			ddn->cause = current_ie;
		} else if (current_ie->type == IE_EPS_BEARER_ID &&
			current_ie->instance == 0) {
			ddn->eps_bearer_id = current_ie;
		} else if (current_ie->type == IE_ALLOCATION_RETENTION_PRIORITY &&
			current_ie->instance == 0) {
			ddn->allocation_retention_priority = current_ie;
		} else if (current_ie->type == IE_IMSI &&
			current_ie->instance == 0) {
			ddn->imsi = current_ie;
		} else if (current_ie->type == IE_FULLY_QUALIFIED_TUNNEL_ENDPOINT_IDENTIFIER &&
			current_ie->instance == 0) {
			ddn->sender_f_teid_for_control_plane = current_ie;
		} else if (current_ie->type == IE_INDICATION &&
			current_ie->instance == 0) {
			ddn->indication_flags = current_ie;
		} else if (current_ie->type == IE_LOAD_CONTROL_INFORMATION &&
			current_ie->instance == 0) {
			ddn->sgw_node_level_load_control_information = current_ie;
		} else if (current_ie->type == IE_OVERLOAD_CONTROL_INFORMATION &&
			current_ie->instance == 0) {
			ddn->sgw_overload_control_information = current_ie;
		} else if (current_ie->type == IE_PAGING_AND_SERVICE_INFORMATION &&
			current_ie->instance == 0) {
			ddn->paging_and_service_information = current_ie;
		} else if (current_ie->type == IE_PRIVATE_EXTENSION) {
			ddn->private_extension = current_ie;
		}

    }
    

    return 0;
}

// TODO
static void
set_downlink_data_notification() {
    /* TODO */
}

int
process_downlink_data_notification(gtpv2c_header *gtpv2c_rx,
                               gtpv2c_header *gtpv2c_tx)
{
    /* TODO */
}
