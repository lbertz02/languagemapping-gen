@copyright

#include <errno.h>

#include "packet_filters.h"
#include "gtpv2c_set_ie.h"
#include "../cp_dp_api/vepc_cp_dp_api.h"

/** Information Elements in forward_relocation_complete_acknowledge */
struct parse_forward_relocation_complete_acknowledge_t {
	gtpv2c_ie *cause;
	gtpv2c_ie *recovery;
	gtpv2c_ie *secondary_rat_usage_data_report;
	gtpv2c_ie *private_extension;
};

static int
parse_forward_relocation_complete_acknowledge(gtpv2c_header *gtpv2c_rx,
          struct parse_forward_relocation_complete_acknowledge_t *frca)
{
    gtpv2c_ie *current_ie;
    gtpv2c_ie *current_group_ie;
    gtpv2c_ie *limit_ie;
    gtpv2c_ie *limit_group_ie;
    
    FOR_EACH_GTPV2C_IE(gtpv2c_rx, current_ie, limit_ie)
    {
		if (current_ie->type == IE_CAUSE &&
			current_ie->instance == 0) {
			frca->cause = current_ie;
		} else if (current_ie->type == IE_RECOVERY_RESTART_COUNTER &&
			current_ie->instance == 0) {
			frca->recovery = current_ie;
		} else if (current_ie->type == IE_SECONDARY_RAT_USAGE_DATA_REPORT &&
			current_ie->instance == 0) {
			frca->secondary_rat_usage_data_report = current_ie;
		} else if (current_ie->type == IE_PRIVATE_EXTENSION) {
			frca->private_extension = current_ie;
		}

    }
    
	if (!frca->cause) {
		fprintf(stderr, "Dropping packet\n");
		return -EPERM;
	}

    return 0;
}

// TODO
static void
set_forward_relocation_complete_acknowledge() {
    /* TODO */
}

int
process_forward_relocation_complete_acknowledge(gtpv2c_header *gtpv2c_rx,
                               gtpv2c_header *gtpv2c_tx)
{
    /* TODO */
}
