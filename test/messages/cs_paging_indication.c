@copyright

#include <errno.h>

#include "packet_filters.h"
#include "gtpv2c_set_ie.h"
#include "../cp_dp_api/vepc_cp_dp_api.h"

/** Information Elements in cs_paging_indication */
struct parse_cs_paging_indication_t {
	gtpv2c_ie *imsi;
	gtpv2c_ie *vlr_name;
	gtpv2c_ie *tmsi;
	gtpv2c_ie *location_area_identifier;
	gtpv2c_ie *global_cn_id;
	gtpv2c_ie *channel_needed;
	gtpv2c_ie *emlpp_priority;
	gtpv2c_ie *service_indicator;
	gtpv2c_ie *private_extension;
};

static int
parse_cs_paging_indication(gtpv2c_header *gtpv2c_rx,
          struct parse_cs_paging_indication_t *cpi)
{
    gtpv2c_ie *current_ie;
    gtpv2c_ie *current_group_ie;
    gtpv2c_ie *limit_ie;
    gtpv2c_ie *limit_group_ie;
    
    FOR_EACH_GTPV2C_IE(gtpv2c_rx, current_ie, limit_ie)
    {
		if (current_ie->type == IE_IMSI &&
			current_ie->instance == 0) {
			cpi->imsi = current_ie;
		} else if (current_ie->type == IE_FULLY_QUALIFIED_DOMAIN_NAME &&
			current_ie->instance == 0) {
			cpi->vlr_name = current_ie;
		} else if (current_ie->type == IE_TMSI &&
			current_ie->instance == 0) {
			cpi->tmsi = current_ie;
		} else if (current_ie->type == IE_USER_LOCATION_INFORMATION &&
			current_ie->instance == 0) {
			cpi->location_area_identifier = current_ie;
		} else if (current_ie->type == IE_GLOBAL_CN_ID &&
			current_ie->instance == 0) {
			cpi->global_cn_id = current_ie;
		} else if (current_ie->type == IE_CHANNEL_NEEDED &&
			current_ie->instance == 0) {
			cpi->channel_needed = current_ie;
		} else if (current_ie->type == IE_EMLPP_PRIORITY &&
			current_ie->instance == 0) {
			cpi->emlpp_priority = current_ie;
		} else if (current_ie->type == IE_SERVICE_INDICATOR &&
			current_ie->instance == 0) {
			cpi->service_indicator = current_ie;
		} else if (current_ie->type == IE_PRIVATE_EXTENSION) {
			cpi->private_extension = current_ie;
		}

    }
    
	if (!cpi->imsi
		|| !cpi->vlr_name) {
		fprintf(stderr, "Dropping packet\n");
		return -EPERM;
	}

    return 0;
}

// TODO
static void
set_cs_paging_indication() {
    /* TODO */
}

int
process_cs_paging_indication(gtpv2c_header *gtpv2c_rx,
                               gtpv2c_header *gtpv2c_tx)
{
    /* TODO */
}
