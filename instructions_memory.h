/* instructions_logical.h
 *
 * This is the interface for the Memory instruction module which is 
 * responsible for making sure the map_segment, unmap_segment, segmented_load,
 * segmented_store, and load_program operations are done.
 */ 

#ifndef INSTRUCTIONS_MEMORY_INCLUDED
#define INSTRUCTIONS_MEMORY_INCLUDED

/* Maps a segment able to hold a number of words equivalent to the value
 * stored in register rc and stores its address in register rb
 */
extern void map_segment(int rb, int rc);

/* Unmaps a segment whose address is held in register rc */
extern void unmap_segment(int rc);

/* Goes to the segment whose address is the value in rb, gets the 
 * word whose position is specified by the value in register rc, 
 * and stores its value in register ra
 */
extern void segmented_load(int ra, int rb, int rc);

/* Goes to the segment whose address is the value in rb, gets the 
 * word whose position is specified by the value in register rc, 
 * and stores the value of register ra at that point
 */
extern void segmented_store(int ra, int rb, int rc);

/* The segment stored whose address is the value in register rb replaces
 * segment 0 and the program counter is set to the value of register rc
 */
extern void load_program(int rb, int rc);

#endif