@copyright

#include <errno.h>

#include "packet_filters.h"
#include "gtpv2c_set_ie.h"
#include "../cp_dp_api/vepc_cp_dp_api.h"

/** Information Elements in delete_pdn_connection_set_response */
struct parse_delete_pdn_connection_set_response_t {
	gtpv2c_ie *cause;
	gtpv2c_ie *recovery;
	gtpv2c_ie *private_extension;
};

static int
parse_delete_pdn_connection_set_response(gtpv2c_header *gtpv2c_rx,
          struct parse_delete_pdn_connection_set_response_t *dpcsr)
{
    gtpv2c_ie *current_ie;
    gtpv2c_ie *current_group_ie;
    gtpv2c_ie *limit_ie;
    gtpv2c_ie *limit_group_ie;
    
    FOR_EACH_GTPV2C_IE(gtpv2c_rx, current_ie, limit_ie)
    {
		if (current_ie->type == IE_CAUSE &&
			current_ie->instance == 0) {
			dpcsr->cause = current_ie;
		} else if (current_ie->type == IE_RECOVERY_RESTART_COUNTER &&
			current_ie->instance == 0) {
			dpcsr->recovery = current_ie;
		} else if (current_ie->type == IE_PRIVATE_EXTENSION) {
			dpcsr->private_extension = current_ie;
		}

    }
    
	if (!dpcsr->cause) {
		fprintf(stderr, "Dropping packet\n");
		return -EPERM;
	}

    return 0;
}

// TODO
static void
set_delete_pdn_connection_set_response() {
    /* TODO */
}

int
process_delete_pdn_connection_set_response(gtpv2c_header *gtpv2c_rx,
                               gtpv2c_header *gtpv2c_tx)
{
    /* TODO */
}
