/* boundscheck.c
 *
 * This is the implemntation of the boundscheck.h interface
 */ 

#include "boundscheck.h"

#include <stdio.h>
#include <stdlib.h>

#include "bitpack.h"

/* bool in_bounds(uint32_t value, int num_bits)
 * 
 * Description: This function checks to see whether a given value can be 
 * represented in the specified number of bits
 * Parameters: The value to check the bounds of and the number of bits
 * Returns: True if the value is in boudns and false otherwise.
 */
bool in_bounds(uint32_t value, int num_bits)
{
        return Bitpack_fitsu(value, num_bits);
}