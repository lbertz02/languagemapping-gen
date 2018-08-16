@copyright

#include <errno.h>

#include "packet_filters.h"
#include "gtpv2c_set_ie.h"
#include "../cp_dp_api/vepc_cp_dp_api.h"

/** Information Elements in release_access_bearers_request */
struct parse_release_access_bearers_request_t {
	gtpv2c_ie *list_of_rabs;
	gtpv2c_ie *originating_node;
	gtpv2c_ie *indication_flags;
	gtpv2c_ie *secondary_rat_usage_data_report;
	gtpv2c_ie *private_extension;
};

static int
parse_release_access_bearers_request(gtpv2c_header *gtpv2c_rx,
          struct parse_release_access_bearers_request_t *rabr)
{
    gtpv2c_ie *current_ie;
    gtpv2c_ie *current_group_ie;
    gtpv2c_ie *limit_ie;
    gtpv2c_ie *limit_group_ie;
    
    FOR_EACH_GTPV2C_IE(gtpv2c_rx, current_ie, limit_ie)
    {
		if (current_ie->type == IE_EPS_BEARER_ID &&
			current_ie->instance == 0) {
			rabr->list_of_rabs = current_ie;
		} else if (current_ie->type == IE_NODE_TYPE &&
			current_ie->instance == 0) {
			rabr->originating_node = current_ie;
		} else if (current_ie->type == IE_INDICATION &&
			current_ie->instance == 0) {
			rabr->indication_flags = current_ie;
		} else if (current_ie->type == IE_SECONDARY_RAT_USAGE_DATA_REPORT &&
			current_ie->instance == 0) {
			rabr->secondary_rat_usage_data_report = current_ie;
		} else if (current_ie->type == IE_PRIVATE_EXTENSION) {
			rabr->private_extension = current_ie;
		}

    }
    

    return 0;
}

// TODO
static void
set_release_access_bearers_request() {
    /* TODO */
}

int
process_release_access_bearers_request(gtpv2c_header *gtpv2c_rx,
                               gtpv2c_header *gtpv2c_tx)
{
    /* TODO */
}
