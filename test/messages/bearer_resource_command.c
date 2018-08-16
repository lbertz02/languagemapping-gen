@copyright

#include <errno.h>

#include "packet_filters.h"
#include "gtpv2c_set_ie.h"
#include "../cp_dp_api/vepc_cp_dp_api.h"

/** Information Elements in bearer_resource_command */
struct parse_bearer_resource_command_t {
	gtpv2c_ie *linked_eps_bearer_id;
	gtpv2c_ie *procedure_transaction_id;
	gtpv2c_ie *flow_quality_of_service;
	gtpv2c_ie *traffic_aggregate_description;
	gtpv2c_ie *rat_type;
	gtpv2c_ie *serving_network;
	gtpv2c_ie *user_location_information;
	gtpv2c_ie *eps_bearer_id;
	gtpv2c_ie *indication_flags;
	gtpv2c_ie *s4_u_sgsn_f_teid;
	gtpv2c_ie *s12_rnc_f_teid;
	gtpv2c_ie *protocol_configuration_options;
	gtpv2c_ie *signalling_priority_indication;
	gtpv2c_ie *mmes4_sgsn_overload_control_information;
	gtpv2c_ie *sgw_overload_control_information;
	gtpv2c_ie *nbifom_container;
	gtpv2c_ie *extended_protocol_configuration_options_;
	gtpv2c_ie *sender_f_teid_for_control_plane;
	gtpv2c_ie *private_extension;
};

static int
parse_bearer_resource_command(gtpv2c_header *gtpv2c_rx,
          struct parse_bearer_resource_command_t *brc)
{
    gtpv2c_ie *current_ie;
    gtpv2c_ie *current_group_ie;
    gtpv2c_ie *limit_ie;
    gtpv2c_ie *limit_group_ie;
    
    FOR_EACH_GTPV2C_IE(gtpv2c_rx, current_ie, limit_ie)
    {
		if (current_ie->type == IE_EPS_BEARER_ID &&
			current_ie->instance == 0) {
			brc->linked_eps_bearer_id = current_ie;
		} else if (current_ie->type == IE_PROCEDURE_TRANSACTION_ID &&
			current_ie->instance == 0) {
			brc->procedure_transaction_id = current_ie;
		} else if (current_ie->type == IE_FLOW_QUALITY_OF_SERVICE &&
			current_ie->instance == 0) {
			brc->flow_quality_of_service = current_ie;
		} else if (current_ie->type == IE_TRAFFIC_AGGREGATE_DESCRIPTION &&
			current_ie->instance == 0) {
			brc->traffic_aggregate_description = current_ie;
		} else if (current_ie->type == IE_RAT_TYPE &&
			current_ie->instance == 0) {
			brc->rat_type = current_ie;
		} else if (current_ie->type == IE_SERVING_NETWORK &&
			current_ie->instance == 0) {
			brc->serving_network = current_ie;
		} else if (current_ie->type == IE_USER_LOCATION_INFORMATION &&
			current_ie->instance == 0) {
			brc->user_location_information = current_ie;
		} else if (current_ie->type == IE_EPS_BEARER_ID &&
			current_ie->instance == 1) {
			brc->eps_bearer_id = current_ie;
		} else if (current_ie->type == IE_INDICATION &&
			current_ie->instance == 0) {
			brc->indication_flags = current_ie;
		} else if (current_ie->type == IE_FULLY_QUALIFIED_TUNNEL_ENDPOINT_IDENTIFIER &&
			current_ie->instance == 0) {
			brc->s4_u_sgsn_f_teid = current_ie;
		} else if (current_ie->type == IE_FULLY_QUALIFIED_TUNNEL_ENDPOINT_IDENTIFIER &&
			current_ie->instance == 1) {
			brc->s12_rnc_f_teid = current_ie;
		} else if (current_ie->type == IE_PROTOCOL_CONFIGURATION_OPTIONS &&
			current_ie->instance == 0) {
			brc->protocol_configuration_options = current_ie;
		} else if (current_ie->type == IE_SIGNALLING_PRIORITY_INDICATION &&
			current_ie->instance == 0) {
			brc->signalling_priority_indication = current_ie;
		} else if (current_ie->type == IE_OVERLOAD_CONTROL_INFORMATION &&
			current_ie->instance == 0) {
			brc->mmes4_sgsn_overload_control_information = current_ie;
		} else if (current_ie->type == IE_OVERLOAD_CONTROL_INFORMATION &&
			current_ie->instance == 1) {
			brc->sgw_overload_control_information = current_ie;
		} else if (current_ie->type == IE_FULLY_QUALIFIED_CONTAINER &&
			current_ie->instance == 0) {
			brc->nbifom_container = current_ie;
		} else if (current_ie->type == IE_EXTENDED_PROTOCOL_CONFIGURATION_OPTIONS &&
			current_ie->instance == 0) {
			brc->extended_protocol_configuration_options_ = current_ie;
		} else if (current_ie->type == IE_FULLY_QUALIFIED_TUNNEL_ENDPOINT_IDENTIFIER &&
			current_ie->instance == 2) {
			brc->sender_f_teid_for_control_plane = current_ie;
		} else if (current_ie->type == IE_PRIVATE_EXTENSION) {
			brc->private_extension = current_ie;
		}

    }
    
	if (!brc->linked_eps_bearer_id
		|| !brc->procedure_transaction_id) {
		fprintf(stderr, "Dropping packet\n");
		return -EPERM;
	}

    return 0;
}

// TODO
static void
set_bearer_resource_command() {
    /* TODO */
}

int
process_bearer_resource_command(gtpv2c_header *gtpv2c_rx,
                               gtpv2c_header *gtpv2c_tx)
{
    /* TODO */
}
