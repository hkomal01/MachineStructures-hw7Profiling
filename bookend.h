/* bookend.h
 *
 * Header file for the module responsible for maing sure the UM initializes
 * as well as terminates properly.
 * 
 */
#include <stdio.h>
#include <stdlib.h>

#ifndef BOOKEND_INCLUDED
#define BOOKEND_INCLUDED

/* Given the UM file to run, the UM interpreter is initalized*/
extern void constructor(FILE *f);

/* Ends the UM interpreter */
extern void halt();

/* Helper function for halt() in order to properly end the UM interpreter */
extern void destructor();

#endif