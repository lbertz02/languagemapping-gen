@copyright

#include <errno.h>

#include "packet_filters.h"
#include "gtpv2c_set_ie.h"
#include "../cp_dp_api/vepc_cp_dp_api.h"

/** Information Elements in trace_session_deactivation */
struct parse_trace_session_deactivation_t {
	gtpv2c_ie *trace_reference;
};

static int
parse_trace_session_deactivation(gtpv2c_header *gtpv2c_rx,
          struct parse_trace_session_deactivation_t *tsd)
{
    gtpv2c_ie *current_ie;
    gtpv2c_ie *current_group_ie;
    gtpv2c_ie *limit_ie;
    gtpv2c_ie *limit_group_ie;
    
    FOR_EACH_GTPV2C_IE(gtpv2c_rx, current_ie, limit_ie)
    {
		if (current_ie->type == IE_TRACE_REFERENCE &&
			current_ie->instance == 0) {
			tsd->trace_reference = current_ie;
		}

    }
    
	if (!tsd->trace_reference) {
		fprintf(stderr, "Dropping packet\n");
		return -EPERM;
	}

    return 0;
}

// TODO
static void
set_trace_session_deactivation() {
    /* TODO */
}

int
process_trace_session_deactivation(gtpv2c_header *gtpv2c_rx,
                               gtpv2c_header *gtpv2c_tx)
{
    /* TODO */
}
