@copyright

#include <errno.h>

#include "packet_filters.h"
#include "gtpv2c_set_ie.h"
#include "../cp_dp_api/vepc_cp_dp_api.h"

/** Information Elements in resume_notification */
struct parse_resume_notification_t {
	gtpv2c_ie *imsi;
	gtpv2c_ie *linked_eps_bearer_id;
	gtpv2c_ie *originating_node;
	gtpv2c_ie *sender_f_teid_for_control_plane;
	gtpv2c_ie *private_extension;
};

static int
parse_resume_notification(gtpv2c_header *gtpv2c_rx,
          struct parse_resume_notification_t *rn)
{
    gtpv2c_ie *current_ie;
    gtpv2c_ie *current_group_ie;
    gtpv2c_ie *limit_ie;
    gtpv2c_ie *limit_group_ie;
    
    FOR_EACH_GTPV2C_IE(gtpv2c_rx, current_ie, limit_ie)
    {
		if (current_ie->type == IE_IMSI &&
			current_ie->instance == 0) {
			rn->imsi = current_ie;
		} else if (current_ie->type == IE_EPS_BEARER_ID &&
			current_ie->instance == 0) {
			rn->linked_eps_bearer_id = current_ie;
		} else if (current_ie->type == IE_NODE_TYPE &&
			current_ie->instance == 0) {
			rn->originating_node = current_ie;
		} else if (current_ie->type == IE_FULLY_QUALIFIED_TUNNEL_ENDPOINT_IDENTIFIER &&
			current_ie->instance == 0) {
			rn->sender_f_teid_for_control_plane = current_ie;
		} else if (current_ie->type == IE_PRIVATE_EXTENSION) {
			rn->private_extension = current_ie;
		}

    }
    
	if (!rn->imsi) {
		fprintf(stderr, "Dropping packet\n");
		return -EPERM;
	}

    return 0;
}

// TODO
static void
set_resume_notification() {
    /* TODO */
}

int
process_resume_notification(gtpv2c_header *gtpv2c_rx,
                               gtpv2c_header *gtpv2c_tx)
{
    /* TODO */
}
