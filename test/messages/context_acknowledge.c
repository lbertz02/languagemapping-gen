@copyright

#include <errno.h>

#include "packet_filters.h"
#include "gtpv2c_set_ie.h"
#include "../cp_dp_api/vepc_cp_dp_api.h"

/** Information Elements in context_acknowledge */
struct parse_context_acknowledge_t {
	gtpv2c_ie *cause;
	gtpv2c_ie *indication_flags;
	gtpv2c_ie *forwarding_f_teid;
	gtpv2c_ie *bearer_context;
	gtpv2c_ie *sgsn_number;
	gtpv2c_ie *mme_number_for_mt_sms;
	gtpv2c_ie *sgsn_identifier_for_mt_sms;
	gtpv2c_ie *mme_identifier_for_mt_sms;
	gtpv2c_ie *private_extension;
};

static int
parse_context_acknowledge(gtpv2c_header *gtpv2c_rx,
          struct parse_context_acknowledge_t *ca)
{
    gtpv2c_ie *current_ie;
    gtpv2c_ie *current_group_ie;
    gtpv2c_ie *limit_ie;
    gtpv2c_ie *limit_group_ie;
    
    FOR_EACH_GTPV2C_IE(gtpv2c_rx, current_ie, limit_ie)
    {
		if (current_ie->type == IE_CAUSE &&
			current_ie->instance == 0) {
			ca->cause = current_ie;
		} else if (current_ie->type == IE_INDICATION &&
			current_ie->instance == 0) {
			ca->indication_flags = current_ie;
		} else if (current_ie->type == IE_FULLY_QUALIFIED_TUNNEL_ENDPOINT_IDENTIFIER &&
			current_ie->instance == 0) {
			ca->forwarding_f_teid = current_ie;
		} else if (current_ie->type == IE_BEARER_CONTEXT &&
			current_ie->instance == 0) {
			ca->bearer_context = current_ie;
		} else if (current_ie->type == IE_NODE_NUMBER &&
			current_ie->instance == 0) {
			ca->sgsn_number = current_ie;
		} else if (current_ie->type == IE_NODE_NUMBER &&
			current_ie->instance == 1) {
			ca->mme_number_for_mt_sms = current_ie;
		} else if (current_ie->type == IE_NODE_IDENTIFIER &&
			current_ie->instance == 0) {
			ca->sgsn_identifier_for_mt_sms = current_ie;
		} else if (current_ie->type == IE_NODE_IDENTIFIER &&
			current_ie->instance == 1) {
			ca->mme_identifier_for_mt_sms = current_ie;
		} else if (current_ie->type == IE_PRIVATE_EXTENSION) {
			ca->private_extension = current_ie;
		}

    }
    
	if (!ca->cause) {
		fprintf(stderr, "Dropping packet\n");
		return -EPERM;
	}

    return 0;
}

// TODO
static void
set_context_acknowledge() {
    /* TODO */
}

int
process_context_acknowledge(gtpv2c_header *gtpv2c_rx,
                               gtpv2c_header *gtpv2c_tx)
{
    /* TODO */
}
