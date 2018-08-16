@copyright

#include <errno.h>

#include "packet_filters.h"
#include "gtpv2c_set_ie.h"
#include "../cp_dp_api/vepc_cp_dp_api.h"

/** Information Elements in pgw_downlink_triggering_notification */
struct parse_pgw_downlink_triggering_notification_t {
	gtpv2c_ie *imsi;
	gtpv2c_ie *mmes4_sgsn_identifier;
	gtpv2c_ie *pgw_s5_fully_qualified_tunnel_endpoint_identifier_for_gtp_or_pmip_control_plane;
	gtpv2c_ie *private_extension;
};

static int
parse_pgw_downlink_triggering_notification(gtpv2c_header *gtpv2c_rx,
          struct parse_pgw_downlink_triggering_notification_t *pdtn)
{
    gtpv2c_ie *current_ie;
    gtpv2c_ie *current_group_ie;
    gtpv2c_ie *limit_ie;
    gtpv2c_ie *limit_group_ie;
    
    FOR_EACH_GTPV2C_IE(gtpv2c_rx, current_ie, limit_ie)
    {
		if (current_ie->type == IE_IMSI &&
			current_ie->instance == 0) {
			pdtn->imsi = current_ie;
		} else if (current_ie->type == IE_IP_ADDRESS &&
			current_ie->instance == 0) {
			pdtn->mmes4_sgsn_identifier = current_ie;
		} else if (current_ie->type == IE_FULLY_QUALIFIED_TUNNEL_ENDPOINT_IDENTIFIER &&
			current_ie->instance == 0) {
			pdtn->pgw_s5_fully_qualified_tunnel_endpoint_identifier_for_gtp_or_pmip_control_plane = current_ie;
		} else if (current_ie->type == IE_PRIVATE_EXTENSION) {
			pdtn->private_extension = current_ie;
		}

    }
    
	if (!pdtn->imsi) {
		fprintf(stderr, "Dropping packet\n");
		return -EPERM;
	}

    return 0;
}

// TODO
static void
set_pgw_downlink_triggering_notification() {
    /* TODO */
}

int
process_pgw_downlink_triggering_notification(gtpv2c_header *gtpv2c_rx,
                               gtpv2c_header *gtpv2c_tx)
{
    /* TODO */
}
