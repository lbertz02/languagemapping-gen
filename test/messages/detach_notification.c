@copyright

#include <errno.h>

#include "packet_filters.h"
#include "gtpv2c_set_ie.h"
#include "../cp_dp_api/vepc_cp_dp_api.h"

/** Information Elements in detach_notification */
struct parse_detach_notification_t {
	gtpv2c_ie *cause;
	gtpv2c_ie *detach_type;
	gtpv2c_ie *private_extension;
};

static int
parse_detach_notification(gtpv2c_header *gtpv2c_rx,
          struct parse_detach_notification_t *dn)
{
    gtpv2c_ie *current_ie;
    gtpv2c_ie *current_group_ie;
    gtpv2c_ie *limit_ie;
    gtpv2c_ie *limit_group_ie;
    
    FOR_EACH_GTPV2C_IE(gtpv2c_rx, current_ie, limit_ie)
    {
		if (current_ie->type == IE_CAUSE &&
			current_ie->instance == 0) {
			dn->cause = current_ie;
		} else if (current_ie->type == IE_DETACH_TYPE &&
			current_ie->instance == 0) {
			dn->detach_type = current_ie;
		} else if (current_ie->type == IE_PRIVATE_EXTENSION) {
			dn->private_extension = current_ie;
		}

    }
    
	if (!dn->cause) {
		fprintf(stderr, "Dropping packet\n");
		return -EPERM;
	}

    return 0;
}

// TODO
static void
set_detach_notification() {
    /* TODO */
}

int
process_detach_notification(gtpv2c_header *gtpv2c_rx,
                               gtpv2c_header *gtpv2c_tx)
{
    /* TODO */
}
