/* handle.c
 *
 * This is the implementation of the handle module.
 *
 */

#include "handle.h"

#include <assert.h>
#include "bookend.h"
#include "instructions_arith_data.h"
#include "instructions_io.h"
#include "instructions_logical.h"
#include "instructions_memory.h"
#include "unpack.h"

/* All operations able to be performed by the UM */
typedef enum Um_opcode {
        CMOV = 0, SLOAD, SSTORE, ADD, MUL, DIV,
        NAND, HALT, ACTIVATE, INACTIVATE, OUT, IN, LOADP, LV
} Um_opcode;

/* void instruction_handling(int opcode, int ra, int rb, rc)
 *
 * Description: This function will perform the given operation using the values
 * specified in the three registers.
 * Parameters: The opcode of the instruction to perform and upto 3 registers
 * to use in those instructions.
 * Returns: Nothing directly, however, the operations may change some value in
 * on of the registers.
 * Note: Opcode will be beteen 0-12 and the registers will be between
 * 0-8
 */
void instruction_handling(int opcode, int ra, int rb, int rc)
{
    assert(opcode < LV && opcode >= CMOV);
    
    /* Switch statement will execute the instruction depending on the opcode */
    switch(opcode) {
        case CMOV:
            conditional_move(ra, rb, rc);
            break;
        case SLOAD:
            segmented_load(ra, rb, rc);
            break;
        case SSTORE:
            segmented_store(ra, rb, rc);
            break;
        case ADD:
            addition(ra, rb, rc);
            break;
        case MUL:
            multiplication(ra, rb, rc);
            break;
        case DIV:
            division(ra, rb, rc);
            break;
        case NAND:
            bitwise_nand(ra, rb, rc);
            break;
        case HALT:
            halt();
            break;
        case ACTIVATE:
            map_segment(rb, rc);
            break;
        case INACTIVATE:
            unmap_segment(rc);
            break;
        case OUT:
            output(rc);
            break;
        case IN:
            input(rc);
            break;
        case LOADP:
            load_program(rb, rc);
            break;
    }
}

/* void lv_handling(int ra, uint32_t value)
 * 
 * Description: This function will perform specifically the load value 
 * operation by calling the load_value function.
 * Parameters: The register to load a value into and the value to be loaded
 * Returns: Nothing directly but will modify what is stored in register ra
 */
void lv_handling(int ra, uint32_t value)
{
    load_value(ra, value);
}    