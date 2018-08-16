@copyright

#include <errno.h>

#include "packet_filters.h"
#include "gtpv2c_set_ie.h"
#include "../cp_dp_api/vepc_cp_dp_api.h"

/** Information Elements in modify_bearer_request */
struct parse_modify_bearer_request_t {
	gtpv2c_ie *me_identity;
	gtpv2c_ie *user_location_information;
	gtpv2c_ie *serving_network;
	gtpv2c_ie *indication_flags;
	gtpv2c_ie *sender_f_teid_for_control_plane;
	gtpv2c_ie *aggregate_maximum_bit_rate;
	gtpv2c_ie *delay_downlink_packet_notification_request;
	gtpv2c_ie *bearer_contexts_to_be_modified;
	gtpv2c_ie *bearer_contexts_to_be_removed;
	gtpv2c_ie *recovery;
	gtpv2c_ie *ue_time_zone;
	gtpv2c_ie *mme_fq_csid;
	gtpv2c_ie *sgw_fq_csid;
	gtpv2c_ie *user_csg_information;
	gtpv2c_ie *ue_local_ip_address;
	gtpv2c_ie *ue_udp_port;
	gtpv2c_ie *mmes4_sgsn_ldn;
	gtpv2c_ie *sgw_ldn;
	gtpv2c_ie *h_enb_local_ip_address;
	gtpv2c_ie *h_enb_udp_port;
	gtpv2c_ie *mmes4_sgsn_identifier;
	gtpv2c_ie *cn_operator_selection_entity;
	gtpv2c_ie *presence_reporting_area_information;
	gtpv2c_ie *mmes4_sgsn_overload_control_information;
	gtpv2c_ie *sgw_overload_control_information;
	gtpv2c_ie *epdg_overload_control_information;
	gtpv2c_ie *serving_plmn_rate_control;
	gtpv2c_ie *mo_exception_data_counter;
	gtpv2c_ie *imsi;
	gtpv2c_ie *user_location_information_for_sgw;
	gtpv2c_ie *wlan_location_information;
	gtpv2c_ie *wlan_location_timestamp;
	gtpv2c_ie *secondary_rat_usage_data_report;
	gtpv2c_ie *private_extension;
};

static int
parse_modify_bearer_request(gtpv2c_header *gtpv2c_rx,
          struct parse_modify_bearer_request_t *mbr)
{
    gtpv2c_ie *current_ie;
    gtpv2c_ie *current_group_ie;
    gtpv2c_ie *limit_ie;
    gtpv2c_ie *limit_group_ie;
    
    FOR_EACH_GTPV2C_IE(gtpv2c_rx, current_ie, limit_ie)
    {
		if (current_ie->type == IE_MOBILE_EQUIPMENT_IDENTITY &&
			current_ie->instance == 0) {
			mbr->me_identity = current_ie;
		} else if (current_ie->type == IE_USER_LOCATION_INFORMATION &&
			current_ie->instance == 0) {
			mbr->user_location_information = current_ie;
		} else if (current_ie->type == IE_SERVING_NETWORK &&
			current_ie->instance == 0) {
			mbr->serving_network = current_ie;
		} else if (current_ie->type == IE_INDICATION &&
			current_ie->instance == 0) {
			mbr->indication_flags = current_ie;
		} else if (current_ie->type == IE_FULLY_QUALIFIED_TUNNEL_ENDPOINT_IDENTIFIER &&
			current_ie->instance == 0) {
			mbr->sender_f_teid_for_control_plane = current_ie;
		} else if (current_ie->type == IE_AGGREGATE_MAXIMUM_BIT_RATE &&
			current_ie->instance == 0) {
			mbr->aggregate_maximum_bit_rate = current_ie;
		} else if (current_ie->type == IE_DELAY_VALUE &&
			current_ie->instance == 0) {
			mbr->delay_downlink_packet_notification_request = current_ie;
		} else if (current_ie->type == IE_BEARER_CONTEXT &&
			current_ie->instance == 0) {
			mbr->bearer_contexts_to_be_modified = current_ie;
		} else if (current_ie->type == IE_BEARER_CONTEXT &&
			current_ie->instance == 1) {
			mbr->bearer_contexts_to_be_removed = current_ie;
		} else if (current_ie->type == IE_RECOVERY_RESTART_COUNTER &&
			current_ie->instance == 0) {
			mbr->recovery = current_ie;
		} else if (current_ie->type == IE_UE_TIME_ZONE &&
			current_ie->instance == 0) {
			mbr->ue_time_zone = current_ie;
		} else if (current_ie->type == IE_FQ_CSID &&
			current_ie->instance == 0) {
			mbr->mme_fq_csid = current_ie;
		} else if (current_ie->type == IE_FQ_CSID &&
			current_ie->instance == 1) {
			mbr->sgw_fq_csid = current_ie;
		} else if (current_ie->type == IE_USER_CSG_INFORMATION &&
			current_ie->instance == 0) {
			mbr->user_csg_information = current_ie;
		} else if (current_ie->type == IE_IP_ADDRESS &&
			current_ie->instance == 1) {
			mbr->ue_local_ip_address = current_ie;
		} else if (current_ie->type == IE_PORT_NUMBER &&
			current_ie->instance == 1) {
			mbr->ue_udp_port = current_ie;
		} else if (current_ie->type == IE_LOCAL_DISTINGUISHED_NAME &&
			current_ie->instance == 0) {
			mbr->mmes4_sgsn_ldn = current_ie;
		} else if (current_ie->type == IE_LOCAL_DISTINGUISHED_NAME &&
			current_ie->instance == 1) {
			mbr->sgw_ldn = current_ie;
		} else if (current_ie->type == IE_IP_ADDRESS &&
			current_ie->instance == 0) {
			mbr->h_enb_local_ip_address = current_ie;
		} else if (current_ie->type == IE_PORT_NUMBER &&
			current_ie->instance == 0) {
			mbr->h_enb_udp_port = current_ie;
		} else if (current_ie->type == IE_IP_ADDRESS &&
			current_ie->instance == 2) {
			mbr->mmes4_sgsn_identifier = current_ie;
		} else if (current_ie->type == IE_CN_OPERATOR_SELECTION_ENTITY &&
			current_ie->instance == 0) {
			mbr->cn_operator_selection_entity = current_ie;
		} else if (current_ie->type == IE_PRESENCE_REPORTING_AREA_INFORMATION &&
			current_ie->instance == 0) {
			mbr->presence_reporting_area_information = current_ie;
		} else if (current_ie->type == IE_OVERLOAD_CONTROL_INFORMATION &&
			current_ie->instance == 0) {
			mbr->mmes4_sgsn_overload_control_information = current_ie;
		} else if (current_ie->type == IE_OVERLOAD_CONTROL_INFORMATION &&
			current_ie->instance == 1) {
			mbr->sgw_overload_control_information = current_ie;
		} else if (current_ie->type == IE_OVERLOAD_CONTROL_INFORMATION &&
			current_ie->instance == 2) {
			mbr->epdg_overload_control_information = current_ie;
		} else if (current_ie->type == IE_SERVING_PLMN_RATE_CONTROL &&
			current_ie->instance == 0) {
			mbr->serving_plmn_rate_control = current_ie;
		} else if (current_ie->type == IE_COUNTER &&
			current_ie->instance == 0) {
			mbr->mo_exception_data_counter = current_ie;
		} else if (current_ie->type == IE_IMSI &&
			current_ie->instance == 0) {
			mbr->imsi = current_ie;
		} else if (current_ie->type == IE_USER_LOCATION_INFORMATION &&
			current_ie->instance == 1) {
			mbr->user_location_information_for_sgw = current_ie;
		} else if (current_ie->type == IE_TWAN_IDENTIFIER &&
			current_ie->instance == 0) {
			mbr->wlan_location_information = current_ie;
		} else if (current_ie->type == IE_TWAN_IDENTIFIER_TIMESTAMP &&
			current_ie->instance == 0) {
			mbr->wlan_location_timestamp = current_ie;
		} else if (current_ie->type == IE_SECONDARY_RAT_USAGE_DATA_REPORT &&
			current_ie->instance == 0) {
			mbr->secondary_rat_usage_data_report = current_ie;
		} else if (current_ie->type == IE_PRIVATE_EXTENSION) {
			mbr->private_extension = current_ie;
		}

    }
    

    return 0;
}

// TODO
static void
set_modify_bearer_request() {
    /* TODO */
}

int
process_modify_bearer_request(gtpv2c_header *gtpv2c_rx,
                               gtpv2c_header *gtpv2c_tx)
{
    /* TODO */
}
