/* instructions_logical.h
 *
 * This is the interface for the Logical instruction module which is 
 * responsible for making sure bitwise_nand is done.
 */ 

#ifndef INSTRUCTIONS_LOGICAL_INCLUDED
#define INSTRUCTIONS_LOGICAL_INCLUDED

/* Nands the values of register rb and rc and stores result in register ra */
extern void bitwise_nand(int ra, int rb, int rc);

#endif