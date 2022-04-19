/* instructions_logical.c
 *
 * This is the implementation of the Logical instructions module described in
 * the interface
 */ 

#include "instructions_logical.h"

#include <stdio.h>
#include <stdint.h>

#include "registers.h"

/* void bitwise_nand(int ra, int rb, int rc)
 * 
 * Description: Will perform the bitwise-nand operation on the values of two
 * registers and the store the result in the third register
 * Parameters: The two registers whose values are to be nand'd (rb and rc) and
 * the register in which the result is to be stored (ra)
 * Returns: Nothing directly but will change the value in register ra
 */ 
void bitwise_nand(int ra, int rb, int rc)
{   
    uint32_t nand = (uint32_t) ~(get_register(rb) & get_register(rc));
    set_register(ra, nand);
}