@copyright

#include <errno.h>

#include "packet_filters.h"
#include "gtpv2c_set_ie.h"
#include "../cp_dp_api/vepc_cp_dp_api.h"

/** Information Elements in create_forwarding_tunnel_request */
struct parse_create_forwarding_tunnel_request_t {
	gtpv2c_ie *s103_pdn_data_forwarding_info;
	gtpv2c_ie *private_extension;
};

static int
parse_create_forwarding_tunnel_request(gtpv2c_header *gtpv2c_rx,
          struct parse_create_forwarding_tunnel_request_t *cftr)
{
    gtpv2c_ie *current_ie;
    gtpv2c_ie *current_group_ie;
    gtpv2c_ie *limit_ie;
    gtpv2c_ie *limit_group_ie;
    
    FOR_EACH_GTPV2C_IE(gtpv2c_rx, current_ie, limit_ie)
    {
		if (current_ie->type == IE_S103_PDN_DATA_FORWARDING_INFO &&
			current_ie->instance == 0) {
			cftr->s103_pdn_data_forwarding_info = current_ie;
		} else if (current_ie->type == IE_PRIVATE_EXTENSION) {
			cftr->private_extension = current_ie;
		}

    }
    
	if (!cftr->s103_pdn_data_forwarding_info) {
		fprintf(stderr, "Dropping packet\n");
		return -EPERM;
	}

    return 0;
}

// TODO
static void
set_create_forwarding_tunnel_request() {
    /* TODO */
}

int
process_create_forwarding_tunnel_request(gtpv2c_header *gtpv2c_rx,
                               gtpv2c_header *gtpv2c_tx)
{
    /* TODO */
}
