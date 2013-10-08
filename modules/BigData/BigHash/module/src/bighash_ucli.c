/****************************************************************
 * 
 *        Copyright 2013, Big Switch Networks, Inc. 
 * 
 * Licensed under the Eclipse Public License, Version 1.0 (the
 * "License"); you may not use this file except in compliance
 * with the License. You may obtain a copy of the License at
 * 
 *        http://www.eclipse.org/legal/epl-v10.html
 * 
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific
 * language governing permissions and limitations under the
 * License.
 * 
 ***************************************************************/
/**************************************************************************//**
 * 
 * 
 * 
 *****************************************************************************/
#include <BigHash/bighash_config.h>

#if BIGHASH_CONFIG_INCLUDE_UCLI == 1

#include <uCli/ucli.h>
#include <uCli/ucli_argparse.h>
#include <uCli/ucli_handler_macros.h>

static ucli_status_t 
bighash_ucli_ucli__config__(ucli_context_t* uc)
{
    UCLI_HANDLER_MACRO_MODULE_CONFIG(bighash)
}

/* <auto.ucli.handlers.start> */
/* <auto.ucli.handlers.end> */

static ucli_module_t
bighash_ucli_module__ = 
    {
        "bighash_ucli", 
        NULL,  
        bighash_ucli_ucli_handlers__, 
        NULL, 
        NULL, 
    };

ucli_node_t*
bighash_ucli_node_create(void)
{
    ucli_node_t* n; 
    ucli_module_init(&bighash_ucli_module__); 
    n = ucli_node_create("bighash", NULL, &bighash_ucli_module__); 
    ucli_node_subnode_add(n, ucli_module_log_node_create("bighash")); 
    return n; 
}

#else
void*
bighash_ucli_node_create(void)
{
    return NULL; 
}
#endif

