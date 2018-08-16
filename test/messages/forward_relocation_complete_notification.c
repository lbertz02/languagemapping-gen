@copyright

#include <errno.h>

#include "packet_filters.h"
#include "gtpv2c_set_ie.h"
#include "../cp_dp_api/vepc_cp_dp_api.h"

/** Information Elements in forward_relocation_complete_notification */
struct parse_forward_relocation_complete_notification_t {
	gtpv2c_ie *indication_flags;
	gtpv2c_ie *private_extension;
};

static int
parse_forward_relocation_complete_notification(gtpv2c_header *gtpv2c_rx,
          struct parse_forward_relocation_complete_notification_t *frcn)
{
    gtpv2c_ie *current_ie;
    gtpv2c_ie *current_group_ie;
    gtpv2c_ie *limit_ie;
    gtpv2c_ie *limit_group_ie;
    
    FOR_EACH_GTPV2C_IE(gtpv2c_rx, current_ie, limit_ie)
    {
		if (current_ie->type == IE_INDICATION &&
			current_ie->instance == 0) {
			frcn->indication_flags = current_ie;
		} else if (current_ie->type == IE_PRIVATE_EXTENSION) {
			frcn->private_extension = current_ie;
		}

    }
    

    return 0;
}

// TODO
static void
set_forward_relocation_complete_notification() {
    /* TODO */
}

int
process_forward_relocation_complete_notification(gtpv2c_header *gtpv2c_rx,
                               gtpv2c_header *gtpv2c_tx)
{
    /* TODO */
}
