/* instructions_arith_data.c
 *
 * This is the implementation of the Arithmetic and Data module described in
 * the interface.
 */ 

#include "instructions_arith_data.h"

#include <stdint.h>
#include <assert.h>

#include "boundscheck.h"
#include "registers.h"

#define LOAD_VALUE_BITS 25

/* void addition(int ra, int rb, int rc)
 *
 * Description: Performs the addition operation on three registers
 * Parameters: Three registers: two of which to add and the final to store
 * the value in (ra).
 * Returns: Nothing directly but changes the value in register ra to the 
 * sum of the others
 */ 
extern void addition(int ra, int rb, int rc)
{
    set_register(ra, (get_register(rb) + get_register(rc)));
}

/* void multiplication(int ra, int rb, int rc)
 *
 * Description: Performs the multiplication operation on three registers
 * Parameters: Three registers: two of which to multiply and the final to store
 * the value in (ra).
 * Returns: Nothing directly but changes the value in register ra to the 
 * product of the others
 */ 
extern void multiplication(int ra, int rb, int rc)
{
    set_register(ra, (get_register(rb) * get_register(rc)));
}

/* void multiplication(int ra, int rb, int rc)
 *
 * Description: Performs the division operation on three registers
 * Parameters: Three registers: two of which to divide and the final to store
 * the value in (ra).
 * Returns: Nothing directly but changes the value in register ra to the 
 * quotient of the others
 */ 
extern void division(int ra, int rb, int rc)
{
    set_register(ra, get_register(rb) / get_register(rc));
}

/* void conditional_move(int ra, int rb, int rc)
 *
 * Description: Performs the conditional move operation
 * Parameters: Three registers: one to test against and two others to 
 * potentially modify the values of.
 * Returns: Nothing directly but can change the value of register ra
 */ 
extern void conditional_move(int ra, int rb, int rc)
{
    if (get_register(rc) != 0) {
        set_register(ra, get_register(rb));
    }
}

/* void conditional_move(int ra, uint32_t value)
 *
 * Description: Performs the load value operation
 * Parameters: A register and a value to place inside of that register
 * Returns: Nothing directly but changes the value of register ra
 */ 
extern void load_value(int ra, uint32_t value)
{
    assert(in_bounds(value, LOAD_VALUE_BITS));

    set_register(ra, value);
}