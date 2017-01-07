/*
 * @file dyn_mem_cust.c
 * Memory allocation function for system with custom malloc
 * and free functions.
 *
 * Standard functions does not provide some features needed by
 * lvgl.
 */

#include "misc_conf.h"
#if USE_DYN_MEM_CUST != 0

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "../math/math_base.h"
#include "dyn_mem_cust.h"

/* Define custom function for MEM_MALLOC and MEM_FREE */
#ifndef MEM_MALLOC
#define MEM_MALLOC	malloc
#endif

#ifndef MEM_FREE
#define MEM_FREE	free
#endif

static struct mem_cust_t *memlist = NULL;
static struct mem_cust_t *memcurr = NULL;

/*
 * Noting to initialize
 */
void dm_init(void)
{
}

/**
 * Allocate a memory dynamically
 * @param size size of the memory to allocate in bytes
 * @return pointer to the allocated memory 
 */
void * dm_alloc(uint32_t size)
{
	struct mem_cust_t *info;

	info = MEM_MALLOC(sizeof(*info) + size);
	if (!info)
		return NULL;

	memset(info, 0, sizeof(*info));
	info->size = size;
	info->memptr = (void *)((size_t)info + sizeof(*info));

#if DM_AUTO_ZERO != 0
	memset(info->memptr, 0, size);
#endif
	if (memlist == NULL) {
		/* First allocation */
		memlist = info;
		memcurr = info;
	} else {
		/* Add to list */
		info->prev = memcurr;
		memcurr->next = info;
		memcurr = info;
	}

	return info->memptr;
}

/**
 * Free an allocated data
 * @param data pointer to an allocated memory 
 */
void dm_free(void * data)
{
	if (!data)
		return;

	struct mem_cust_t *ptr;
	struct mem_cust_t *prev;

	ptr = (struct mem_cust_t *) ((size_t) data - sizeof(*ptr));

	/* delete from list */
	/* check if its head */
	if (ptr == memlist) {
		/* move ahead */
		memlist = ptr->next;
		memlist->prev = NULL;
	} else {
		prev = ptr->prev;
		prev->next = ptr->next;
		if (ptr == memcurr)
			memcurr = prev;
	}
	MEM_FREE(ptr);
}

/**
 * Give the size of an allocated memory
 * @param data pointer to an allocated memory
 * @return the size of data memory in bytes
 */
uint32_t dm_get_size(void * data)
{
	if (!data)
		return 0;

	struct mem_cust_t *ptr;

	ptr = (struct mem_cust_t *) ((size_t) data - sizeof(*ptr));

	return ptr->size;
}

/**
 * Reallocate a memory with a new size. The old content will be kept.
 * @param data pointer to an allocated memory.
 * Its content will be copied to the new memory block and freed
 * @param new_size the desired new size in byte
 * @return pointer to the new memory
 */
void * dm_realloc(void * data_p, uint32_t new_size)
{
    uint8_t* new_p;

    new_p = dm_alloc(new_size);

    if(new_p != NULL && data_p != NULL) {
        /*Copy the old data to the new. Use the smaller size*/
        uint32_t old_size = dm_get_size(data_p);
        if(old_size != 0) {
            memcpy(new_p, data_p, min(new_size, old_size));
            dm_free(data_p);
        }
    }

    return new_p;
}
#endif /* USE_DYN_MEM_CUST != 0 */
