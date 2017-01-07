/**
 * @file dyn_mem.h
 *
 */

#ifndef _DYN_MEM_CUST_H_
#define _DYN_MEM_CUST_H_

/*********************
 *      INCLUDES
 *********************/

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

struct mem_cust_t {
	uint32_t size;
	struct mem_cust_t *next;
	struct mem_cust_t *prev;
	void *memptr;
};

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**********************
 *      MACROS
 **********************/

#endif /* _DYN_MEM_CUST_H_ */
