@copyright

#include <errno.h>

#include "packet_filters.h"
#include "gtpv2c_set_ie.h"
#include "../cp_dp_api/vepc_cp_dp_api.h"

/** Information Elements in update_pdn_connection_set_request */
struct parse_update_pdn_connection_set_request_t {
	gtpv2c_ie *mme_fq_csid;
	gtpv2c_ie *sgw_fq_csid;
	gtpv2c_ie *private_extension;
};

static int
parse_update_pdn_connection_set_request(gtpv2c_header *gtpv2c_rx,
          struct parse_update_pdn_connection_set_request_t *upcsr)
{
    gtpv2c_ie *current_ie;
    gtpv2c_ie *current_group_ie;
    gtpv2c_ie *limit_ie;
    gtpv2c_ie *limit_group_ie;
    
    FOR_EACH_GTPV2C_IE(gtpv2c_rx, current_ie, limit_ie)
    {
		if (current_ie->type == IE_FQ_CSID &&
			current_ie->instance == 0) {
			upcsr->mme_fq_csid = current_ie;
		} else if (current_ie->type == IE_FQ_CSID &&
			current_ie->instance == 1) {
			upcsr->sgw_fq_csid = current_ie;
		} else if (current_ie->type == IE_PRIVATE_EXTENSION) {
			upcsr->private_extension = current_ie;
		}

    }
    

    return 0;
}

// TODO
static void
set_update_pdn_connection_set_request() {
    /* TODO */
}

int
process_update_pdn_connection_set_request(gtpv2c_header *gtpv2c_rx,
                               gtpv2c_header *gtpv2c_tx)
{
    /* TODO */
}
