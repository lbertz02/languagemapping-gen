@copyright

#include <errno.h>

#include "packet_filters.h"
#include "gtpv2c_set_ie.h"
#include "../cp_dp_api/vepc_cp_dp_api.h"

/** Information Elements in modify_bearer_command */
struct parse_modify_bearer_command_t {
	gtpv2c_ie *apn_aggregate_maximum_bit_rate;
	gtpv2c_ie *bearer_context;
	gtpv2c_ie *mmes4_sgsn_overload_control_information;
	gtpv2c_ie *sgw_overload_control_information;
	gtpv2c_ie *twanepdg_overload_control_information;
	gtpv2c_ie *sender_f_teid_for_control_plane;
	gtpv2c_ie *private_extension;
};

static int
parse_modify_bearer_command(gtpv2c_header *gtpv2c_rx,
          struct parse_modify_bearer_command_t *mbc)
{
    gtpv2c_ie *current_ie;
    gtpv2c_ie *current_group_ie;
    gtpv2c_ie *limit_ie;
    gtpv2c_ie *limit_group_ie;
    
    FOR_EACH_GTPV2C_IE(gtpv2c_rx, current_ie, limit_ie)
    {
		if (current_ie->type == IE_AGGREGATE_MAXIMUM_BIT_RATE &&
			current_ie->instance == 0) {
			mbc->apn_aggregate_maximum_bit_rate = current_ie;
		} else if (current_ie->type == IE_BEARER_CONTEXT &&
			current_ie->instance == 0) {
			mbc->bearer_context = current_ie;
		} else if (current_ie->type == IE_OVERLOAD_CONTROL_INFORMATION &&
			current_ie->instance == 0) {
			mbc->mmes4_sgsn_overload_control_information = current_ie;
		} else if (current_ie->type == IE_OVERLOAD_CONTROL_INFORMATION &&
			current_ie->instance == 1) {
			mbc->sgw_overload_control_information = current_ie;
		} else if (current_ie->type == IE_OVERLOAD_CONTROL_INFORMATION &&
			current_ie->instance == 2) {
			mbc->twanepdg_overload_control_information = current_ie;
		} else if (current_ie->type == IE_FULLY_QUALIFIED_TUNNEL_ENDPOINT_IDENTIFIER &&
			current_ie->instance == 0) {
			mbc->sender_f_teid_for_control_plane = current_ie;
		} else if (current_ie->type == IE_PRIVATE_EXTENSION) {
			mbc->private_extension = current_ie;
		}

    }
    
	if (!mbc->apn_aggregate_maximum_bit_rate
		|| !mbc->bearer_context) {
		fprintf(stderr, "Dropping packet\n");
		return -EPERM;
	}

    return 0;
}

// TODO
static void
set_modify_bearer_command() {
    /* TODO */
}

int
process_modify_bearer_command(gtpv2c_header *gtpv2c_rx,
                               gtpv2c_header *gtpv2c_tx)
{
    /* TODO */
}
