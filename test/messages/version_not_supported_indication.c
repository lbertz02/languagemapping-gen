@copyright

#include <errno.h>

#include "packet_filters.h"
#include "gtpv2c_set_ie.h"
#include "../cp_dp_api/vepc_cp_dp_api.h"

/** Information Elements in version_not_supported_indication */
struct parse_version_not_supported_indication_t {
	
};

static int
parse_version_not_supported_indication(gtpv2c_header *gtpv2c_rx,
          struct parse_version_not_supported_indication_t *vnsi)
{
    gtpv2c_ie *current_ie;
    gtpv2c_ie *current_group_ie;
    gtpv2c_ie *limit_ie;
    gtpv2c_ie *limit_group_ie;
    
    FOR_EACH_GTPV2C_IE(gtpv2c_rx, current_ie, limit_ie)
    {
		

    }
    

    return 0;
}

// TODO
static void
set_version_not_supported_indication() {
    /* TODO */
}

int
process_version_not_supported_indication(gtpv2c_header *gtpv2c_rx,
                               gtpv2c_header *gtpv2c_tx)
{
    /* TODO */
}
