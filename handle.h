/* handle.h
 *
 * This is the interface for the handle module which is responsible for 
 * handling unpacked UM instructions
 * 
 */

#include <stdint.h>

#ifndef HANDLE_INCLUDED
#define HANDLE_INCLUDED

/* Given an opcode and upto 3 register value, instruction_handling will 
 * perform the operation specified
 */
extern void instruction_handling(int opcode, int ra, int rb, int rc);

/* Will perform load value with the given register and value*/
extern void lv_handling(int ra, uint32_t value);

#endif