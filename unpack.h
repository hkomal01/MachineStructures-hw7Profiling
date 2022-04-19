/* unpack.h
 * 
 * This is the interface for the Unpack module which is responsible for
 * unpacking every UM instruction and then performing the operation specified.
 */

#include <stdint.h>
#include <stdbool.h>

#ifndef UNPACK_INCLUDED
#define UNPACK_INCLUDED

/* Runs the UM Interpreter */
extern void execute();

/* Stops the UM Interpreter from running */
extern void halt_execute();

/* Returns true if the UM has been halted */
extern bool halted();

/* Gets the value of the program counter */
extern uint32_t get_program_counter();

/* Sets the program counter to a specified value */
extern void set_program_counter(uint32_t word);

/* Unpacks a given UM instruction */
extern void unpack(uint32_t instruction);

#endif
