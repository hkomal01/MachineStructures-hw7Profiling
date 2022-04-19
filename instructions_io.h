/* instructions_io.h
 *
 * This is the interface for the I/O module which is responsible for making
 * sure the operations for input and output are done.
 */ 

#ifndef INSTRUCTIONS_IO_INCLUDED
#define INSTRUCTIONS_IO_INCLUDED

/* Take input from stdin and stores it into register ra */
extern void input(int rc);

/* Outputs the value stored in rc (in ASCII)*/
extern void output(int rc);

#endif