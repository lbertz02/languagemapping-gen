@copyright

#include <errno.h>

#include "packet_filters.h"
#include "gtpv2c_set_ie.h"
#include "../cp_dp_api/vepc_cp_dp_api.h"

/** Information Elements in ran_information_relay */
struct parse_ran_information_relay_t {
	gtpv2c_ie *bss_container;
	gtpv2c_ie *rim_routing_address;
	gtpv2c_ie *private_extension;
};

static int
parse_ran_information_relay(gtpv2c_header *gtpv2c_rx,
          struct parse_ran_information_relay_t *rir)
{
    gtpv2c_ie *current_ie;
    gtpv2c_ie *current_group_ie;
    gtpv2c_ie *limit_ie;
    gtpv2c_ie *limit_group_ie;
    
    FOR_EACH_GTPV2C_IE(gtpv2c_rx, current_ie, limit_ie)
    {
		if (current_ie->type == IE_FULLY_QUALIFIED_CONTAINER &&
			current_ie->instance == 0) {
			rir->bss_container = current_ie;
		} else if (current_ie->type == IE_TARGET_IDENTIFICATION &&
			current_ie->instance == 0) {
			rir->rim_routing_address = current_ie;
		} else if (current_ie->type == IE_PRIVATE_EXTENSION) {
			rir->private_extension = current_ie;
		}

    }
    
	if (!rir->bss_container) {
		fprintf(stderr, "Dropping packet\n");
		return -EPERM;
	}

    return 0;
}

// TODO
static void
set_ran_information_relay() {
    /* TODO */
}

int
process_ran_information_relay(gtpv2c_header *gtpv2c_rx,
                               gtpv2c_header *gtpv2c_tx)
{
    /* TODO */
}
