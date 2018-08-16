@copyright

#include <errno.h>

#include "packet_filters.h"
#include "gtpv2c_set_ie.h"
#include "../cp_dp_api/vepc_cp_dp_api.h"

/** Information Elements in pgw_restart_notification */
struct parse_pgw_restart_notification_t {
	gtpv2c_ie *pgw_s5s8_ip_address_for_control_plane_or_pmip;
	gtpv2c_ie *sgw_s11s4_ip_address_for_control_plane;
	gtpv2c_ie *cause;
	gtpv2c_ie *private_extension;
};

static int
parse_pgw_restart_notification(gtpv2c_header *gtpv2c_rx,
          struct parse_pgw_restart_notification_t *prn)
{
    gtpv2c_ie *current_ie;
    gtpv2c_ie *current_group_ie;
    gtpv2c_ie *limit_ie;
    gtpv2c_ie *limit_group_ie;
    
    FOR_EACH_GTPV2C_IE(gtpv2c_rx, current_ie, limit_ie)
    {
		if (current_ie->type == IE_IP_ADDRESS &&
			current_ie->instance == 0) {
			prn->pgw_s5s8_ip_address_for_control_plane_or_pmip = current_ie;
		} else if (current_ie->type == IE_IP_ADDRESS &&
			current_ie->instance == 1) {
			prn->sgw_s11s4_ip_address_for_control_plane = current_ie;
		} else if (current_ie->type == IE_CAUSE &&
			current_ie->instance == 0) {
			prn->cause = current_ie;
		} else if (current_ie->type == IE_PRIVATE_EXTENSION) {
			prn->private_extension = current_ie;
		}

    }
    
	if (!prn->pgw_s5s8_ip_address_for_control_plane_or_pmip
		|| !prn->sgw_s11s4_ip_address_for_control_plane) {
		fprintf(stderr, "Dropping packet\n");
		return -EPERM;
	}

    return 0;
}

// TODO
static void
set_pgw_restart_notification() {
    /* TODO */
}

int
process_pgw_restart_notification(gtpv2c_header *gtpv2c_rx,
                               gtpv2c_header *gtpv2c_tx)
{
    /* TODO */
}
