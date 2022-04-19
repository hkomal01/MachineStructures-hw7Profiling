/* registers.c
 * 
 * This is the implementation of the registers module described inthe interface
 */
#include "registers.h"

#include <assert.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#include "boundscheck.h"

#define REGISTER_BITS 3
#define REGISTER_SIZE 32

/* 8 registers are initialized */
uint32_t registers[8];

/* void new_registers()
 * 
 * Description: Initializes the register values all to 0
 * Parameters: None
 * Returns: Nothing
 */
void new_registers()
{
    /* jump through array and set each element to 0 */
    for (int i = 0; i < 8; i++) {
        registers[i] = 0;
    }
}

/* void set_register(int regId, uint32_t value)
 * 
 * Description: Changes the value of the register
 * Parameters: The index of the register to change and the value to change it
 * to
 * Returns: Nothing directly but modifies a register
 */
void set_register(int regId, uint32_t value)
{
    assert(in_bounds(regId, REGISTER_BITS));
    assert(in_bounds(value, REGISTER_SIZE));

    registers[regId] = value;
}

/* void get_register(int regId)
 * 
 * Description: Gets the value of a register
 * Parameters: The index of the register whose value to is to be retrieved
 * Returns: The value of the register specified
 */
uint32_t get_register(int regId)
{
    assert(in_bounds(regId, REGISTER_BITS));

    return registers[regId];
}