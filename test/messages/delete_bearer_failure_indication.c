@copyright

#include <errno.h>

#include "packet_filters.h"
#include "gtpv2c_set_ie.h"
#include "../cp_dp_api/vepc_cp_dp_api.h"

/** Information Elements in delete_bearer_failure_indication */
struct parse_delete_bearer_failure_indication_t {
	gtpv2c_ie *cause;
	gtpv2c_ie *bearer_context;
	gtpv2c_ie *recovery;
	gtpv2c_ie *indication_flags;
	gtpv2c_ie *pgw_overload_control_information;
	gtpv2c_ie *sgw_overload_control_information;
	gtpv2c_ie *private_extension;
};

static int
parse_delete_bearer_failure_indication(gtpv2c_header *gtpv2c_rx,
          struct parse_delete_bearer_failure_indication_t *dbfi)
{
    gtpv2c_ie *current_ie;
    gtpv2c_ie *current_group_ie;
    gtpv2c_ie *limit_ie;
    gtpv2c_ie *limit_group_ie;
    
    FOR_EACH_GTPV2C_IE(gtpv2c_rx, current_ie, limit_ie)
    {
		if (current_ie->type == IE_CAUSE &&
			current_ie->instance == 0) {
			dbfi->cause = current_ie;
		} else if (current_ie->type == IE_BEARER_CONTEXT &&
			current_ie->instance == 0) {
			dbfi->bearer_context = current_ie;
		} else if (current_ie->type == IE_RECOVERY_RESTART_COUNTER &&
			current_ie->instance == 0) {
			dbfi->recovery = current_ie;
		} else if (current_ie->type == IE_INDICATION &&
			current_ie->instance == 0) {
			dbfi->indication_flags = current_ie;
		} else if (current_ie->type == IE_OVERLOAD_CONTROL_INFORMATION &&
			current_ie->instance == 0) {
			dbfi->pgw_overload_control_information = current_ie;
		} else if (current_ie->type == IE_OVERLOAD_CONTROL_INFORMATION &&
			current_ie->instance == 1) {
			dbfi->sgw_overload_control_information = current_ie;
		} else if (current_ie->type == IE_PRIVATE_EXTENSION) {
			dbfi->private_extension = current_ie;
		}

    }
    
	if (!dbfi->cause
		|| !dbfi->bearer_context) {
		fprintf(stderr, "Dropping packet\n");
		return -EPERM;
	}

    return 0;
}

// TODO
static void
set_delete_bearer_failure_indication() {
    /* TODO */
}

int
process_delete_bearer_failure_indication(gtpv2c_header *gtpv2c_rx,
                               gtpv2c_header *gtpv2c_tx)
{
    /* TODO */
}
