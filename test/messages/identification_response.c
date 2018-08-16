@copyright

#include <errno.h>

#include "packet_filters.h"
#include "gtpv2c_set_ie.h"
#include "../cp_dp_api/vepc_cp_dp_api.h"

/** Information Elements in identification_response */
struct parse_identification_response_t {
	gtpv2c_ie *cause;
	gtpv2c_ie *imsi;
	gtpv2c_ie *mmesgsn_ue_mm_context;
	gtpv2c_ie *trace_information;
	gtpv2c_ie *ue_usage_type;
	gtpv2c_ie *monitoring_event_information;
	gtpv2c_ie *private_extension;
};

static int
parse_identification_response(gtpv2c_header *gtpv2c_rx,
          struct parse_identification_response_t *ir)
{
    gtpv2c_ie *current_ie;
    gtpv2c_ie *current_group_ie;
    gtpv2c_ie *limit_ie;
    gtpv2c_ie *limit_group_ie;
    
    FOR_EACH_GTPV2C_IE(gtpv2c_rx, current_ie, limit_ie)
    {
		if (current_ie->type == IE_CAUSE &&
			current_ie->instance == 0) {
			ir->cause = current_ie;
		} else if (current_ie->type == IE_IMSI &&
			current_ie->instance == 0) {
			ir->imsi = current_ie;
		} else if (current_ie->type == IE_MM_CONTEXT &&
			current_ie->instance == 0) {
			ir->mmesgsn_ue_mm_context = current_ie;
		} else if (current_ie->type == IE_TRACE_INFORMATION &&
			current_ie->instance == 0) {
			ir->trace_information = current_ie;
		} else if (current_ie->type == IE_INTEGER_NUMBER &&
			current_ie->instance == 0) {
			ir->ue_usage_type = current_ie;
		} else if (current_ie->type == IE_MONITORING_EVENT_INFORMATION &&
			current_ie->instance == 0) {
			ir->monitoring_event_information = current_ie;
		} else if (current_ie->type == IE_PRIVATE_EXTENSION) {
			ir->private_extension = current_ie;
		}

    }
    
	if (!ir->cause) {
		fprintf(stderr, "Dropping packet\n");
		return -EPERM;
	}

    return 0;
}

// TODO
static void
set_identification_response() {
    /* TODO */
}

int
process_identification_response(gtpv2c_header *gtpv2c_rx,
                               gtpv2c_header *gtpv2c_tx)
{
    /* TODO */
}
