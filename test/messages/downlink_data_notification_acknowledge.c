@copyright

#include <errno.h>

#include "packet_filters.h"
#include "gtpv2c_set_ie.h"
#include "../cp_dp_api/vepc_cp_dp_api.h"

/** Information Elements in downlink_data_notification_acknowledge */
struct parse_downlink_data_notification_acknowledge_t {
	gtpv2c_ie *cause;
	gtpv2c_ie *data_notification_delay;
	gtpv2c_ie *recovery;
	gtpv2c_ie *dl_low_priority_traffic_throttling;
	gtpv2c_ie *imsi;
	gtpv2c_ie *dl_buffering_duration;
	gtpv2c_ie *dl_buffering_suggested_packet_count;
	gtpv2c_ie *private_extension;
};

static int
parse_downlink_data_notification_acknowledge(gtpv2c_header *gtpv2c_rx,
          struct parse_downlink_data_notification_acknowledge_t *ddna)
{
    gtpv2c_ie *current_ie;
    gtpv2c_ie *current_group_ie;
    gtpv2c_ie *limit_ie;
    gtpv2c_ie *limit_group_ie;
    
    FOR_EACH_GTPV2C_IE(gtpv2c_rx, current_ie, limit_ie)
    {
		if (current_ie->type == IE_CAUSE &&
			current_ie->instance == 0) {
			ddna->cause = current_ie;
		} else if (current_ie->type == IE_DELAY_VALUE &&
			current_ie->instance == 0) {
			ddna->data_notification_delay = current_ie;
		} else if (current_ie->type == IE_RECOVERY_RESTART_COUNTER &&
			current_ie->instance == 0) {
			ddna->recovery = current_ie;
		} else if (current_ie->type == IE_THROTTLING &&
			current_ie->instance == 0) {
			ddna->dl_low_priority_traffic_throttling = current_ie;
		} else if (current_ie->type == IE_IMSI &&
			current_ie->instance == 0) {
			ddna->imsi = current_ie;
		} else if (current_ie->type == IE_EPC_TIMER &&
			current_ie->instance == 0) {
			ddna->dl_buffering_duration = current_ie;
		} else if (current_ie->type == IE_INTEGER_NUMBER &&
			current_ie->instance == 0) {
			ddna->dl_buffering_suggested_packet_count = current_ie;
		} else if (current_ie->type == IE_PRIVATE_EXTENSION) {
			ddna->private_extension = current_ie;
		}

    }
    
	if (!ddna->cause) {
		fprintf(stderr, "Dropping packet\n");
		return -EPERM;
	}

    return 0;
}

// TODO
static void
set_downlink_data_notification_acknowledge() {
    /* TODO */
}

int
process_downlink_data_notification_acknowledge(gtpv2c_header *gtpv2c_rx,
                               gtpv2c_header *gtpv2c_tx)
{
    /* TODO */
}
