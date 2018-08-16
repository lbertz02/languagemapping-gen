@copyright

#include <errno.h>

#include "packet_filters.h"
#include "gtpv2c_set_ie.h"
#include "../cp_dp_api/vepc_cp_dp_api.h"

/** Information Elements in create_session_request */
struct parse_create_session_request_t {
	gtpv2c_ie *imsi;
	gtpv2c_ie *msisdn;
	gtpv2c_ie *me_identity_;
	gtpv2c_ie *user_location_information_;
	gtpv2c_ie *rat_type;
	gtpv2c_ie *indication_flags;
	gtpv2c_ie *sender_f_teid_for_control_plane;
	gtpv2c_ie *pgw_s5s8_address_for_control_plane_or_pmip;
	gtpv2c_ie *access_point_name_;
	gtpv2c_ie *selection_mode;
	gtpv2c_ie *pdn_type;
	gtpv2c_ie *pdn_address_allocation_;
	gtpv2c_ie *maximum_apn_restriction;
	gtpv2c_ie *aggregate_maximum_bit_rate_;
	gtpv2c_ie *linked_eps_bearer_id;
	gtpv2c_ie *trusted_wlan_mode_indication;
	gtpv2c_ie *protocol_configuration_options_;
	gtpv2c_ie *bearer_contexts_to_be_created;
	gtpv2c_ie *bearer_contexts_to_be_removed;
	gtpv2c_ie *trace_information;
	gtpv2c_ie *recovery;
	gtpv2c_ie *mme_fq_csid;
	gtpv2c_ie *sgw_fq_csid;
	gtpv2c_ie *epdg_fq_csid;
	gtpv2c_ie *twan_fq_csid;
	gtpv2c_ie *ue_time_zone;
	gtpv2c_ie *user_csg_information_;
	gtpv2c_ie *charging_characteristics;
	gtpv2c_ie *mmex4_sgsn_ldn;
	gtpv2c_ie *sgw_ldn;
	gtpv2c_ie *epdg_ldn;
	gtpv2c_ie *twan_ldn;
	gtpv2c_ie *signalling_priority_indication;
	gtpv2c_ie *ue_local_ip_address;
	gtpv2c_ie *ue_udp_port;
	gtpv2c_ie *additional_protocol_configuration_options_;
	gtpv2c_ie *h_enb_local_ip_address;
	gtpv2c_ie *h_enb_udp_port;
	gtpv2c_ie *mmes4_sgsn_identifier;
	gtpv2c_ie *twan_identifier;
	gtpv2c_ie *epdg_ip_address;
	gtpv2c_ie *cn_operator_selection_entity;
	gtpv2c_ie *presence_reporting_area_information;
	gtpv2c_ie *mmes4_sgsn_overload_control_information;
	gtpv2c_ie *sgw_overload_control_information;
	gtpv2c_ie *twan_epdg_overload_control_information;
	gtpv2c_ie *origination_time_stamp;
	gtpv2c_ie *maximum_wait_time;
	gtpv2c_ie *wlan_location_information;
	gtpv2c_ie *wlan_location_timestamp;
	gtpv2c_ie *nbifom_container;
	gtpv2c_ie *remote_ue_context_connected;
	gtpv2c_ie *tgpp_aaa_server_identifier;
	gtpv2c_ie *extended_protocol_configuration_options_;
	gtpv2c_ie *serving_plmn_rate_control;
	gtpv2c_ie *mo_exception_data_counter;
	gtpv2c_ie *ue_tcp_port;
	gtpv2c_ie *mapped_ue_usage_type;
	gtpv2c_ie *user_location_information_for_sgw_;
	gtpv2c_ie *sgw_u_node_name;
	gtpv2c_ie *secondary_rat_usage_data_report;
	gtpv2c_ie *up_function_selection_indication_flags;
	gtpv2c_ie *private_extension;
};

static int
parse_create_session_request(gtpv2c_header *gtpv2c_rx,
          struct parse_create_session_request_t *csr)
{
    gtpv2c_ie *current_ie;
    gtpv2c_ie *current_group_ie;
    gtpv2c_ie *limit_ie;
    gtpv2c_ie *limit_group_ie;
    
    FOR_EACH_GTPV2C_IE(gtpv2c_rx, current_ie, limit_ie)
    {
		if (current_ie->type == IE_IMSI &&
			current_ie->instance == 0) {
			csr->imsi = current_ie;
		} else if (current_ie->type == IE_MSISDN &&
			current_ie->instance == 0) {
			csr->msisdn = current_ie;
		} else if (current_ie->type == IE_MOBILE_EQUIPMENT_IDENTITY &&
			current_ie->instance == 0) {
			csr->me_identity_ = current_ie;
		} else if (current_ie->type == IE_USER_LOCATION_INFORMATION &&
			current_ie->instance == 0) {
			csr->user_location_information_ = current_ie;
		} else if (current_ie->type == IE_RAT_TYPE &&
			current_ie->instance == 0) {
			csr->rat_type = current_ie;
		} else if (current_ie->type == IE_INDICATION &&
			current_ie->instance == 0) {
			csr->indication_flags = current_ie;
		} else if (current_ie->type == IE_FULLY_QUALIFIED_TUNNEL_ENDPOINT_IDENTIFIER &&
			current_ie->instance == 0) {
			csr->sender_f_teid_for_control_plane = current_ie;
		} else if (current_ie->type == IE_FULLY_QUALIFIED_TUNNEL_ENDPOINT_IDENTIFIER &&
			current_ie->instance == 1) {
			csr->pgw_s5s8_address_for_control_plane_or_pmip = current_ie;
		} else if (current_ie->type == IE_ACCESS_POINT_NAME &&
			current_ie->instance == 0) {
			csr->access_point_name_ = current_ie;
		} else if (current_ie->type == IE_SELECTION_MODE &&
			current_ie->instance == 0) {
			csr->selection_mode = current_ie;
		} else if (current_ie->type == IE_PDN_TYPE &&
			current_ie->instance == 0) {
			csr->pdn_type = current_ie;
		} else if (current_ie->type == IE_PDN_ADDRESS_ALLOCATION &&
			current_ie->instance == 0) {
			csr->pdn_address_allocation_ = current_ie;
		} else if (current_ie->type == IE_ACCESS_POINT_NAME_RESTRICTION &&
			current_ie->instance == 0) {
			csr->maximum_apn_restriction = current_ie;
		} else if (current_ie->type == IE_AGGREGATE_MAXIMUM_BIT_RATE &&
			current_ie->instance == 0) {
			csr->aggregate_maximum_bit_rate_ = current_ie;
		} else if (current_ie->type == IE_EPS_BEARER_ID &&
			current_ie->instance == 0) {
			csr->linked_eps_bearer_id = current_ie;
		} else if (current_ie->type == IE_TRUSTED_WLAN_MODE_INDICATION &&
			current_ie->instance == 0) {
			csr->trusted_wlan_mode_indication = current_ie;
		} else if (current_ie->type == IE_PROTOCOL_CONFIGURATION_OPTIONS &&
			current_ie->instance == 0) {
			csr->protocol_configuration_options_ = current_ie;
		} else if (current_ie->type == IE_BEARER_CONTEXT &&
			current_ie->instance == 0) {
			csr->bearer_contexts_to_be_created = current_ie;
		} else if (current_ie->type == IE_BEARER_CONTEXT &&
			current_ie->instance == 1) {
			csr->bearer_contexts_to_be_removed = current_ie;
		} else if (current_ie->type == IE_TRACE_INFORMATION &&
			current_ie->instance == 0) {
			csr->trace_information = current_ie;
		} else if (current_ie->type == IE_RECOVERY_RESTART_COUNTER &&
			current_ie->instance == 0) {
			csr->recovery = current_ie;
		} else if (current_ie->type == IE_FQ_CSID &&
			current_ie->instance == 0) {
			csr->mme_fq_csid = current_ie;
		} else if (current_ie->type == IE_FQ_CSID &&
			current_ie->instance == 1) {
			csr->sgw_fq_csid = current_ie;
		} else if (current_ie->type == IE_FQ_CSID &&
			current_ie->instance == 2) {
			csr->epdg_fq_csid = current_ie;
		} else if (current_ie->type == IE_FQ_CSID &&
			current_ie->instance == 3) {
			csr->twan_fq_csid = current_ie;
		} else if (current_ie->type == IE_UE_TIME_ZONE &&
			current_ie->instance == 0) {
			csr->ue_time_zone = current_ie;
		} else if (current_ie->type == IE_USER_CSG_INFORMATION &&
			current_ie->instance == 0) {
			csr->user_csg_information_ = current_ie;
		} else if (current_ie->type == IE_CHARGING_CHARACTERISTICS &&
			current_ie->instance == 0) {
			csr->charging_characteristics = current_ie;
		} else if (current_ie->type == IE_LOCAL_DISTINGUISHED_NAME &&
			current_ie->instance == 0) {
			csr->mmex4_sgsn_ldn = current_ie;
		} else if (current_ie->type == IE_LOCAL_DISTINGUISHED_NAME &&
			current_ie->instance == 1) {
			csr->sgw_ldn = current_ie;
		} else if (current_ie->type == IE_LOCAL_DISTINGUISHED_NAME &&
			current_ie->instance == 2) {
			csr->epdg_ldn = current_ie;
		} else if (current_ie->type == IE_LOCAL_DISTINGUISHED_NAME &&
			current_ie->instance == 3) {
			csr->twan_ldn = current_ie;
		} else if (current_ie->type == IE_SIGNALLING_PRIORITY_INDICATION &&
			current_ie->instance == 0) {
			csr->signalling_priority_indication = current_ie;
		} else if (current_ie->type == IE_IP_ADDRESS &&
			current_ie->instance == 0) {
			csr->ue_local_ip_address = current_ie;
		} else if (current_ie->type == IE_PORT_NUMBER &&
			current_ie->instance == 0) {
			csr->ue_udp_port = current_ie;
		} else if (current_ie->type == IE_ADDITIONAL_PROTOCOL_CONFIGURATION_OPTIONS &&
			current_ie->instance == 0) {
			csr->additional_protocol_configuration_options_ = current_ie;
		} else if (current_ie->type == IE_IP_ADDRESS &&
			current_ie->instance == 1) {
			csr->h_enb_local_ip_address = current_ie;
		} else if (current_ie->type == IE_PORT_NUMBER &&
			current_ie->instance == 1) {
			csr->h_enb_udp_port = current_ie;
		} else if (current_ie->type == IE_IP_ADDRESS &&
			current_ie->instance == 2) {
			csr->mmes4_sgsn_identifier = current_ie;
		} else if (current_ie->type == IE_TWAN_IDENTIFIER &&
			current_ie->instance == 0) {
			csr->twan_identifier = current_ie;
		} else if (current_ie->type == IE_IP_ADDRESS &&
			current_ie->instance == 3) {
			csr->epdg_ip_address = current_ie;
		} else if (current_ie->type == IE_CN_OPERATOR_SELECTION_ENTITY &&
			current_ie->instance == 0) {
			csr->cn_operator_selection_entity = current_ie;
		} else if (current_ie->type == IE_PRESENCE_REPORTING_AREA_INFORMATION &&
			current_ie->instance == 0) {
			csr->presence_reporting_area_information = current_ie;
		} else if (current_ie->type == IE_OVERLOAD_CONTROL_INFORMATION &&
			current_ie->instance == 0) {
			csr->mmes4_sgsn_overload_control_information = current_ie;
		} else if (current_ie->type == IE_OVERLOAD_CONTROL_INFORMATION &&
			current_ie->instance == 1) {
			csr->sgw_overload_control_information = current_ie;
		} else if (current_ie->type == IE_OVERLOAD_CONTROL_INFORMATION &&
			current_ie->instance == 2) {
			csr->twan_epdg_overload_control_information = current_ie;
		} else if (current_ie->type == IE_MILLISECOND_TIME_STAMP &&
			current_ie->instance == 0) {
			csr->origination_time_stamp = current_ie;
		} else if (current_ie->type == IE_INTEGER_NUMBER &&
			current_ie->instance == 0) {
			csr->maximum_wait_time = current_ie;
		} else if (current_ie->type == IE_TWAN_IDENTIFIER &&
			current_ie->instance == 1) {
			csr->wlan_location_information = current_ie;
		} else if (current_ie->type == IE_TWAN_IDENTIFIER_TIMESTAMP &&
			current_ie->instance == 0) {
			csr->wlan_location_timestamp = current_ie;
		} else if (current_ie->type == IE_FULLY_QUALIFIED_CONTAINER &&
			current_ie->instance == 0) {
			csr->nbifom_container = current_ie;
		} else if (current_ie->type == IE_REMOTE_UE_CONTEXT &&
			current_ie->instance == 0) {
			csr->remote_ue_context_connected = current_ie;
		} else if (current_ie->type == IE_NODE_IDENTIFIER &&
			current_ie->instance == 0) {
			csr->tgpp_aaa_server_identifier = current_ie;
		} else if (current_ie->type == IE_EXTENDED_PROTOCOL_CONFIGURATION_OPTIONS &&
			current_ie->instance == 0) {
			csr->extended_protocol_configuration_options_ = current_ie;
		} else if (current_ie->type == IE_SERVING_PLMN_RATE_CONTROL &&
			current_ie->instance == 0) {
			csr->serving_plmn_rate_control = current_ie;
		} else if (current_ie->type == IE_COUNTER &&
			current_ie->instance == 0) {
			csr->mo_exception_data_counter = current_ie;
		} else if (current_ie->type == IE_PORT_NUMBER &&
			current_ie->instance == 2) {
			csr->ue_tcp_port = current_ie;
		} else if (current_ie->type == IE_MAPPED_UE_USAGE_TYPE &&
			current_ie->instance == 0) {
			csr->mapped_ue_usage_type = current_ie;
		} else if (current_ie->type == IE_USER_LOCATION_INFORMATION &&
			current_ie->instance == 1) {
			csr->user_location_information_for_sgw_ = current_ie;
		} else if (current_ie->type == IE_FULLY_QUALIFIED_DOMAIN_NAME &&
			current_ie->instance == 0) {
			csr->sgw_u_node_name = current_ie;
		} else if (current_ie->type == IE_SECONDARY_RAT_USAGE_DATA_REPORT &&
			current_ie->instance == 0) {
			csr->secondary_rat_usage_data_report = current_ie;
		} else if (current_ie->type == IE_UP_FUNCTION_SELECTION_INDICATION_FLAGS &&
			current_ie->instance == 0) {
			csr->up_function_selection_indication_flags = current_ie;
		} else if (current_ie->type == IE_PRIVATE_EXTENSION) {
			csr->private_extension = current_ie;
		}

    }
    
	if (!csr->rat_type
		|| !csr->sender_f_teid_for_control_plane
		|| !csr->access_point_name_
		|| !csr->bearer_contexts_to_be_created) {
		fprintf(stderr, "Dropping packet\n");
		return -EPERM;
	}

    return 0;
}

// TODO
static void
set_create_session_request() {
    /* TODO */
}

int
process_create_session_request(gtpv2c_header *gtpv2c_rx,
                               gtpv2c_header *gtpv2c_tx)
{
    /* TODO */
}
