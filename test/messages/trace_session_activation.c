@copyright

#include <errno.h>

#include "packet_filters.h"
#include "gtpv2c_set_ie.h"
#include "../cp_dp_api/vepc_cp_dp_api.h"

/** Information Elements in trace_session_activation */
struct parse_trace_session_activation_t {
	gtpv2c_ie *imsi;
	gtpv2c_ie *trace_information;
	gtpv2c_ie *me_identity;
};

static int
parse_trace_session_activation(gtpv2c_header *gtpv2c_rx,
          struct parse_trace_session_activation_t *tsa)
{
    gtpv2c_ie *current_ie;
    gtpv2c_ie *current_group_ie;
    gtpv2c_ie *limit_ie;
    gtpv2c_ie *limit_group_ie;
    
    FOR_EACH_GTPV2C_IE(gtpv2c_rx, current_ie, limit_ie)
    {
		if (current_ie->type == IE_IMSI &&
			current_ie->instance == 0) {
			tsa->imsi = current_ie;
		} else if (current_ie->type == IE_TRACE_INFORMATION &&
			current_ie->instance == 0) {
			tsa->trace_information = current_ie;
		} else if (current_ie->type == IE_MOBILE_EQUIPMENT_IDENTITY &&
			current_ie->instance == 0) {
			tsa->me_identity = current_ie;
		}

    }
    
	if (!tsa->trace_information) {
		fprintf(stderr, "Dropping packet\n");
		return -EPERM;
	}

    return 0;
}

// TODO
static void
set_trace_session_activation() {
    /* TODO */
}

int
process_trace_session_activation(gtpv2c_header *gtpv2c_rx,
                               gtpv2c_header *gtpv2c_tx)
{
    /* TODO */
}
