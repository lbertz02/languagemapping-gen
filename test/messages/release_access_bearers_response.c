@copyright

#include <errno.h>

#include "packet_filters.h"
#include "gtpv2c_set_ie.h"
#include "../cp_dp_api/vepc_cp_dp_api.h"

/** Information Elements in release_access_bearers_response */
struct parse_release_access_bearers_response_t {
	gtpv2c_ie *cause;
	gtpv2c_ie *recovery;
	gtpv2c_ie *indication_flags;
	gtpv2c_ie *sgw_node_level_load_control_information;
	gtpv2c_ie *sgw_overload_control_information;
	gtpv2c_ie *private_extension;
};

static int
parse_release_access_bearers_response(gtpv2c_header *gtpv2c_rx,
          struct parse_release_access_bearers_response_t *rabr)
{
    gtpv2c_ie *current_ie;
    gtpv2c_ie *current_group_ie;
    gtpv2c_ie *limit_ie;
    gtpv2c_ie *limit_group_ie;
    
    FOR_EACH_GTPV2C_IE(gtpv2c_rx, current_ie, limit_ie)
    {
		if (current_ie->type == IE_CAUSE &&
			current_ie->instance == 0) {
			rabr->cause = current_ie;
		} else if (current_ie->type == IE_RECOVERY_RESTART_COUNTER &&
			current_ie->instance == 0) {
			rabr->recovery = current_ie;
		} else if (current_ie->type == IE_INDICATION &&
			current_ie->instance == 0) {
			rabr->indication_flags = current_ie;
		} else if (current_ie->type == IE_LOAD_CONTROL_INFORMATION &&
			current_ie->instance == 0) {
			rabr->sgw_node_level_load_control_information = current_ie;
		} else if (current_ie->type == IE_OVERLOAD_CONTROL_INFORMATION &&
			current_ie->instance == 0) {
			rabr->sgw_overload_control_information = current_ie;
		} else if (current_ie->type == IE_PRIVATE_EXTENSION) {
			rabr->private_extension = current_ie;
		}

    }
    
	if (!rabr->cause) {
		fprintf(stderr, "Dropping packet\n");
		return -EPERM;
	}

    return 0;
}

// TODO
static void
set_release_access_bearers_response() {
    /* TODO */
}

int
process_release_access_bearers_response(gtpv2c_header *gtpv2c_rx,
                               gtpv2c_header *gtpv2c_tx)
{
    /* TODO */
}
