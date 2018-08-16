@copyright

#include <errno.h>

#include "packet_filters.h"
#include "gtpv2c_set_ie.h"
#include "../cp_dp_api/vepc_cp_dp_api.h"

/** Information Elements in echo_request */
struct parse_echo_request_t {
	gtpv2c_ie *recovery;
	gtpv2c_ie *sending_node_features;
	gtpv2c_ie *private_extension;
};

static int
parse_echo_request(gtpv2c_header *gtpv2c_rx,
          struct parse_echo_request_t *er)
{
    gtpv2c_ie *current_ie;
    gtpv2c_ie *current_group_ie;
    gtpv2c_ie *limit_ie;
    gtpv2c_ie *limit_group_ie;
    
    FOR_EACH_GTPV2C_IE(gtpv2c_rx, current_ie, limit_ie)
    {
		if (current_ie->type == IE_RECOVERY_RESTART_COUNTER &&
			current_ie->instance == 0) {
			er->recovery = current_ie;
		} else if (current_ie->type == IE_NODE_FEATURES &&
			current_ie->instance == 0) {
			er->sending_node_features = current_ie;
		} else if (current_ie->type == IE_PRIVATE_EXTENSION) {
			er->private_extension = current_ie;
		}

    }
    
	if (!er->recovery) {
		fprintf(stderr, "Dropping packet\n");
		return -EPERM;
	}

    return 0;
}

// TODO
static void
set_echo_request() {
    /* TODO */
}

int
process_echo_request(gtpv2c_header *gtpv2c_rx,
                               gtpv2c_header *gtpv2c_tx)
{
    /* TODO */
}
