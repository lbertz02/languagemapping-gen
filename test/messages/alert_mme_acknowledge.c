@copyright

#include <errno.h>

#include "packet_filters.h"
#include "gtpv2c_set_ie.h"
#include "../cp_dp_api/vepc_cp_dp_api.h"

/** Information Elements in alert_mme_acknowledge */
struct parse_alert_mme_acknowledge_t {
	gtpv2c_ie *cause;
	gtpv2c_ie *private_extension;
};

static int
parse_alert_mme_acknowledge(gtpv2c_header *gtpv2c_rx,
          struct parse_alert_mme_acknowledge_t *ama)
{
    gtpv2c_ie *current_ie;
    gtpv2c_ie *current_group_ie;
    gtpv2c_ie *limit_ie;
    gtpv2c_ie *limit_group_ie;
    
    FOR_EACH_GTPV2C_IE(gtpv2c_rx, current_ie, limit_ie)
    {
		if (current_ie->type == IE_CAUSE &&
			current_ie->instance == 0) {
			ama->cause = current_ie;
		} else if (current_ie->type == IE_PRIVATE_EXTENSION) {
			ama->private_extension = current_ie;
		}

    }
    
	if (!ama->cause) {
		fprintf(stderr, "Dropping packet\n");
		return -EPERM;
	}

    return 0;
}

// TODO
static void
set_alert_mme_acknowledge() {
    /* TODO */
}

int
process_alert_mme_acknowledge(gtpv2c_header *gtpv2c_rx,
                               gtpv2c_header *gtpv2c_tx)
{
    /* TODO */
}
