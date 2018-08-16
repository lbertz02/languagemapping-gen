@copyright

#include <errno.h>

#include "packet_filters.h"
#include "gtpv2c_set_ie.h"
#include "../cp_dp_api/vepc_cp_dp_api.h"

/** Information Elements in pgw_restart_notification_acknowledge */
struct parse_pgw_restart_notification_acknowledge_t {
	gtpv2c_ie *cause;
	gtpv2c_ie *private_extension;
};

static int
parse_pgw_restart_notification_acknowledge(gtpv2c_header *gtpv2c_rx,
          struct parse_pgw_restart_notification_acknowledge_t *prna)
{
    gtpv2c_ie *current_ie;
    gtpv2c_ie *current_group_ie;
    gtpv2c_ie *limit_ie;
    gtpv2c_ie *limit_group_ie;
    
    FOR_EACH_GTPV2C_IE(gtpv2c_rx, current_ie, limit_ie)
    {
		if (current_ie->type == IE_CAUSE &&
			current_ie->instance == 0) {
			prna->cause = current_ie;
		} else if (current_ie->type == IE_PRIVATE_EXTENSION) {
			prna->private_extension = current_ie;
		}

    }
    
	if (!prna->cause) {
		fprintf(stderr, "Dropping packet\n");
		return -EPERM;
	}

    return 0;
}

// TODO
static void
set_pgw_restart_notification_acknowledge() {
    /* TODO */
}

int
process_pgw_restart_notification_acknowledge(gtpv2c_header *gtpv2c_rx,
                               gtpv2c_header *gtpv2c_tx)
{
    /* TODO */
}
