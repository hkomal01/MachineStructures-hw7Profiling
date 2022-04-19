/* unpack.c
 * 
 * This is the implementation of the Unpack module described in the interface
 */

#include "unpack.h"

#include <assert.h>

#include "addresses.h"
#include "bitpack.h"
#include "handle.h"
#include "registers.h"
#include "segments.h"

#define OPCODE_WIDTH 4
#define OPCODE_LSB 28
#define LV 13
#define RA_WIDTH 3
#define RA_LSB 6
#define RA_LSB_LV 25
#define RB_WIDTH 3
#define RB_LSB 3
#define RC_WIDTH 3
#define RC_LSB 0
#define VALUE_WIDTH 25
#define VALUE_LSB 0

#define START_OF_PROGRAM 0
#define ZERO_SEGMENT 0
#define RUNNING true
#define HALTED false

/* Initialize the program counter and a boolean to see if the interpreter is 
 * running
 */
uint32_t program_counter;
bool run;

/* void execute()
 * 
 * Description: Execute the UM instructions given
 * Parameters: None
 * Returns: Nothing
 */
void execute()
{
    program_counter = START_OF_PROGRAM;
    run = RUNNING;

    /* Read every instruction until we are done with the file or we halt */
    while (run == true && 
           program_counter < (uint32_t) num_words(ZERO_SEGMENT)) {
        unpack(get_word(ZERO_SEGMENT, program_counter));
        program_counter++;
    }
}

/* void halt_execute()
 * 
 * Description: Sets the value of the run boolean to false if we've halted
 * Parameters: None
 * Returns: Nothing directly but modifies the 'run' boolean
 */
extern void halt_execute()
{
    run = HALTED;
}

/* bool halted()
 * 
 * Description: Checks whether or not the UM has halted
 * Parameters: None
 * Returns: True if we've hit a halt operation or EOF and false otherwise
 */
extern bool halted()
{
    return(!(run == RUNNING));
}

/* uint32_t get_program_counter()
 * 
 * Description: Gets the value of the program counter
 * Parameters: None
 * Returns: The current position of the program counter 
 */
extern uint32_t get_program_counter()
{
    return program_counter;
}

/* void set_program_counter(uint32_t word)
 * 
 * Description: Sets the value of the program counter to the one specified
 * Parameters: The value to set the program counter to
 * Returns: Nothing 
 */
extern void set_program_counter(uint32_t word)
{
    program_counter = word;
}

/* void unpack(uint32_t instruction)
 * 
 * Description: Unpacks every single instruction the .um file given and stores
 * relevant pieces of information to be handle.
 * Parameters: The instruction to unpack
 * Returns: Nothing 
 */
extern void unpack(uint32_t instruction)
{
    /* Get the opcode of the instruction unpacked */
    int opcode = Bitpack_getu(instruction, OPCODE_WIDTH, OPCODE_LSB);
    int ra;

    /* If the operation is a load value instruction unpack the value and call
     * the load value function (lv_handling)
     */
    if (opcode == LV) {
        ra = Bitpack_getu(instruction, RA_WIDTH, RA_LSB_LV);
        uint32_t value = Bitpack_getu(instruction, VALUE_WIDTH, VALUE_LSB);
        
        lv_handling(ra, value);
    }
    /* Otherwise, store values for ra, rb, rc and call the handle function */
    else {
        ra = Bitpack_getu(instruction, RA_WIDTH, RA_LSB);
        int rb = Bitpack_getu(instruction, RB_WIDTH, RB_LSB);
        int rc = Bitpack_getu(instruction, RC_WIDTH, RC_LSB);

        instruction_handling(opcode, ra, rb, rc);
    }
}