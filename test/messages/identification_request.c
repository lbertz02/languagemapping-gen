@copyright

#include <errno.h>

#include "packet_filters.h"
#include "gtpv2c_set_ie.h"
#include "../cp_dp_api/vepc_cp_dp_api.h"

/** Information Elements in identification_request */
struct parse_identification_request_t {
	gtpv2c_ie *guti;
	gtpv2c_ie *routeing_area_identity;
	gtpv2c_ie *packet_tmsi;
	gtpv2c_ie *p_tmsi_signature;
	gtpv2c_ie *complete_attach_request_message;
	gtpv2c_ie *address_for_control_plane;
	gtpv2c_ie *udp_source_port_number;
	gtpv2c_ie *hop_counter;
	gtpv2c_ie *target_plmn_id;
	gtpv2c_ie *private_extension;
};

static int
parse_identification_request(gtpv2c_header *gtpv2c_rx,
          struct parse_identification_request_t *ir)
{
    gtpv2c_ie *current_ie;
    gtpv2c_ie *current_group_ie;
    gtpv2c_ie *limit_ie;
    gtpv2c_ie *limit_group_ie;
    
    FOR_EACH_GTPV2C_IE(gtpv2c_rx, current_ie, limit_ie)
    {
		if (current_ie->type == IE_GUTI &&
			current_ie->instance == 0) {
			ir->guti = current_ie;
		} else if (current_ie->type == IE_USER_LOCATION_INFORMATION &&
			current_ie->instance == 0) {
			ir->routeing_area_identity = current_ie;
		} else if (current_ie->type == IE_PACKET_TMSI &&
			current_ie->instance == 0) {
			ir->packet_tmsi = current_ie;
		} else if (current_ie->type == IE_P_TMSI_SIGNATURE &&
			current_ie->instance == 0) {
			ir->p_tmsi_signature = current_ie;
		} else if (current_ie->type == IE_COMPLETE_REQUEST_MESSAGE &&
			current_ie->instance == 0) {
			ir->complete_attach_request_message = current_ie;
		} else if (current_ie->type == IE_IP_ADDRESS &&
			current_ie->instance == 0) {
			ir->address_for_control_plane = current_ie;
		} else if (current_ie->type == IE_PORT_NUMBER &&
			current_ie->instance == 0) {
			ir->udp_source_port_number = current_ie;
		} else if (current_ie->type == IE_HOP_COUNTER &&
			current_ie->instance == 0) {
			ir->hop_counter = current_ie;
		} else if (current_ie->type == IE_SERVING_NETWORK &&
			current_ie->instance == 0) {
			ir->target_plmn_id = current_ie;
		} else if (current_ie->type == IE_PRIVATE_EXTENSION) {
			ir->private_extension = current_ie;
		}

    }
    

    return 0;
}

// TODO
static void
set_identification_request() {
    /* TODO */
}

int
process_identification_request(gtpv2c_header *gtpv2c_rx,
                               gtpv2c_header *gtpv2c_tx)
{
    /* TODO */
}
