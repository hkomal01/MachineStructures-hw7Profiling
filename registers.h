/* registers.h
 * 
 * This is the interface for the Registers module which is reponsible for
 * handling register values 
 */

#include <stdint.h>

#ifndef REGISTERS_INCLUDED
#define REGISTERS_INCLUDED

/* Initializes every value in the register to 0 */
extern void new_registers();

/* Set the register at regId to a 32-bit value*/
extern void set_register(int regId, uint32_t value);

/* Returns the word stored in a register */
extern uint32_t get_register(int regId);

#endif