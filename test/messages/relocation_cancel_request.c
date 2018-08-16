@copyright

#include <errno.h>

#include "packet_filters.h"
#include "gtpv2c_set_ie.h"
#include "../cp_dp_api/vepc_cp_dp_api.h"

/** Information Elements in relocation_cancel_request */
struct parse_relocation_cancel_request_t {
	gtpv2c_ie *imsi;
	gtpv2c_ie *me_identity;
	gtpv2c_ie *indication_flags;
	gtpv2c_ie *ranap_cause;
	gtpv2c_ie *private_extension;
};

static int
parse_relocation_cancel_request(gtpv2c_header *gtpv2c_rx,
          struct parse_relocation_cancel_request_t *rcr)
{
    gtpv2c_ie *current_ie;
    gtpv2c_ie *current_group_ie;
    gtpv2c_ie *limit_ie;
    gtpv2c_ie *limit_group_ie;
    
    FOR_EACH_GTPV2C_IE(gtpv2c_rx, current_ie, limit_ie)
    {
		if (current_ie->type == IE_IMSI &&
			current_ie->instance == 0) {
			rcr->imsi = current_ie;
		} else if (current_ie->type == IE_MOBILE_EQUIPMENT_IDENTITY &&
			current_ie->instance == 0) {
			rcr->me_identity = current_ie;
		} else if (current_ie->type == IE_INDICATION &&
			current_ie->instance == 0) {
			rcr->indication_flags = current_ie;
		} else if (current_ie->type == IE_FULLY_QUALIFIED_CAUSE &&
			current_ie->instance == 0) {
			rcr->ranap_cause = current_ie;
		} else if (current_ie->type == IE_PRIVATE_EXTENSION) {
			rcr->private_extension = current_ie;
		}

    }
    

    return 0;
}

// TODO
static void
set_relocation_cancel_request() {
    /* TODO */
}

int
process_relocation_cancel_request(gtpv2c_header *gtpv2c_rx,
                               gtpv2c_header *gtpv2c_tx)
{
    /* TODO */
}
