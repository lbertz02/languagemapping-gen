@copyright

#include <errno.h>

#include "packet_filters.h"
#include "gtpv2c_set_ie.h"
#include "../cp_dp_api/vepc_cp_dp_api.h"

/** Information Elements in mbms_session_update_response */
struct parse_mbms_session_update_response_t {
	gtpv2c_ie *cause;
	gtpv2c_ie *mbms_distribution_acknowledge;
	gtpv2c_ie *sn_u_sgsn_f_teid;
	gtpv2c_ie *recovery;
	gtpv2c_ie *private_extension;
};

static int
parse_mbms_session_update_response(gtpv2c_header *gtpv2c_rx,
          struct parse_mbms_session_update_response_t *msur)
{
    gtpv2c_ie *current_ie;
    gtpv2c_ie *current_group_ie;
    gtpv2c_ie *limit_ie;
    gtpv2c_ie *limit_group_ie;
    
    FOR_EACH_GTPV2C_IE(gtpv2c_rx, current_ie, limit_ie)
    {
		if (current_ie->type == IE_CAUSE &&
			current_ie->instance == 0) {
			msur->cause = current_ie;
		} else if (current_ie->type == IE_MBMS_DISTRIBUTION_ACKNOWLEDGE &&
			current_ie->instance == 0) {
			msur->mbms_distribution_acknowledge = current_ie;
		} else if (current_ie->type == IE_FULLY_QUALIFIED_TUNNEL_ENDPOINT_IDENTIFIER &&
			current_ie->instance == 0) {
			msur->sn_u_sgsn_f_teid = current_ie;
		} else if (current_ie->type == IE_RECOVERY_RESTART_COUNTER &&
			current_ie->instance == 0) {
			msur->recovery = current_ie;
		} else if (current_ie->type == IE_PRIVATE_EXTENSION) {
			msur->private_extension = current_ie;
		}

    }
    
	if (!msur->cause) {
		fprintf(stderr, "Dropping packet\n");
		return -EPERM;
	}

    return 0;
}

// TODO
static void
set_mbms_session_update_response() {
    /* TODO */
}

int
process_mbms_session_update_response(gtpv2c_header *gtpv2c_rx,
                               gtpv2c_header *gtpv2c_tx)
{
    /* TODO */
}
