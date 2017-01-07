/**
 * @file dyn_mem_simple.h
 *
 */

#ifndef DYN_MEM_SIMPLE_H
#define DYN_MEM_SIMPLE_H

/*********************
 *      INCLUDES
 *********************/
#include "misc_conf.h"
#if USE_DYN_MEM_SIMPLE != 0

#include <stdint.h>
#include <stddef.h>

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

typedef struct
{
    uint32_t cnt_free;
    uint32_t cnt_used;
    uint32_t size_free;
    uint32_t size_free_big;
    uint32_t pct_frag;
}dm_mon_t;


/**********************
 * GLOBAL PROTOTYPES
 **********************/
void dm_defrag(void);
void dm_monitor(dm_mon_t * mon_p);

/**********************
 *      MACROS
 **********************/

#endif /* USE_DYN_MEM_SIMPLE != 0 */
#endif
