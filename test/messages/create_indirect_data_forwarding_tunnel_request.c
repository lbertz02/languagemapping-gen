@copyright

#include <errno.h>

#include "packet_filters.h"
#include "gtpv2c_set_ie.h"
#include "../cp_dp_api/vepc_cp_dp_api.h"

/** Information Elements in create_indirect_data_forwarding_tunnel_request */
struct parse_create_indirect_data_forwarding_tunnel_request_t {
	gtpv2c_ie *imsi;
	gtpv2c_ie *me_identity;
	gtpv2c_ie *indication_flags;
	gtpv2c_ie *sender_fully_qualified_tunnel_endpoint_identifier_for_control_plane;
	gtpv2c_ie *bearer_context;
	gtpv2c_ie *recovery;
	gtpv2c_ie *private_extension;
};

static int
parse_create_indirect_data_forwarding_tunnel_request(gtpv2c_header *gtpv2c_rx,
          struct parse_create_indirect_data_forwarding_tunnel_request_t *cidftr)
{
    gtpv2c_ie *current_ie;
    gtpv2c_ie *current_group_ie;
    gtpv2c_ie *limit_ie;
    gtpv2c_ie *limit_group_ie;
    
    FOR_EACH_GTPV2C_IE(gtpv2c_rx, current_ie, limit_ie)
    {
		if (current_ie->type == IE_IMSI &&
			current_ie->instance == 0) {
			cidftr->imsi = current_ie;
		} else if (current_ie->type == IE_MOBILE_EQUIPMENT_IDENTITY &&
			current_ie->instance == 0) {
			cidftr->me_identity = current_ie;
		} else if (current_ie->type == IE_INDICATION &&
			current_ie->instance == 0) {
			cidftr->indication_flags = current_ie;
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
    
	if (!cidftr->bearer_context) {
		fprintf(stderr, "Dropping packet\n");
		return -EPERM;
	}

    return 0;
}

// TODO
static void
set_create_indirect_data_forwarding_tunnel_request() {
    /* TODO */
}

int
process_create_indirect_data_forwarding_tunnel_request(gtpv2c_header *gtpv2c_rx,
                               gtpv2c_header *gtpv2c_tx)
{
    /* TODO */
}
