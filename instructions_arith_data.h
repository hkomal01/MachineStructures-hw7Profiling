/* instructions_arith_data.h
 *
 * This is the interface for the Arithmetic and Data module which is 
 * responsible for making sure the operations for addition, 
 * multiplication, division, conditional_move, and load value are done.
 */ 

#include <stdint.h>

#ifndef INSTRUCTIONS_ARITH_DATA_INCLUDED
#define INSTRUCTIONS_ARITH_DATA_INCLUDED

/* Given three registers, addition is performed (ra = rb + rc)*/
extern void addition(int ra, int rb, int rc);

/* Given three registers, multiplication is performed (ra = rb * rc)*/
extern void multiplication(int ra, int rb, int rc);

/* Given three registers, division is performed (ra = rb / rc) */
extern void division(int ra, int rb, int rc);

/* Given three registers, conditional movie is performed 
 * (if rc != 0 then ra = rb)
 */
extern void conditional_move(int ra, int rb, int rc);

/* Given a register and a value, the value is loaded onto the register */
extern void load_value(int ra, uint32_t value);

#endif 
