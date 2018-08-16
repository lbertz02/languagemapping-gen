@copyright

#include <errno.h>

#include "packet_filters.h"
#include "gtpv2c_set_ie.h"
#include "../cp_dp_api/vepc_cp_dp_api.h"

/** Information Elements in change_notification_response */
struct parse_change_notification_response_t {
	gtpv2c_ie *imsi;
	gtpv2c_ie *me_identity;
	gtpv2c_ie *cause;
	gtpv2c_ie *change_reporting_action;
	gtpv2c_ie *csg_information_reporting_action;
	gtpv2c_ie *presence_reporting_area_action;
	gtpv2c_ie *private_extension;
};

static int
parse_change_notification_response(gtpv2c_header *gtpv2c_rx,
          struct parse_change_notification_response_t *cnr)
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
		} else if (current_ie->type == IE_CAUSE &&
			current_ie->instance == 0) {
			cnr->cause = current_ie;
		} else if (current_ie->type == IE_CHANGE_REPORTING_ACTION &&
			current_ie->instance == 0) {
			cnr->change_reporting_action = current_ie;
		} else if (current_ie->type == IE_CSG_REPORTING_ACTION &&
			current_ie->instance == 0) {
			cnr->csg_information_reporting_action = current_ie;
		} else if (current_ie->type == IE_PRESENCE_REPORTING_AREA_ACTION &&
			current_ie->instance == 0) {
			cnr->presence_reporting_area_action = current_ie;
		} else if (current_ie->type == IE_PRIVATE_EXTENSION) {
			cnr->private_extension = current_ie;
		}

    }
    
	if (!cnr->cause) {
		fprintf(stderr, "Dropping packet\n");
		return -EPERM;
	}

    return 0;
}

// TODO
static void
set_change_notification_response() {
    /* TODO */
}

int
process_change_notification_response(gtpv2c_header *gtpv2c_rx,
                               gtpv2c_header *gtpv2c_tx)
{
    /* TODO */
}
