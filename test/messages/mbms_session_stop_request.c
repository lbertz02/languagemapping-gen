@copyright

#include <errno.h>

#include "packet_filters.h"
#include "gtpv2c_set_ie.h"
#include "../cp_dp_api/vepc_cp_dp_api.h"

/** Information Elements in mbms_session_stop_request */
struct parse_mbms_session_stop_request_t {
	gtpv2c_ie *mbms_flow_identifier;
	gtpv2c_ie *mbms_data_transfer_stop;
	gtpv2c_ie *mbms_flags;
	gtpv2c_ie *private_extension;
};

static int
parse_mbms_session_stop_request(gtpv2c_header *gtpv2c_rx,
          struct parse_mbms_session_stop_request_t *mssr)
{
    gtpv2c_ie *current_ie;
    gtpv2c_ie *current_group_ie;
    gtpv2c_ie *limit_ie;
    gtpv2c_ie *limit_group_ie;
    
    FOR_EACH_GTPV2C_IE(gtpv2c_rx, current_ie, limit_ie)
    {
		if (current_ie->type == IE_MBMS_FLOW_IDENTIFIER &&
			current_ie->instance == 0) {
			mssr->mbms_flow_identifier = current_ie;
		} else if (current_ie->type == IE_ABSOLUTE_TIME_OF_MBMS_DATA_TRANSFER &&
			current_ie->instance == 0) {
			mssr->mbms_data_transfer_stop = current_ie;
		} else if (current_ie->type == IE_MBMS_FLAGS &&
			current_ie->instance == 0) {
			mssr->mbms_flags = current_ie;
		} else if (current_ie->type == IE_PRIVATE_EXTENSION) {
			mssr->private_extension = current_ie;
		}

    }
    

    return 0;
}

// TODO
static void
set_mbms_session_stop_request() {
    /* TODO */
}

int
process_mbms_session_stop_request(gtpv2c_header *gtpv2c_rx,
                               gtpv2c_header *gtpv2c_tx)
{
    /* TODO */
}
