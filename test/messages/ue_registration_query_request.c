@copyright

#include <errno.h>

#include "packet_filters.h"
#include "gtpv2c_set_ie.h"
#include "../cp_dp_api/vepc_cp_dp_api.h"

/** Information Elements in ue_registration_query_request */
struct parse_ue_registration_query_request_t {
	gtpv2c_ie *imsi;
	gtpv2c_ie *private_extension;
};

static int
parse_ue_registration_query_request(gtpv2c_header *gtpv2c_rx,
          struct parse_ue_registration_query_request_t *urqr)
{
    gtpv2c_ie *current_ie;
    gtpv2c_ie *current_group_ie;
    gtpv2c_ie *limit_ie;
    gtpv2c_ie *limit_group_ie;
    
    FOR_EACH_GTPV2C_IE(gtpv2c_rx, current_ie, limit_ie)
    {
		if (current_ie->type == IE_IMSI &&
			current_ie->instance == 0) {
			urqr->imsi = current_ie;
		} else if (current_ie->type == IE_PRIVATE_EXTENSION) {
			urqr->private_extension = current_ie;
		}

    }
    
	if (!urqr->imsi) {
		fprintf(stderr, "Dropping packet\n");
		return -EPERM;
	}

    return 0;
}

// TODO
static void
set_ue_registration_query_request() {
    /* TODO */
}

int
process_ue_registration_query_request(gtpv2c_header *gtpv2c_rx,
                               gtpv2c_header *gtpv2c_tx)
{
    /* TODO */
}
