/*
ZZZ
 * Copyright (c) 2017 Intel Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#include <errno.h>
#include "packet_filters.h"
#include "gtpv2c_set_ie.h"
#include "../cp_dp_api/vepc_cp_dp_api.h"
/** Information Elements in AAA */
struct parse_AAA_t {
BBB
};
static int
parse_AAA(gtpv2c_header *gtpv2c_rx,
          struct parse_AAA_t *VVV)
{
    gtpv2c_ie *current_ie;
    gtpv2c_ie *current_group_ie;
    gtpv2c_ie *limit_ie;
    gtpv2c_ie *limit_group_ie;
    
    FOR_EACH_GTPV2C_IE(gtpv2c_rx, current_ie, limit_ie)
    {
CCC
    }
    
DDD
    return 0;
}
// TODO
static void
set_AAA() {
    /* TODO */
}
int
process_AAA(gtpv2c_header *gtpv2c_rx,
                               gtpv2c_header *gtpv2c_tx)
{
    /* TODO */
}
