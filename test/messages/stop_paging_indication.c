@copyright

#include <errno.h>

#include "packet_filters.h"
#include "gtpv2c_set_ie.h"
#include "../cp_dp_api/vepc_cp_dp_api.h"

/** Information Elements in stop_paging_indication */
struct parse_stop_paging_indication_t {
	gtpv2c_ie *imsi;
	gtpv2c_ie *private_extension;
};

static int
parse_stop_paging_indication(gtpv2c_header *gtpv2c_rx,
          struct parse_stop_paging_indication_t *spi)
{
    gtpv2c_ie *current_ie;
    gtpv2c_ie *current_group_ie;
    gtpv2c_ie *limit_ie;
    gtpv2c_ie *limit_group_ie;
    
    FOR_EACH_GTPV2C_IE(gtpv2c_rx, current_ie, limit_ie)
    {
		if (current_ie->type == IE_IMSI &&
			current_ie->instance == 0) {
			spi->imsi = current_ie;
		} else if (current_ie->type == IE_PRIVATE_EXTENSION) {
			spi->private_extension = current_ie;
		}

    }
    

    return 0;
}

// TODO
static void
set_stop_paging_indication() {
    /* TODO */
}

int
process_stop_paging_indication(gtpv2c_header *gtpv2c_rx,
                               gtpv2c_header *gtpv2c_tx)
{
    /* TODO */
}
