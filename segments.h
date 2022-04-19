/* segments.h
 *
 * This is the interface for the Segments module which is reponsible for
 * the memory management segments.
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef SEGMENTS_INCLUDED
#define SEGMENTS_INCLUDED

/* Initializer function for the module */
extern void new_segments();

/* Creates a segment with the number of words specified and returns the 
 * ID of the segment created
 */
extern uint32_t new_segment(uint32_t numWords);

/* Allocates memory for segment 0 at the start of the program */
void new_segment_0(FILE *f);

/* Frees the segment at the given ID */
extern void free_segment(uint32_t Id);

/* Destructor function: Frees all memory at the end of the program
 * almost like a garbage collector
 */
extern void free_segments();

/* Copies the contents of one segment to another */
extern void copy_segment(uint32_t Id_from, uint32_t Id_to);

/* Returns the number of words in the segment at the given ID */
extern uint32_t num_words(uint32_t Id);

/* Gets the word at the given ID and word position */
extern uint32_t get_word(uint32_t Id, uint32_t word);

/* Sets the word at the given ID and word position */
extern void set_word(uint32_t Id, uint32_t word, uint32_t value);

#endif