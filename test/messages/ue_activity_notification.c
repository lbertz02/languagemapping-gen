@copyright

#include <errno.h>

#include "packet_filters.h"
#include "gtpv2c_set_ie.h"
#include "../cp_dp_api/vepc_cp_dp_api.h"

/** Information Elements in ue_activity_notification */
struct parse_ue_activity_notification_t {
	gtpv2c_ie *private_extension;
};

static int
parse_ue_activity_notification(gtpv2c_header *gtpv2c_rx,
          struct parse_ue_activity_notification_t *uan)
{
    gtpv2c_ie *current_ie;
    gtpv2c_ie *current_group_ie;
    gtpv2c_ie *limit_ie;
    gtpv2c_ie *limit_group_ie;
    
    FOR_EACH_GTPV2C_IE(gtpv2c_rx, current_ie, limit_ie)
    {
		if (current_ie->type == IE_PRIVATE_EXTENSION) {
			uan->private_extension = current_ie;
		}

    }
    

    return 0;
}

// TODO
static void
set_ue_activity_notification() {
    /* TODO */
}

int
process_ue_activity_notification(gtpv2c_header *gtpv2c_rx,
                               gtpv2c_header *gtpv2c_tx)
{
    /* TODO */
}
