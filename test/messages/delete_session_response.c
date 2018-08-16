@copyright

#include <errno.h>

#include "packet_filters.h"
#include "gtpv2c_set_ie.h"
#include "../cp_dp_api/vepc_cp_dp_api.h"

/** Information Elements in delete_session_response */
struct parse_delete_session_response_t {
	gtpv2c_ie *cause;
	gtpv2c_ie *recovery;
	gtpv2c_ie *protocol_configuration_options;
	gtpv2c_ie *indication_flags;
	gtpv2c_ie *pgw_node_level_load_control_information;
	gtpv2c_ie *pgw_apn_level_load_control_information;
	gtpv2c_ie *sgw_node_level_load_control_information;
	gtpv2c_ie *pgw_overload_control_information;
	gtpv2c_ie *sgw_overload_control_information;
	gtpv2c_ie *extended_protocol_configuration_options;
	gtpv2c_ie *private_extension;
};

static int
parse_delete_session_response(gtpv2c_header *gtpv2c_rx,
          struct parse_delete_session_response_t *dsr)
{
    gtpv2c_ie *current_ie;
    gtpv2c_ie *current_group_ie;
    gtpv2c_ie *limit_ie;
    gtpv2c_ie *limit_group_ie;
    
    FOR_EACH_GTPV2C_IE(gtpv2c_rx, current_ie, limit_ie)
    {
		if (current_ie->type == IE_CAUSE &&
			current_ie->instance == 0) {
			dsr->cause = current_ie;
		} else if (current_ie->type == IE_RECOVERY_RESTART_COUNTER &&
			current_ie->instance == 0) {
			dsr->recovery = current_ie;
		} else if (current_ie->type == IE_PROTOCOL_CONFIGURATION_OPTIONS &&
			current_ie->instance == 0) {
			dsr->protocol_configuration_options = current_ie;
		} else if (current_ie->type == IE_INDICATION &&
			current_ie->instance == 0) {
			dsr->indication_flags = current_ie;
		} else if (current_ie->type == IE_LOAD_CONTROL_INFORMATION &&
			current_ie->instance == 0) {
			dsr->pgw_node_level_load_control_information = current_ie;
		} else if (current_ie->type == IE_LOAD_CONTROL_INFORMATION &&
			current_ie->instance == 1) {
			dsr->pgw_apn_level_load_control_information = current_ie;
		} else if (current_ie->type == IE_LOAD_CONTROL_INFORMATION &&
			current_ie->instance == 2) {
			dsr->sgw_node_level_load_control_information = current_ie;
		} else if (current_ie->type == IE_OVERLOAD_CONTROL_INFORMATION &&
			current_ie->instance == 0) {
			dsr->pgw_overload_control_information = current_ie;
		} else if (current_ie->type == IE_OVERLOAD_CONTROL_INFORMATION &&
			current_ie->instance == 1) {
			dsr->sgw_overload_control_information = current_ie;
		} else if (current_ie->type == IE_EXTENDED_PROTOCOL_CONFIGURATION_OPTIONS &&
			current_ie->instance == 0) {
			dsr->extended_protocol_configuration_options = current_ie;
		} else if (current_ie->type == IE_PRIVATE_EXTENSION) {
			dsr->private_extension = current_ie;
		}

    }
    
	if (!dsr->cause) {
		fprintf(stderr, "Dropping packet\n");
		return -EPERM;
	}

    return 0;
}

// TODO
static void
set_delete_session_response() {
    /* TODO */
}

int
process_delete_session_response(gtpv2c_header *gtpv2c_rx,
                               gtpv2c_header *gtpv2c_tx)
{
    /* TODO */
}
