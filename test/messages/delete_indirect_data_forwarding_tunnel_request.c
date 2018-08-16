@copyright

#include <errno.h>

#include "packet_filters.h"
#include "gtpv2c_set_ie.h"
#include "../cp_dp_api/vepc_cp_dp_api.h"

/** Information Elements in delete_indirect_data_forwarding_tunnel_request */
struct parse_delete_indirect_data_forwarding_tunnel_request_t {
	gtpv2c_ie *private_extension;
};

static int
parse_delete_indirect_data_forwarding_tunnel_request(gtpv2c_header *gtpv2c_rx,
          struct parse_delete_indirect_data_forwarding_tunnel_request_t *didftr)
{
    gtpv2c_ie *current_ie;
    gtpv2c_ie *current_group_ie;
    gtpv2c_ie *limit_ie;
    gtpv2c_ie *limit_group_ie;
    
    FOR_EACH_GTPV2C_IE(gtpv2c_rx, current_ie, limit_ie)
    {
		if (current_ie->type == IE_PRIVATE_EXTENSION) {
			didftr->private_extension = current_ie;
		}

    }
    

    return 0;
}

// TODO
static void
set_delete_indirect_data_forwarding_tunnel_request() {
    /* TODO */
}

int
process_delete_indirect_data_forwarding_tunnel_request(gtpv2c_header *gtpv2c_rx,
                               gtpv2c_header *gtpv2c_tx)
{
    /* TODO */
}
