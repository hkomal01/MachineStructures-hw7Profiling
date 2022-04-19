/* addresses.c
 * 
 * implementation of the addresses module which is described by the interface
 * addresses.h
 */

#include "addresses.h"

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#include "stack.h"

/* Initialize a stack of rectcled addresses and a "counter" variable */
Stack_T addresses;
uint32_t next_id;


/* new_addresses()
 *
 * Description: Initializes the stack of recycled addresses and also assigns
 * a starter value to the next_id counter variable.
 * Parameters: None
 * Returns: Nothing directly but assigns values to certain variables
 */
void new_addresses()
{
    addresses = Stack_new();
    next_id = 1;
}

/* giveId()
 *
 * Description: Gives an ID to be used for a newly mapped segment
 * Parameters: None
 * Returns: A new ID for a mapped segment as an unsigned integers
 * Note: If there are any recycled IDs, they will be returned first
 * and new IDs will only be returned if there are no "recycled" IDs 
 */
uint32_t giveId()
{
    /* Return a recycled ID if there are any available */
    if (!Stack_empty(addresses)) {
        return (uint32_t) (uintptr_t) Stack_pop(addresses);
    }
    
    /* Else return a new id */
    return next_id++;
}

/* recycleId(uint32_t Id)
 *
 * Description: Takes in the Id of a segment to be freed and allows it to be
 * used again by another segment.
 * Parameters: The ID to be recycled (as an unsigned integers)
 * Returns: Nothing
 */
void recycleId(uint32_t Id)
{
    Stack_push(addresses, (void *)(uintptr_t)Id);
}

/* free_addresses()
 *
 * Description: Frees all memory used by the stack of recycled IDs
 * Parameters: None
 * Returns: Nothing
 */
void free_addresses()
{
    Stack_free(&addresses);
}