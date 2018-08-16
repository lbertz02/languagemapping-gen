@copyright

#include <errno.h>

#include "packet_filters.h"
#include "gtpv2c_set_ie.h"
#include "../cp_dp_api/vepc_cp_dp_api.h"

/** Information Elements in remote_ue_report_notification */
struct parse_remote_ue_report_notification_t {
	gtpv2c_ie *remote_ue_context__connected;
	gtpv2c_ie *remote_ue_context_disconnected;
	gtpv2c_ie *private_extension;
};

static int
parse_remote_ue_report_notification(gtpv2c_header *gtpv2c_rx,
          struct parse_remote_ue_report_notification_t *rurn)
{
    gtpv2c_ie *current_ie;
    gtpv2c_ie *current_group_ie;
    gtpv2c_ie *limit_ie;
    gtpv2c_ie *limit_group_ie;
    
    FOR_EACH_GTPV2C_IE(gtpv2c_rx, current_ie, limit_ie)
    {
		if (current_ie->type == IE_REMOTE_UE_CONTEXT &&
			current_ie->instance == 0) {
			rurn->remote_ue_context__connected = current_ie;
		} else if (current_ie->type == IE_REMOTE_UE_CONTEXT &&
			current_ie->instance == 1) {
			rurn->remote_ue_context_disconnected = current_ie;
		} else if (current_ie->type == IE_PRIVATE_EXTENSION) {
			rurn->private_extension = current_ie;
		}

    }
    

    return 0;
}

// TODO
static void
set_remote_ue_report_notification() {
    /* TODO */
}

int
process_remote_ue_report_notification(gtpv2c_header *gtpv2c_rx,
                               gtpv2c_header *gtpv2c_tx)
{
    /* TODO */
}
