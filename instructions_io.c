/* instructions_io.c
 *
 * This is the implementation of the I/O module described in the interface.
 */ 

#include "instructions_io.h"

#include "io.h"
#include "registers.h"
#include "boundscheck.h"

#include <assert.h> 

/* Define the number of bits in a character as a constant */
#define CHAR_BITS 8

/* void input(int rc)
 * 
 * Description: Take input from stdin and stores the input into register rc
 * Parameters: The register in which the value inputted is to be stored
 * Returns: Nothing directly but the value of register rc will be changed
 */
extern void input(int rc)
{
    uint32_t character = read_char();
    assert(character == (uint32_t) ~0 || in_bounds(character, CHAR_BITS));
    set_register(rc, character);
}

/* void output(int rc)
 * 
 * Description: Output the byte stored in register rc as a character
 * Parameters: The register in which the value to be outputted is stored
 * Returns: Nothing directly but prints to stdout
 */
extern void output(int rc)
{
    uint32_t character = get_register(rc);
    assert(in_bounds(character, CHAR_BITS));
    write_char(character);
}