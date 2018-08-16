@copyright

#include <errno.h>

#include "packet_filters.h"
#include "gtpv2c_set_ie.h"
#include "../cp_dp_api/vepc_cp_dp_api.h"

/** Information Elements in bearer_resource_failure_indication */
struct parse_bearer_resource_failure_indication_t {
	gtpv2c_ie *cause;
	gtpv2c_ie *linked_eps_bearer_id;
	gtpv2c_ie *procedure_transaction_id;
	gtpv2c_ie *indication_flags;
	gtpv2c_ie *pgw_overload_control_information;
	gtpv2c_ie *sgwoverload_control_information;
	gtpv2c_ie *recovery;
	gtpv2c_ie *nbifom_container;
	gtpv2c_ie *private_extension;
};

static int
parse_bearer_resource_failure_indication(gtpv2c_header *gtpv2c_rx,
          struct parse_bearer_resource_failure_indication_t *brfi)
{
    gtpv2c_ie *current_ie;
    gtpv2c_ie *current_group_ie;
    gtpv2c_ie *limit_ie;
    gtpv2c_ie *limit_group_ie;
    
    FOR_EACH_GTPV2C_IE(gtpv2c_rx, current_ie, limit_ie)
    {
		if (current_ie->type == IE_CAUSE &&
			current_ie->instance == 0) {
			brfi->cause = current_ie;
		} else if (current_ie->type == IE_EPS_BEARER_ID &&
			current_ie->instance == 0) {
			brfi->linked_eps_bearer_id = current_ie;
		} else if (current_ie->type == IE_PROCEDURE_TRANSACTION_ID &&
			current_ie->instance == 0) {
			brfi->procedure_transaction_id = current_ie;
		} else if (current_ie->type == IE_INDICATION &&
			current_ie->instance == 0) {
			brfi->indication_flags = current_ie;
		} else if (current_ie->type == IE_OVERLOAD_CONTROL_INFORMATION &&
			current_ie->instance == 0) {
			brfi->pgw_overload_control_information = current_ie;
		} else if (current_ie->type == IE_OVERLOAD_CONTROL_INFORMATION &&
			current_ie->instance == 1) {
			brfi->sgwoverload_control_information = current_ie;
		} else if (current_ie->type == IE_RECOVERY_RESTART_COUNTER &&
			current_ie->instance == 0) {
			brfi->recovery = current_ie;
		} else if (current_ie->type == IE_FULLY_QUALIFIED_CONTAINER &&
			current_ie->instance == 0) {
			brfi->nbifom_container = current_ie;
		} else if (current_ie->type == IE_PRIVATE_EXTENSION) {
			brfi->private_extension = current_ie;
		}

    }
    
	if (!brfi->cause
		|| !brfi->linked_eps_bearer_id
		|| !brfi->procedure_transaction_id) {
		fprintf(stderr, "Dropping packet\n");
		return -EPERM;
	}

    return 0;
}

// TODO
static void
set_bearer_resource_failure_indication() {
    /* TODO */
}

int
process_bearer_resource_failure_indication(gtpv2c_header *gtpv2c_rx,
                               gtpv2c_header *gtpv2c_tx)
{
    /* TODO */
}
