@copyright

#include <errno.h>

#include "packet_filters.h"
#include "gtpv2c_set_ie.h"
#include "../cp_dp_api/vepc_cp_dp_api.h"

/** Information Elements in isr_status_indication */
struct parse_isr_status_indication_t {
	gtpv2c_ie *action_indication;
	gtpv2c_ie *private_extension;
};

static int
parse_isr_status_indication(gtpv2c_header *gtpv2c_rx,
          struct parse_isr_status_indication_t *isi)
{
    gtpv2c_ie *current_ie;
    gtpv2c_ie *current_group_ie;
    gtpv2c_ie *limit_ie;
    gtpv2c_ie *limit_group_ie;
    
    FOR_EACH_GTPV2C_IE(gtpv2c_rx, current_ie, limit_ie)
    {
		if (current_ie->type == IE_ACTION_INDICATION &&
			current_ie->instance == 0) {
			isi->action_indication = current_ie;
		} else if (current_ie->type == IE_PRIVATE_EXTENSION) {
			isi->private_extension = current_ie;
		}

    }
    
	if (!isi->action_indication) {
		fprintf(stderr, "Dropping packet\n");
		return -EPERM;
	}

    return 0;
}

// TODO
static void
set_isr_status_indication() {
    /* TODO */
}

int
process_isr_status_indication(gtpv2c_header *gtpv2c_rx,
                               gtpv2c_header *gtpv2c_tx)
{
    /* TODO */
}
