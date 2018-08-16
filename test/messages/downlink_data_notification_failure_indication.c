@copyright

#include <errno.h>

#include "packet_filters.h"
#include "gtpv2c_set_ie.h"
#include "../cp_dp_api/vepc_cp_dp_api.h"

/** Information Elements in downlink_data_notification_failure_indication */
struct parse_downlink_data_notification_failure_indication_t {
	gtpv2c_ie *cause;
	gtpv2c_ie *originating_node;
	gtpv2c_ie *imsi;
	gtpv2c_ie *private_extension;
};

static int
parse_downlink_data_notification_failure_indication(gtpv2c_header *gtpv2c_rx,
          struct parse_downlink_data_notification_failure_indication_t *ddnfi)
{
    gtpv2c_ie *current_ie;
    gtpv2c_ie *current_group_ie;
    gtpv2c_ie *limit_ie;
    gtpv2c_ie *limit_group_ie;
    
    FOR_EACH_GTPV2C_IE(gtpv2c_rx, current_ie, limit_ie)
    {
		if (current_ie->type == IE_CAUSE &&
			current_ie->instance == 0) {
			ddnfi->cause = current_ie;
		} else if (current_ie->type == IE_NODE_TYPE &&
			current_ie->instance == 0) {
			ddnfi->originating_node = current_ie;
		} else if (current_ie->type == IE_IMSI &&
			current_ie->instance == 0) {
			ddnfi->imsi = current_ie;
		} else if (current_ie->type == IE_PRIVATE_EXTENSION) {
			ddnfi->private_extension = current_ie;
		}

    }
    
	if (!ddnfi->cause) {
		fprintf(stderr, "Dropping packet\n");
		return -EPERM;
	}

    return 0;
}

// TODO
static void
set_downlink_data_notification_failure_indication() {
    /* TODO */
}

int
process_downlink_data_notification_failure_indication(gtpv2c_header *gtpv2c_rx,
                               gtpv2c_header *gtpv2c_tx)
{
    /* TODO */
}
