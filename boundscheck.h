/* boundscheckh
 *
 * The interface for the boundscheck module which is responsible for making
 * sure that all values worked with are in 32-bit
 */

#include <stdbool.h>
#include <stdint.h>

#ifndef BOUNDSCHECK_INCLUDED
#define BOUNDSCHECK_INCLUDED

/* Given a value and a number of bits, in_bounds will see if that value can
 * represented in that amount of bits
 */
extern bool in_bounds(uint32_t value, int num_bits);

#endif