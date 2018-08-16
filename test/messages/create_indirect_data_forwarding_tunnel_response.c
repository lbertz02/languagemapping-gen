@copyright

#include <errno.h>

#include "packet_filters.h"
#include "gtpv2c_set_ie.h"
#include "../cp_dp_api/vepc_cp_dp_api.h"

/** Information Elements in create_indirect_data_forwarding_tunnel_response */
struct parse_create_indirect_data_forwarding_tunnel_response_t {
	gtpv2c_ie *cause;
	gtpv2c_ie *sender_fully_qualified_tunnel_endpoint_identifier_for_control_plane;
	gtpv2c_ie *bearer_context;
	gtpv2c_ie *recovery;
	gtpv2c_ie *private_extension;
};

static int
parse_create_indirect_data_forwarding_tunnel_response(gtpv2c_header *gtpv2c_rx,
          struct parse_create_indirect_data_forwarding_tunnel_response_t *cidftr)
{
    gtpv2c_ie *current_ie;
    gtpv2c_ie *current_group_ie;
    gtpv2c_ie *limit_ie;
    gtpv2c_ie *limit_group_ie;
    
    FOR_EACH_GTPV2C_IE(gtpv2c_rx, current_ie, limit_ie)
    {
		if (current_ie->type == IE_CAUSE &&
			current_ie->instance == 0) {
			cidftr->cause = current_ie;
		} else if (current_ie->type == IE_FULLY_QUALIFIED_TUNNEL_ENDPOINT_IDENTIFIER &&
			current_ie->instance == 0) {
			cidftr->sender_fully_qualified_tunnel_endpoint_identifier_for_control_plane = current_ie;
		} else if (current_ie->type == IE_BEARER_CONTEXT &&
			current_ie->instance == 0) {
			cidftr->bearer_context = current_ie;
		} else if (current_ie->type == IE_RECOVERY_RESTART_COUNTER &&
			current_ie->instance == 0) {
			cidftr->recovery = current_ie;
		} else if (current_ie->type == IE_PRIVATE_EXTENSION) {
			cidftr->private_extension = current_ie;
		}

    }
    
	if (!cidftr->cause
		|| !cidftr->bearer_context) {
		fprintf(stderr, "Dropping packet\n");
		return -EPERM;
	}

    return 0;
}

// TODO
static void
set_create_indirect_data_forwarding_tunnel_response() {
    /* TODO */
}

int
process_create_indirect_data_forwarding_tunnel_response(gtpv2c_header *gtpv2c_rx,
                               gtpv2c_header *gtpv2c_tx)
{
    /* TODO */
}
