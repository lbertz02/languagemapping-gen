@copyright

#include <errno.h>

#include "packet_filters.h"
#include "gtpv2c_set_ie.h"
#include "../cp_dp_api/vepc_cp_dp_api.h"

/** Information Elements in context_request */
struct parse_context_request_t {
	gtpv2c_ie *imsi;
	gtpv2c_ie *guti;
	gtpv2c_ie *routeing_area_identity;
	gtpv2c_ie *packet_tmsi;
	gtpv2c_ie *p_tmsi_signature;
	gtpv2c_ie *complete_tau_request_message;
	gtpv2c_ie *s3s16s10n26_address_and_teid_for_control_plane;
	gtpv2c_ie *udp_source_port_number;
	gtpv2c_ie *rat_type;
	gtpv2c_ie *indication;
	gtpv2c_ie *hop_counter;
	gtpv2c_ie *target_plmn_id;
	gtpv2c_ie *mmes4_sgsn_ldn;
	gtpv2c_ie *sgsn_node_name;
	gtpv2c_ie *mme_node_name;
	gtpv2c_ie *sgsn_number;
	gtpv2c_ie *sgsn_identifier;
	gtpv2c_ie *mme_identifier;
	gtpv2c_ie *ciot_optimizations_support_indication;
	gtpv2c_ie *private_extension;
};

static int
parse_context_request(gtpv2c_header *gtpv2c_rx,
          struct parse_context_request_t *cr)
{
    gtpv2c_ie *current_ie;
    gtpv2c_ie *current_group_ie;
    gtpv2c_ie *limit_ie;
    gtpv2c_ie *limit_group_ie;
    
    FOR_EACH_GTPV2C_IE(gtpv2c_rx, current_ie, limit_ie)
    {
		if (current_ie->type == IE_IMSI &&
			current_ie->instance == 0) {
			cr->imsi = current_ie;
		} else if (current_ie->type == IE_GUTI &&
			current_ie->instance == 0) {
			cr->guti = current_ie;
		} else if (current_ie->type == IE_USER_LOCATION_INFORMATION &&
			current_ie->instance == 0) {
			cr->routeing_area_identity = current_ie;
		} else if (current_ie->type == IE_PACKET_TMSI &&
			current_ie->instance == 0) {
			cr->packet_tmsi = current_ie;
		} else if (current_ie->type == IE_P_TMSI_SIGNATURE &&
			current_ie->instance == 0) {
			cr->p_tmsi_signature = current_ie;
		} else if (current_ie->type == IE_COMPLETE_REQUEST_MESSAGE &&
			current_ie->instance == 0) {
			cr->complete_tau_request_message = current_ie;
		} else if (current_ie->type == IE_FULLY_QUALIFIED_TUNNEL_ENDPOINT_IDENTIFIER &&
			current_ie->instance == 0) {
			cr->s3s16s10n26_address_and_teid_for_control_plane = current_ie;
		} else if (current_ie->type == IE_PORT_NUMBER &&
			current_ie->instance == 0) {
			cr->udp_source_port_number = current_ie;
		} else if (current_ie->type == IE_RAT_TYPE &&
			current_ie->instance == 0) {
			cr->rat_type = current_ie;
		} else if (current_ie->type == IE_INDICATION &&
			current_ie->instance == 0) {
			cr->indication = current_ie;
		} else if (current_ie->type == IE_HOP_COUNTER &&
			current_ie->instance == 0) {
			cr->hop_counter = current_ie;
		} else if (current_ie->type == IE_SERVING_NETWORK &&
			current_ie->instance == 0) {
			cr->target_plmn_id = current_ie;
		} else if (current_ie->type == IE_LOCAL_DISTINGUISHED_NAME &&
			current_ie->instance == 0) {
			cr->mmes4_sgsn_ldn = current_ie;
		} else if (current_ie->type == IE_FULLY_QUALIFIED_DOMAIN_NAME &&
			current_ie->instance == 0) {
			cr->sgsn_node_name = current_ie;
		} else if (current_ie->type == IE_FULLY_QUALIFIED_DOMAIN_NAME &&
			current_ie->instance == 1) {
			cr->mme_node_name = current_ie;
		} else if (current_ie->type == IE_NODE_NUMBER &&
			current_ie->instance == 0) {
			cr->sgsn_number = current_ie;
		} else if (current_ie->type == IE_NODE_IDENTIFIER &&
			current_ie->instance == 0) {
			cr->sgsn_identifier = current_ie;
		} else if (current_ie->type == IE_NODE_IDENTIFIER &&
			current_ie->instance == 1) {
			cr->mme_identifier = current_ie;
		} else if (current_ie->type == IE_CIOT_OPTIMIZATIONS_SUPPORT_INDICATION &&
			current_ie->instance == 0) {
			cr->ciot_optimizations_support_indication = current_ie;
		} else if (current_ie->type == IE_PRIVATE_EXTENSION) {
			cr->private_extension = current_ie;
		}

    }
    

    return 0;
}

// TODO
static void
set_context_request() {
    /* TODO */
}

int
process_context_request(gtpv2c_header *gtpv2c_rx,
                               gtpv2c_header *gtpv2c_tx)
{
    /* TODO */
}
