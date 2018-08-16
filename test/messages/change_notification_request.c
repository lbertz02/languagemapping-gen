@copyright

#include <errno.h>

#include "packet_filters.h"
#include "gtpv2c_set_ie.h"
#include "../cp_dp_api/vepc_cp_dp_api.h"

/** Information Elements in change_notification_request */
struct parse_change_notification_request_t {
	gtpv2c_ie *imsi;
	gtpv2c_ie *me_identity;
	gtpv2c_ie *indication_flags;
	gtpv2c_ie *rat_type;
	gtpv2c_ie *user_location_information;
	gtpv2c_ie *user_csg_information;
	gtpv2c_ie *pgw_s5s8_gtp_c_ip_address;
	gtpv2c_ie *lbi;
	gtpv2c_ie *presence_reporting_area_information;
	gtpv2c_ie *mo_exception_data_counter;
	gtpv2c_ie *secondary_rat_usage_data_report;
	gtpv2c_ie *private_extension;
};

static int
parse_change_notification_request(gtpv2c_header *gtpv2c_rx,
          struct parse_change_notification_request_t *cnr)
{
    gtpv2c_ie *current_ie;
    gtpv2c_ie *current_group_ie;
    gtpv2c_ie *limit_ie;
    gtpv2c_ie *limit_group_ie;
    
    FOR_EACH_GTPV2C_IE(gtpv2c_rx, current_ie, limit_ie)
    {
		if (current_ie->type == IE_IMSI &&
			current_ie->instance == 0) {
			cnr->imsi = current_ie;
		} else if (current_ie->type == IE_MOBILE_EQUIPMENT_IDENTITY &&
			current_ie->instance == 0) {
			cnr->me_identity = current_ie;
		} else if (current_ie->type == IE_INDICATION &&
			current_ie->instance == 0) {
			cnr->indication_flags = current_ie;
		} else if (current_ie->type == IE_RAT_TYPE &&
			current_ie->instance == 0) {
			cnr->rat_type = current_ie;
		} else if (current_ie->type == IE_USER_LOCATION_INFORMATION &&
			current_ie->instance == 0) {
			cnr->user_location_information = current_ie;
		} else if (current_ie->type == IE_USER_CSG_INFORMATION &&
			current_ie->instance == 0) {
			cnr->user_csg_information = current_ie;
		} else if (current_ie->type == IE_IP_ADDRESS &&
			current_ie->instance == 0) {
			cnr->pgw_s5s8_gtp_c_ip_address = current_ie;
		} else if (current_ie->type == IE_EPS_BEARER_ID &&
			current_ie->instance == 0) {
			cnr->lbi = current_ie;
		} else if (current_ie->type == IE_PRESENCE_REPORTING_AREA_INFORMATION &&
			current_ie->instance == 0) {
			cnr->presence_reporting_area_information = current_ie;
		} else if (current_ie->type == IE_COUNTER &&
			current_ie->instance == 0) {
			cnr->mo_exception_data_counter = current_ie;
		} else if (current_ie->type == IE_SECONDARY_RAT_USAGE_DATA_REPORT &&
			current_ie->instance == 0) {
			cnr->secondary_rat_usage_data_report = current_ie;
		} else if (current_ie->type == IE_PRIVATE_EXTENSION) {
			cnr->private_extension = current_ie;
		}

    }
    
	if (!cnr->rat_type) {
		fprintf(stderr, "Dropping packet\n");
		return -EPERM;
	}

    return 0;
}

// TODO
static void
set_change_notification_request() {
    /* TODO */
}

int
process_change_notification_request(gtpv2c_header *gtpv2c_rx,
                               gtpv2c_header *gtpv2c_tx)
{
    /* TODO */
}
