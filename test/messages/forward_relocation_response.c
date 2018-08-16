@copyright

#include <errno.h>

#include "packet_filters.h"
#include "gtpv2c_set_ie.h"
#include "../cp_dp_api/vepc_cp_dp_api.h"

/** Information Elements in forward_relocation_response */
struct parse_forward_relocation_response_t {
	gtpv2c_ie *cause;
	gtpv2c_ie *sender_fully_qualified_tunnel_endpoint_identifier_for_control_plane;
	gtpv2c_ie *indication_flags;
	gtpv2c_ie *s1_ap_cause;
	gtpv2c_ie *ranap_cause;
	gtpv2c_ie *bssgp_cause;
	gtpv2c_ie *e_utran_transparent_container;
	gtpv2c_ie *utran_transparent_container;
	gtpv2c_ie *bss_container;
	gtpv2c_ie *mmes4_sgsn_ldn;
	gtpv2c_ie *sgsn_node_name;
	gtpv2c_ie *mme_node_name;
	gtpv2c_ie *sgsn_number;
	gtpv2c_ie *sgsn_identifier;
	gtpv2c_ie *mme_identifier;
	gtpv2c_ie *mme_number_for_mt_sms;
	gtpv2c_ie *sgsn_identifier_for_mt_sms;
	gtpv2c_ie *mme_identifier_for_mt_sms;
	gtpv2c_ie *private_extension;
};

static int
parse_forward_relocation_response(gtpv2c_header *gtpv2c_rx,
          struct parse_forward_relocation_response_t *frr)
{
    gtpv2c_ie *current_ie;
    gtpv2c_ie *current_group_ie;
    gtpv2c_ie *limit_ie;
    gtpv2c_ie *limit_group_ie;
    
    FOR_EACH_GTPV2C_IE(gtpv2c_rx, current_ie, limit_ie)
    {
		if (current_ie->type == IE_CAUSE &&
			current_ie->instance == 0) {
			frr->cause = current_ie;
		} else if (current_ie->type == IE_FULLY_QUALIFIED_TUNNEL_ENDPOINT_IDENTIFIER &&
			current_ie->instance == 0) {
			frr->sender_fully_qualified_tunnel_endpoint_identifier_for_control_plane = current_ie;
		} else if (current_ie->type == IE_INDICATION &&
			current_ie->instance == 0) {
			frr->indication_flags = current_ie;
		} else if (current_ie->type == IE_FULLY_QUALIFIED_CAUSE &&
			current_ie->instance == 0) {
			frr->s1_ap_cause = current_ie;
		} else if (current_ie->type == IE_FULLY_QUALIFIED_CAUSE &&
			current_ie->instance == 1) {
			frr->ranap_cause = current_ie;
		} else if (current_ie->type == IE_FULLY_QUALIFIED_CAUSE &&
			current_ie->instance == 2) {
			frr->bssgp_cause = current_ie;
		} else if (current_ie->type == IE_FULLY_QUALIFIED_CONTAINER &&
			current_ie->instance == 0) {
			frr->e_utran_transparent_container = current_ie;
		} else if (current_ie->type == IE_FULLY_QUALIFIED_CONTAINER &&
			current_ie->instance == 1) {
			frr->utran_transparent_container = current_ie;
		} else if (current_ie->type == IE_FULLY_QUALIFIED_CONTAINER &&
			current_ie->instance == 2) {
			frr->bss_container = current_ie;
		} else if (current_ie->type == IE_LOCAL_DISTINGUISHED_NAME &&
			current_ie->instance == 0) {
			frr->mmes4_sgsn_ldn = current_ie;
		} else if (current_ie->type == IE_FULLY_QUALIFIED_DOMAIN_NAME &&
			current_ie->instance == 0) {
			frr->sgsn_node_name = current_ie;
		} else if (current_ie->type == IE_FULLY_QUALIFIED_DOMAIN_NAME &&
			current_ie->instance == 1) {
			frr->mme_node_name = current_ie;
		} else if (current_ie->type == IE_NODE_NUMBER &&
			current_ie->instance == 0) {
			frr->sgsn_number = current_ie;
		} else if (current_ie->type == IE_NODE_IDENTIFIER &&
			current_ie->instance == 0) {
			frr->sgsn_identifier = current_ie;
		} else if (current_ie->type == IE_NODE_IDENTIFIER &&
			current_ie->instance == 1) {
			frr->mme_identifier = current_ie;
		} else if (current_ie->type == IE_NODE_NUMBER &&
			current_ie->instance == 1) {
			frr->mme_number_for_mt_sms = current_ie;
		} else if (current_ie->type == IE_NODE_IDENTIFIER &&
			current_ie->instance == 2) {
			frr->sgsn_identifier_for_mt_sms = current_ie;
		} else if (current_ie->type == IE_NODE_IDENTIFIER &&
			current_ie->instance == 3) {
			frr->mme_identifier_for_mt_sms = current_ie;
		} else if (current_ie->type == IE_PRIVATE_EXTENSION) {
			frr->private_extension = current_ie;
		}

    }
    
	if (!frr->cause) {
		fprintf(stderr, "Dropping packet\n");
		return -EPERM;
	}

    return 0;
}

// TODO
static void
set_forward_relocation_response() {
    /* TODO */
}

int
process_forward_relocation_response(gtpv2c_header *gtpv2c_rx,
                               gtpv2c_header *gtpv2c_tx)
{
    /* TODO */
}
