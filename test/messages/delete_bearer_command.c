@copyright

#include <errno.h>

#include "packet_filters.h"
#include "gtpv2c_set_ie.h"
#include "../cp_dp_api/vepc_cp_dp_api.h"

/** Information Elements in delete_bearer_command */
struct parse_delete_bearer_command_t {
	gtpv2c_ie *bearer_context;
	gtpv2c_ie *user_location_information;
	gtpv2c_ie *uli_timestamp;
	gtpv2c_ie *ue_time_zone;
	gtpv2c_ie *mmes4_sgs_overload_control_information;
	gtpv2c_ie *sgw_overload_control_information;
	gtpv2c_ie *sender_f_teid_for_control_plane;
	gtpv2c_ie *secondary_rat_usage_data_report;
	gtpv2c_ie *private_extension;
};

static int
parse_delete_bearer_command(gtpv2c_header *gtpv2c_rx,
          struct parse_delete_bearer_command_t *dbc)
{
    gtpv2c_ie *current_ie;
    gtpv2c_ie *current_group_ie;
    gtpv2c_ie *limit_ie;
    gtpv2c_ie *limit_group_ie;
    
    FOR_EACH_GTPV2C_IE(gtpv2c_rx, current_ie, limit_ie)
    {
		if (current_ie->type == IE_BEARER_CONTEXT &&
			current_ie->instance == 0) {
			dbc->bearer_context = current_ie;
		} else if (current_ie->type == IE_USER_LOCATION_INFORMATION &&
			current_ie->instance == 0) {
			dbc->user_location_information = current_ie;
		} else if (current_ie->type == IE_ULI_TIMESTAMP &&
			current_ie->instance == 0) {
			dbc->uli_timestamp = current_ie;
		} else if (current_ie->type == IE_UE_TIME_ZONE &&
			current_ie->instance == 0) {
			dbc->ue_time_zone = current_ie;
		} else if (current_ie->type == IE_OVERLOAD_CONTROL_INFORMATION &&
			current_ie->instance == 0) {
			dbc->mmes4_sgs_overload_control_information = current_ie;
		} else if (current_ie->type == IE_OVERLOAD_CONTROL_INFORMATION &&
			current_ie->instance == 1) {
			dbc->sgw_overload_control_information = current_ie;
		} else if (current_ie->type == IE_FULLY_QUALIFIED_TUNNEL_ENDPOINT_IDENTIFIER &&
			current_ie->instance == 0) {
			dbc->sender_f_teid_for_control_plane = current_ie;
		} else if (current_ie->type == IE_SECONDARY_RAT_USAGE_DATA_REPORT &&
			current_ie->instance == 0) {
			dbc->secondary_rat_usage_data_report = current_ie;
		} else if (current_ie->type == IE_PRIVATE_EXTENSION) {
			dbc->private_extension = current_ie;
		}

    }
    
	if (!dbc->bearer_context) {
		fprintf(stderr, "Dropping packet\n");
		return -EPERM;
	}

    return 0;
}

// TODO
static void
set_delete_bearer_command() {
    /* TODO */
}

int
process_delete_bearer_command(gtpv2c_header *gtpv2c_rx,
                               gtpv2c_header *gtpv2c_tx)
{
    /* TODO */
}
