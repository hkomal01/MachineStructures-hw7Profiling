/* addresses.h
 * 
 * Interface for the addresses module which is responsible for keeping track
 * of addresses for mapped memory
 */
#include <stdint.h>

#ifndef ADDRESSES_INCLUDED
#define ADDRESSES_INCLUDED

/* Initializes the addresses module */
extern void new_addresses();

/* Returns the next availabe ID to map (for use by a segment) */
extern uint32_t giveId();

/* Takes a newly freed segment's ID and makes it available for use again */
extern void recycleId(uint32_t Id);

/* Frees all memory used by the addresses module */
extern void free_addresses();

#endif
