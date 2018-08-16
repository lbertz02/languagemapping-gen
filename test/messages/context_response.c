@copyright

#include <errno.h>

#include "packet_filters.h"
#include "gtpv2c_set_ie.h"
#include "../cp_dp_api/vepc_cp_dp_api.h"

/** Information Elements in context_response */
struct parse_context_response_t {
	gtpv2c_ie *cause;
	gtpv2c_ie *imsi;
	gtpv2c_ie *mmesgsnamf_ue_mm_context;
	gtpv2c_ie *pdn_connection;
	gtpv2c_ie *sender_fully_qualified_tunnel_endpoint_identifier_for_control_plane;
	gtpv2c_ie *sgw_s11s4_ip_address_and_teid_for_control_plane;
	gtpv2c_ie *sgw_node_name;
	gtpv2c_ie *indication_flags;
	gtpv2c_ie *trace_information;
	gtpv2c_ie *hrpd_access_node_s101_ip_address;
	gtpv2c_ie *onexiws_s102_ip_address;
	gtpv2c_ie *subscribed_rfsp_index;
	gtpv2c_ie *rfsp_index_in_use;
	gtpv2c_ie *ue_time_zone;
	gtpv2c_ie *mmes4_sgsn_ldn;
	gtpv2c_ie *mdt_configuration;
	gtpv2c_ie *sgsn_node_name;
	gtpv2c_ie *mme_node_name;
	gtpv2c_ie *user_csg_information;
	gtpv2c_ie *monitoring_event_information;
	gtpv2c_ie *ue_usage_type;
	gtpv2c_ie *scef_pdn_connection;
	gtpv2c_ie *rat_type;
	gtpv2c_ie *serving_plmn_rate_control;
	gtpv2c_ie *mo_exception_data_counter;
	gtpv2c_ie *remaining_running_service_gap_timer;
	gtpv2c_ie *private_extension;
};

static int
parse_context_response(gtpv2c_header *gtpv2c_rx,
          struct parse_context_response_t *cr)
{
    gtpv2c_ie *current_ie;
    gtpv2c_ie *current_group_ie;
    gtpv2c_ie *limit_ie;
    gtpv2c_ie *limit_group_ie;
    
    FOR_EACH_GTPV2C_IE(gtpv2c_rx, current_ie, limit_ie)
    {
		if (current_ie->type == IE_CAUSE &&
			current_ie->instance == 0) {
			cr->cause = current_ie;
		} else if (current_ie->type == IE_IMSI &&
			current_ie->instance == 0) {
			cr->imsi = current_ie;
		} else if (current_ie->type == IE_MM_CONTEXT &&
			current_ie->instance == 0) {
			cr->mmesgsnamf_ue_mm_context = current_ie;
		} else if (current_ie->type == IE_PDN_CONNECTION &&
			current_ie->instance == 0) {
			cr->pdn_connection = current_ie;
		} else if (current_ie->type == IE_FULLY_QUALIFIED_TUNNEL_ENDPOINT_IDENTIFIER &&
			current_ie->instance == 0) {
			cr->sender_fully_qualified_tunnel_endpoint_identifier_for_control_plane = current_ie;
		} else if (current_ie->type == IE_FULLY_QUALIFIED_TUNNEL_ENDPOINT_IDENTIFIER &&
			current_ie->instance == 1) {
			cr->sgw_s11s4_ip_address_and_teid_for_control_plane = current_ie;
		} else if (current_ie->type == IE_FULLY_QUALIFIED_DOMAIN_NAME &&
			current_ie->instance == 0) {
			cr->sgw_node_name = current_ie;
		} else if (current_ie->type == IE_INDICATION &&
			current_ie->instance == 0) {
			cr->indication_flags = current_ie;
		} else if (current_ie->type == IE_TRACE_INFORMATION &&
			current_ie->instance == 0) {
			cr->trace_information = current_ie;
		} else if (current_ie->type == IE_IP_ADDRESS &&
			current_ie->instance == 0) {
			cr->hrpd_access_node_s101_ip_address = current_ie;
		} else if (current_ie->type == IE_IP_ADDRESS &&
			current_ie->instance == 1) {
			cr->onexiws_s102_ip_address = current_ie;
		} else if (current_ie->type == IE_RFSP_INDEX &&
			current_ie->instance == 0) {
			cr->subscribed_rfsp_index = current_ie;
		} else if (current_ie->type == IE_RFSP_INDEX &&
			current_ie->instance == 1) {
			cr->rfsp_index_in_use = current_ie;
		} else if (current_ie->type == IE_UE_TIME_ZONE &&
			current_ie->instance == 0) {
			cr->ue_time_zone = current_ie;
		} else if (current_ie->type == IE_LOCAL_DISTINGUISHED_NAME &&
			current_ie->instance == 0) {
			cr->mmes4_sgsn_ldn = current_ie;
		} else if (current_ie->type == IE_MDT_CONFIGURATION &&
			current_ie->instance == 0) {
			cr->mdt_configuration = current_ie;
		} else if (current_ie->type == IE_FULLY_QUALIFIED_DOMAIN_NAME &&
			current_ie->instance == 1) {
			cr->sgsn_node_name = current_ie;
		} else if (current_ie->type == IE_FULLY_QUALIFIED_DOMAIN_NAME &&
			current_ie->instance == 2) {
			cr->mme_node_name = current_ie;
		} else if (current_ie->type == IE_USER_CSG_INFORMATION &&
			current_ie->instance == 0) {
			cr->user_csg_information = current_ie;
		} else if (current_ie->type == IE_MONITORING_EVENT_INFORMATION &&
			current_ie->instance == 0) {
			cr->monitoring_event_information = current_ie;
		} else if (current_ie->type == IE_INTEGER_NUMBER &&
			current_ie->instance == 0) {
			cr->ue_usage_type = current_ie;
		} else if (current_ie->type == IE_SCEF_PDN_CONNECTION &&
			current_ie->instance == 0) {
			cr->scef_pdn_connection = current_ie;
		} else if (current_ie->type == IE_RAT_TYPE &&
			current_ie->instance == 0) {
			cr->rat_type = current_ie;
		} else if (current_ie->type == IE_SERVING_PLMN_RATE_CONTROL &&
			current_ie->instance == 0) {
			cr->serving_plmn_rate_control = current_ie;
		} else if (current_ie->type == IE_COUNTER &&
			current_ie->instance == 0) {
			cr->mo_exception_data_counter = current_ie;
		} else if (current_ie->type == IE_INTEGER_NUMBER &&
			current_ie->instance == 1) {
			cr->remaining_running_service_gap_timer = current_ie;
		} else if (current_ie->type == IE_PRIVATE_EXTENSION) {
			cr->private_extension = current_ie;
		}

    }
    
	if (!cr->cause) {
		fprintf(stderr, "Dropping packet\n");
		return -EPERM;
	}

    return 0;
}

// TODO
static void
set_context_response() {
    /* TODO */
}

int
process_context_response(gtpv2c_header *gtpv2c_rx,
                               gtpv2c_header *gtpv2c_tx)
{
    /* TODO */
}
