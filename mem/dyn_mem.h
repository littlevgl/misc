/**
 * @file dyn_mem.h
 *
 */

#ifndef DYN_MEM_H
#define DYN_MEM_H

/*********************
 *      INCLUDES
 *********************/
#include "misc_conf.h"

#include <stdint.h>
#include <stddef.h>

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/
void dm_init(void);
void * dm_alloc(uint32_t size);
void dm_free(void  * data);
void * dm_realloc(void * data_p, uint32_t new_size);
uint32_t dm_get_size(void * p);

/**********************
 *      MACROS
 **********************/

#define dm_assert(p) {if(p == NULL) {while(1);}}

#endif

