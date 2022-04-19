/* instructions_memory.c
 *
 * This is the implementation of the Memory instructions module described in
 * the interface
 */

#include "instructions_memory.h"

#include "addresses.h"
#include "registers.h"
#include "segments.h"
#include "unpack.h"

/* The address of the zero segment */
#define ZERO_SEGMENT 0

/* void map_segment(int rb, int rc)
 * 
 * Description: Will map a segment that has enough space to store the number of
 * words specified by the value in register rc, and then stores the address in
 * register rb
 * Parameters: A register storing the number of words to allocate (rc) and a 
 * register to store the address of the newly mapped segment in (rb)
 * Returns: Nothing directly but modifies the value of register rb to be the 
 * address of the newly mapped segment
 */
void map_segment(int rb, int rc)
{
    int Id = new_segment(get_register(rc));
    set_register(rb, Id);
}

/* void unmap_segment(int rc)
 * 
 * Description: Will unmap the segment specified by register rc
 * Parameters: A register storing the address of the segment to unmap (rc)
 * Returns: Nothing 
 */
void unmap_segment(int rc)
{
    free_segment(get_register(rc));
}

/* void segmented_load(int ra, int rb, int rc)
 * 
 * Description: Will store a word of a segment into a register
 * Parameters: A register storing the address of the segment to load (rb), a
 * register storing the position of the word to load (rc), and the register 
 * to store that word in (ra)
 * Returns: Nothing directly but modifies the value stored in register ra
 */
void segmented_load(int ra, int rb, int rc)
{
    set_register(ra, get_word(get_register(rb), get_register(rc)));
}

/* void segmented_store(int ra, int rb, int rc)
 * 
 * Description: Will store a the value of a register into a segment
 * Parameters: A register storing the address of the segment to change (rb), a
 * register storing the position of the word to change (rc), and the register 
 * with the value to be stored (ra)
 * Returns: Nothing directly but modifies the value of a word of a segment in
 * memory
 */
void segmented_store(int ra, int rb, int rc)
{
    set_word(get_register(ra), get_register(rb), get_register(rc));
}

/* void load_program(int rb, int rc)
 * 
 * Description: Replaces segment 0 with a copy of another segment and then
 * changes the program counter
 * Parameters: A register storing the address of the segment to duplicate and
 * replace m[0] with (rb) and a register storing the value of the program
 * counter (rc)
 * Returns: Nothing directly but potentially modifies the 0 segment as well as
 * the program counter
 */
void load_program(int rb, int rc)
{
    if (get_register(rb) != ZERO_SEGMENT) {
        copy_segment(get_register(rb), ZERO_SEGMENT);
    }
    set_program_counter(get_register(rc) - 1);
}