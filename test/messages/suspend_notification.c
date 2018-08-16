@copyright

#include <errno.h>

#include "packet_filters.h"
#include "gtpv2c_set_ie.h"
#include "../cp_dp_api/vepc_cp_dp_api.h"

/** Information Elements in suspend_notification */
struct parse_suspend_notification_t {
	gtpv2c_ie *imsi;
	gtpv2c_ie *routeing_area_identity;
	gtpv2c_ie *linked_eps_bearer_id;
	gtpv2c_ie *packet_tmsi;
	gtpv2c_ie *originating_node;
	gtpv2c_ie *address_for_control_plane;
	gtpv2c_ie *udp_source_port_number;
	gtpv2c_ie *hop_counter;
	gtpv2c_ie *sender_fully_qualified_tunnel_endpoint_identifier_for_control_plane;
	gtpv2c_ie *private_extension;
};

static int
parse_suspend_notification(gtpv2c_header *gtpv2c_rx,
          struct parse_suspend_notification_t *sn)
{
    gtpv2c_ie *current_ie;
    gtpv2c_ie *current_group_ie;
    gtpv2c_ie *limit_ie;
    gtpv2c_ie *limit_group_ie;
    
    FOR_EACH_GTPV2C_IE(gtpv2c_rx, current_ie, limit_ie)
    {
		if (current_ie->type == IE_IMSI &&
			current_ie->instance == 0) {
			sn->imsi = current_ie;
		} else if (current_ie->type == IE_USER_LOCATION_INFORMATION &&
			current_ie->instance == 0) {
			sn->routeing_area_identity = current_ie;
		} else if (current_ie->type == IE_EPS_BEARER_ID &&
			current_ie->instance == 0) {
			sn->linked_eps_bearer_id = current_ie;
		} else if (current_ie->type == IE_PACKET_TMSI &&
			current_ie->instance == 0) {
			sn->packet_tmsi = current_ie;
		} else if (current_ie->type == IE_NODE_TYPE &&
			current_ie->instance == 0) {
			sn->originating_node = current_ie;
		} else if (current_ie->type == IE_IP_ADDRESS &&
			current_ie->instance == 0) {
			sn->address_for_control_plane = current_ie;
		} else if (current_ie->type == IE_PORT_NUMBER &&
			current_ie->instance == 0) {
			sn->udp_source_port_number = current_ie;
		} else if (current_ie->type == IE_HOP_COUNTER &&
			current_ie->instance == 0) {
			sn->hop_counter = current_ie;
		} else if (current_ie->type == IE_FULLY_QUALIFIED_TUNNEL_ENDPOINT_IDENTIFIER &&
			current_ie->instance == 0) {
			sn->sender_fully_qualified_tunnel_endpoint_identifier_for_control_plane = current_ie;
		} else if (current_ie->type == IE_PRIVATE_EXTENSION) {
			sn->private_extension = current_ie;
		}

    }
    

    return 0;
}

// TODO
static void
set_suspend_notification() {
    /* TODO */
}

int
process_suspend_notification(gtpv2c_header *gtpv2c_rx,
                               gtpv2c_header *gtpv2c_tx)
{
    /* TODO */
}
