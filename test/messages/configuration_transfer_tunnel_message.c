@copyright

#include <errno.h>

#include "packet_filters.h"
#include "gtpv2c_set_ie.h"
#include "../cp_dp_api/vepc_cp_dp_api.h"

/** Information Elements in configuration_transfer_tunnel_message */
struct parse_configuration_transfer_tunnel_message_t {
	gtpv2c_ie *e_utran_transparent_container;
	gtpv2c_ie *target_enodeb_id;
};

static int
parse_configuration_transfer_tunnel_message(gtpv2c_header *gtpv2c_rx,
          struct parse_configuration_transfer_tunnel_message_t *cttm)
{
    gtpv2c_ie *current_ie;
    gtpv2c_ie *current_group_ie;
    gtpv2c_ie *limit_ie;
    gtpv2c_ie *limit_group_ie;
    
    FOR_EACH_GTPV2C_IE(gtpv2c_rx, current_ie, limit_ie)
    {
		if (current_ie->type == IE_FULLY_QUALIFIED_CONTAINER &&
			current_ie->instance == 0) {
			cttm->e_utran_transparent_container = current_ie;
		} else if (current_ie->type == IE_TARGET_IDENTIFICATION &&
			current_ie->instance == 0) {
			cttm->target_enodeb_id = current_ie;
		}

    }
    
	if (!cttm->e_utran_transparent_container
		|| !cttm->target_enodeb_id) {
		fprintf(stderr, "Dropping packet\n");
		return -EPERM;
	}

    return 0;
}

// TODO
static void
set_configuration_transfer_tunnel_message() {
    /* TODO */
}

int
process_configuration_transfer_tunnel_message(gtpv2c_header *gtpv2c_rx,
                               gtpv2c_header *gtpv2c_tx)
{
    /* TODO */
}
