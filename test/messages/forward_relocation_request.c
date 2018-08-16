@copyright

#include <errno.h>

#include "packet_filters.h"
#include "gtpv2c_set_ie.h"
#include "../cp_dp_api/vepc_cp_dp_api.h"

/** Information Elements in forward_relocation_request */
struct parse_forward_relocation_request_t {
	gtpv2c_ie *imsi;
	gtpv2c_ie *sender_fully_qualified_tunnel_endpoint_identifier_for_control_plane;
	gtpv2c_ie *pdn_connection;
	gtpv2c_ie *sgw_s11s4_ip_address_and_teid_for_control_plane;
	gtpv2c_ie *sgw_node_name;
	gtpv2c_ie *mmesgsn_amf_ue_mm_context;
	gtpv2c_ie *indication_flags;
	gtpv2c_ie *e_utran_transparent_container;
	gtpv2c_ie *utran_transparent_container;
	gtpv2c_ie *bss_container;
	gtpv2c_ie *target_identification;
	gtpv2c_ie *hrpd_access_node_s101_ip_address;
	gtpv2c_ie *Onexiws_s102_ip_address;
	gtpv2c_ie *s1_ap_cause;
	gtpv2c_ie *ranap_cause;
	gtpv2c_ie *bssgp_cause;
	gtpv2c_ie *source_identification;
	gtpv2c_ie *selected_plmn_id;
	gtpv2c_ie *recovery;
	gtpv2c_ie *trace_information;
	gtpv2c_ie *subscribed_rfsp_index;
	gtpv2c_ie *rfsp_index_in_use;
	gtpv2c_ie *csg_id;
	gtpv2c_ie *csg_membership_indication;
	gtpv2c_ie *ue_time_zone;
	gtpv2c_ie *serving_network;
	gtpv2c_ie *mmes4_sgsn_ldn;
	gtpv2c_ie *additional_mm_context_for_srvcc;
	gtpv2c_ie *additional_flags_for_srvcc;
	gtpv2c_ie *stn_sr;
	gtpv2c_ie *c_msisdn;
	gtpv2c_ie *mdt_configuration;
	gtpv2c_ie *sgsn_node_name;
	gtpv2c_ie *mme_node_name;
	gtpv2c_ie *user_csg_information;
	gtpv2c_ie *monitoring_event_information;
	gtpv2c_ie *ue_usage_type;
	gtpv2c_ie *mmesgsn_ue_scef_pdn_connections;
	gtpv2c_ie *msisdn;
	gtpv2c_ie *source_udp_port_number;
	gtpv2c_ie *serving_plmn_rate_control;
	gtpv2c_ie *private_extension;
};

static int
parse_forward_relocation_request(gtpv2c_header *gtpv2c_rx,
          struct parse_forward_relocation_request_t *frr)
{
    gtpv2c_ie *current_ie;
    gtpv2c_ie *current_group_ie;
    gtpv2c_ie *limit_ie;
    gtpv2c_ie *limit_group_ie;
    
    FOR_EACH_GTPV2C_IE(gtpv2c_rx, current_ie, limit_ie)
    {
		if (current_ie->type == IE_IMSI &&
			current_ie->instance == 0) {
			frr->imsi = current_ie;
		} else if (current_ie->type == IE_FULLY_QUALIFIED_TUNNEL_ENDPOINT_IDENTIFIER &&
			current_ie->instance == 0) {
			frr->sender_fully_qualified_tunnel_endpoint_identifier_for_control_plane = current_ie;
		} else if (current_ie->type == IE_PDN_CONNECTION &&
			current_ie->instance == 0) {
			frr->pdn_connection = current_ie;
		} else if (current_ie->type == IE_FULLY_QUALIFIED_TUNNEL_ENDPOINT_IDENTIFIER &&
			current_ie->instance == 1) {
			frr->sgw_s11s4_ip_address_and_teid_for_control_plane = current_ie;
		} else if (current_ie->type == IE_FULLY_QUALIFIED_DOMAIN_NAME &&
			current_ie->instance == 0) {
			frr->sgw_node_name = current_ie;
		} else if (current_ie->type == IE_MM_CONTEXT &&
			current_ie->instance == 0) {
			frr->mmesgsn_amf_ue_mm_context = current_ie;
		} else if (current_ie->type == IE_INDICATION &&
			current_ie->instance == 0) {
			frr->indication_flags = current_ie;
		} else if (current_ie->type == IE_FULLY_QUALIFIED_CONTAINER &&
			current_ie->instance == 0) {
			frr->e_utran_transparent_container = current_ie;
		} else if (current_ie->type == IE_FULLY_QUALIFIED_CONTAINER &&
			current_ie->instance == 1) {
			frr->utran_transparent_container = current_ie;
		} else if (current_ie->type == IE_FULLY_QUALIFIED_CONTAINER &&
			current_ie->instance == 2) {
			frr->bss_container = current_ie;
		} else if (current_ie->type == IE_TARGET_IDENTIFICATION &&
			current_ie->instance == 0) {
			frr->target_identification = current_ie;
		} else if (current_ie->type == IE_IP_ADDRESS &&
			current_ie->instance == 0) {
			frr->hrpd_access_node_s101_ip_address = current_ie;
		} else if (current_ie->type == IE_IP_ADDRESS &&
			current_ie->instance == 1) {
			frr->Onexiws_s102_ip_address = current_ie;
		} else if (current_ie->type == IE_FULLY_QUALIFIED_CAUSE &&
			current_ie->instance == 0) {
			frr->s1_ap_cause = current_ie;
		} else if (current_ie->type == IE_FULLY_QUALIFIED_CAUSE &&
			current_ie->instance == 1) {
			frr->ranap_cause = current_ie;
		} else if (current_ie->type == IE_FULLY_QUALIFIED_CAUSE &&
			current_ie->instance == 2) {
			frr->bssgp_cause = current_ie;
		} else if (current_ie->type == IE_SOURCE_IDENTIFICATION &&
			current_ie->instance == 0) {
			frr->source_identification = current_ie;
		} else if (current_ie->type == IE_PLMN_ID &&
			current_ie->instance == 0) {
			frr->selected_plmn_id = current_ie;
		} else if (current_ie->type == IE_RECOVERY_RESTART_COUNTER &&
			current_ie->instance == 0) {
			frr->recovery = current_ie;
		} else if (current_ie->type == IE_TRACE_INFORMATION &&
			current_ie->instance == 0) {
			frr->trace_information = current_ie;
		} else if (current_ie->type == IE_RFSP_INDEX &&
			current_ie->instance == 0) {
			frr->subscribed_rfsp_index = current_ie;
		} else if (current_ie->type == IE_RFSP_INDEX &&
			current_ie->instance == 1) {
			frr->rfsp_index_in_use = current_ie;
		} else if (current_ie->type == IE_CSG_ID &&
			current_ie->instance == 0) {
			frr->csg_id = current_ie;
		} else if (current_ie->type == IE_CSG_MEMBERSHIP_INDICATION &&
			current_ie->instance == 0) {
			frr->csg_membership_indication = current_ie;
		} else if (current_ie->type == IE_UE_TIME_ZONE &&
			current_ie->instance == 0) {
			frr->ue_time_zone = current_ie;
		} else if (current_ie->type == IE_SERVING_NETWORK &&
			current_ie->instance == 0) {
			frr->serving_network = current_ie;
		} else if (current_ie->type == IE_LOCAL_DISTINGUISHED_NAME &&
			current_ie->instance == 0) {
			frr->mmes4_sgsn_ldn = current_ie;
		} else if (current_ie->type == IE_ADDITIONAL_MM_CONTEXT_FOR_SRVCC &&
			current_ie->instance == 0) {
			frr->additional_mm_context_for_srvcc = current_ie;
		} else if (current_ie->type == IE_ADDITIONAL_FLAGS_FOR_SRVCC &&
			current_ie->instance == 0) {
			frr->additional_flags_for_srvcc = current_ie;
		} else if (current_ie->type == IE_STN_SR &&
			current_ie->instance == 0) {
			frr->stn_sr = current_ie;
		} else if (current_ie->type == IE_MSISDN &&
			current_ie->instance == 0) {
			frr->c_msisdn = current_ie;
		} else if (current_ie->type == IE_MDT_CONFIGURATION &&
			current_ie->instance == 0) {
			frr->mdt_configuration = current_ie;
		} else if (current_ie->type == IE_FULLY_QUALIFIED_DOMAIN_NAME &&
			current_ie->instance == 1) {
			frr->sgsn_node_name = current_ie;
		} else if (current_ie->type == IE_FULLY_QUALIFIED_DOMAIN_NAME &&
			current_ie->instance == 2) {
			frr->mme_node_name = current_ie;
		} else if (current_ie->type == IE_USER_CSG_INFORMATION &&
			current_ie->instance == 0) {
			frr->user_csg_information = current_ie;
		} else if (current_ie->type == IE_MONITORING_EVENT_INFORMATION &&
			current_ie->instance == 0) {
			frr->monitoring_event_information = current_ie;
		} else if (current_ie->type == IE_INTEGER_NUMBER &&
			current_ie->instance == 0) {
			frr->ue_usage_type = current_ie;
		} else if (current_ie->type == IE_SCEF_PDN_CONNECTION &&
			current_ie->instance == 0) {
			frr->mmesgsn_ue_scef_pdn_connections = current_ie;
		} else if (current_ie->type == IE_MSISDN &&
			current_ie->instance == 1) {
			frr->msisdn = current_ie;
		} else if (current_ie->type == IE_PORT_NUMBER &&
			current_ie->instance == 0) {
			frr->source_udp_port_number = current_ie;
		} else if (current_ie->type == IE_SERVING_PLMN_RATE_CONTROL &&
			current_ie->instance == 0) {
			frr->serving_plmn_rate_control = current_ie;
		} else if (current_ie->type == IE_PRIVATE_EXTENSION) {
			frr->private_extension = current_ie;
		}

    }
    
	if (!frr->sender_fully_qualified_tunnel_endpoint_identifier_for_control_plane
		|| !frr->mmesgsn_amf_ue_mm_context) {
		fprintf(stderr, "Dropping packet\n");
		return -EPERM;
	}

    return 0;
}

// TODO
static void
set_forward_relocation_request() {
    /* TODO */
}

int
process_forward_relocation_request(gtpv2c_header *gtpv2c_rx,
                               gtpv2c_header *gtpv2c_tx)
{
    /* TODO */
}
