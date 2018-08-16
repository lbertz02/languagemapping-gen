@copyright

#include <errno.h>

#include "packet_filters.h"
#include "gtpv2c_set_ie.h"
#include "../cp_dp_api/vepc_cp_dp_api.h"

/** Information Elements in forward_access_context_notification */
struct parse_forward_access_context_notification_t {
	gtpv2c_ie *rab_context;
	gtpv2c_ie *source_rnc_pdcp_context_info;
	gtpv2c_ie *pdu_numbers;
	gtpv2c_ie *e_utran_transparent_container;
	gtpv2c_ie *private_extension;
};

static int
parse_forward_access_context_notification(gtpv2c_header *gtpv2c_rx,
          struct parse_forward_access_context_notification_t *facn)
{
    gtpv2c_ie *current_ie;
    gtpv2c_ie *current_group_ie;
    gtpv2c_ie *limit_ie;
    gtpv2c_ie *limit_group_ie;
    
    FOR_EACH_GTPV2C_IE(gtpv2c_rx, current_ie, limit_ie)
    {
		if (current_ie->type == IE_RAB_CONTEXT &&
			current_ie->instance == 0) {
			facn->rab_context = current_ie;
		} else if (current_ie->type == IE_SOURCE_RNC_PDCP_CONTEXT_INFO &&
			current_ie->instance == 0) {
			facn->source_rnc_pdcp_context_info = current_ie;
		} else if (current_ie->type == IE_PDU_NUMBERS &&
			current_ie->instance == 0) {
			facn->pdu_numbers = current_ie;
		} else if (current_ie->type == IE_FULLY_QUALIFIED_CONTAINER &&
			current_ie->instance == 0) {
			facn->e_utran_transparent_container = current_ie;
		} else if (current_ie->type == IE_PRIVATE_EXTENSION) {
			facn->private_extension = current_ie;
		}

    }
    

    return 0;
}

// TODO
static void
set_forward_access_context_notification() {
    /* TODO */
}

int
process_forward_access_context_notification(gtpv2c_header *gtpv2c_rx,
                               gtpv2c_header *gtpv2c_tx)
{
    /* TODO */
}
