@copyright

#include <errno.h>

#include "packet_filters.h"
#include "gtpv2c_set_ie.h"
#include "../cp_dp_api/vepc_cp_dp_api.h"

/** Information Elements in ue_registration_query_response */
struct parse_ue_registration_query_response_t {
	gtpv2c_ie *cause;
	gtpv2c_ie *imsi;
	gtpv2c_ie *selected_core_network_operator_identifier;
	gtpv2c_ie *private_extension;
};

static int
parse_ue_registration_query_response(gtpv2c_header *gtpv2c_rx,
          struct parse_ue_registration_query_response_t *urqr)
{
    gtpv2c_ie *current_ie;
    gtpv2c_ie *current_group_ie;
    gtpv2c_ie *limit_ie;
    gtpv2c_ie *limit_group_ie;
    
    FOR_EACH_GTPV2C_IE(gtpv2c_rx, current_ie, limit_ie)
    {
		if (current_ie->type == IE_CAUSE &&
			current_ie->instance == 0) {
			urqr->cause = current_ie;
		} else if (current_ie->type == IE_IMSI &&
			current_ie->instance == 0) {
			urqr->imsi = current_ie;
		} else if (current_ie->type == IE_PLMN_ID &&
			current_ie->instance == 0) {
			urqr->selected_core_network_operator_identifier = current_ie;
		} else if (current_ie->type == IE_PRIVATE_EXTENSION) {
			urqr->private_extension = current_ie;
		}

    }
    
	if (!urqr->cause
		|| !urqr->imsi
		|| !urqr->selected_core_network_operator_identifier) {
		fprintf(stderr, "Dropping packet\n");
		return -EPERM;
	}

    return 0;
}

// TODO
static void
set_ue_registration_query_response() {
    /* TODO */
}

int
process_ue_registration_query_response(gtpv2c_header *gtpv2c_rx,
                               gtpv2c_header *gtpv2c_tx)
{
    /* TODO */
}
