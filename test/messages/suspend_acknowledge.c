@copyright

#include <errno.h>

#include "packet_filters.h"
#include "gtpv2c_set_ie.h"
#include "../cp_dp_api/vepc_cp_dp_api.h"

/** Information Elements in suspend_acknowledge */
struct parse_suspend_acknowledge_t {
	gtpv2c_ie *cause;
	gtpv2c_ie *private_extension;
};

static int
parse_suspend_acknowledge(gtpv2c_header *gtpv2c_rx,
          struct parse_suspend_acknowledge_t *sa)
{
    gtpv2c_ie *current_ie;
    gtpv2c_ie *current_group_ie;
    gtpv2c_ie *limit_ie;
    gtpv2c_ie *limit_group_ie;
    
    FOR_EACH_GTPV2C_IE(gtpv2c_rx, current_ie, limit_ie)
    {
		if (current_ie->type == IE_CAUSE &&
			current_ie->instance == 0) {
			sa->cause = current_ie;
		} else if (current_ie->type == IE_PRIVATE_EXTENSION) {
			sa->private_extension = current_ie;
		}

    }
    
	if (!sa->cause) {
		fprintf(stderr, "Dropping packet\n");
		return -EPERM;
	}

    return 0;
}

// TODO
static void
set_suspend_acknowledge() {
    /* TODO */
}

int
process_suspend_acknowledge(gtpv2c_header *gtpv2c_rx,
                               gtpv2c_header *gtpv2c_tx)
{
    /* TODO */
}
