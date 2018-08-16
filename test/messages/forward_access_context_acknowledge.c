@copyright

#include <errno.h>

#include "packet_filters.h"
#include "gtpv2c_set_ie.h"
#include "../cp_dp_api/vepc_cp_dp_api.h"

/** Information Elements in forward_access_context_acknowledge */
struct parse_forward_access_context_acknowledge_t {
	gtpv2c_ie *cause;
	gtpv2c_ie *private_extension;
};

static int
parse_forward_access_context_acknowledge(gtpv2c_header *gtpv2c_rx,
          struct parse_forward_access_context_acknowledge_t *faca)
{
    gtpv2c_ie *current_ie;
    gtpv2c_ie *current_group_ie;
    gtpv2c_ie *limit_ie;
    gtpv2c_ie *limit_group_ie;
    
    FOR_EACH_GTPV2C_IE(gtpv2c_rx, current_ie, limit_ie)
    {
		if (current_ie->type == IE_CAUSE &&
			current_ie->instance == 0) {
			faca->cause = current_ie;
		} else if (current_ie->type == IE_PRIVATE_EXTENSION) {
			faca->private_extension = current_ie;
		}

    }
    
	if (!faca->cause) {
		fprintf(stderr, "Dropping packet\n");
		return -EPERM;
	}

    return 0;
}

// TODO
static void
set_forward_access_context_acknowledge() {
    /* TODO */
}

int
process_forward_access_context_acknowledge(gtpv2c_header *gtpv2c_rx,
                               gtpv2c_header *gtpv2c_tx)
{
    /* TODO */
}
