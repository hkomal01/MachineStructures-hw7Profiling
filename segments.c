/* segments.c
 *
 * This is the implementation of the Segments module described in the interface
 */

#include "segments.h"

#include <seq.h>
#include <stdlib.h>
#include <string.h>

#include "addresses.h"
#include "io.h"

#define WORD_BYTES 4

/* Initialize two sequences */
Seq_T segments;
Seq_T sizes;

/* void new_segments()
 * 
 * Description: Creates two sequences of size 0 that represent each segment 
 * and their sizes
 * Parameters: None
 * Returns: Nothing
 * Note: This function runs at the start of the program once
 */
void new_segments() 
{
    segments = Seq_new(0);
    sizes = Seq_new(0);
}

/* uint32_t new_segment(uint32_t numWords)
 * 
 * Description: Creates a new segment of numWords size and returns its ID or
 * address
 * Parameters: The size of the segment to allocate
 * Returns: The address or ID of the segment
 */
uint32_t new_segment(uint32_t numWords)
{
    /* Create a new ID for the segment and allocate memory */
    uint32_t segmentId = giveId();
    uint32_t *segment = malloc(numWords * WORD_BYTES);
    uint32_t *segmentSize = malloc(sizeof(uint32_t));
    *segmentSize = numWords;

    /* Place the segment inside the sequence at index segmentId and expand
     * the size of the sequence if necessary
     */
    if (segmentId < (uint32_t) Seq_length(segments)) {
        Seq_put(segments, segmentId, segment);
        Seq_put(sizes, segmentId, segmentSize);
    }
    else {
        Seq_addhi(segments, segment);
        Seq_addhi(sizes, segmentSize);
    }

    /* Initialize all the words to 0 */
    for (uint32_t word = 0; word < numWords; word++) {
        set_word(segmentId, word, 0);
    }
    
    return segmentId;
}

/* void new_segment_0(FILE *f)
 * 
 * Description: Allocates memory for segment 0 based on the size of the file
 * Parameters: A pointer to the file of UM instructions
 * Returns: Nothing
 * Note: This function runs at the start of the program once
 */
void new_segment_0(FILE *f)
{
    /* Gets the number of 4 byte words in the file */
    uint32_t numWords = get_size(f) / WORD_BYTES;
    /* Allocate memory for the segment */
    uint32_t segmentId = 0;
    uint32_t *segment = malloc(numWords * WORD_BYTES);
    uint32_t *segmentSize = malloc(sizeof(uint32_t));
    *segmentSize = numWords;
    /* Add the segment to the sequence of segments and its size to the 
     * sequence of sizes
     */
    Seq_addlo(segments, segment);
    Seq_addlo(sizes, segmentSize);

    /* Read every word of the file and initialize values of the 0 segment to
     * to those words
     */
    for (uint32_t word = 0; word < numWords; word++) {
        set_word(segmentId, word, read_line(f));
    }
}

/* void free_segment(uint32_t Id)
 * 
 * Description: Frees the segment whose ID is specified
 * Parameters: The ID of the segment to free
 * Returns: Nothing
 */
void free_segment(uint32_t Id)
{
    /* Free the ID and recycle it */
    if (Seq_get(segments, Id) != NULL) {
        free(Seq_get(segments, Id));
        Seq_put(segments, Id, NULL);
        recycleId(Id);
    }

    /* Do the same for the seqquence of segment sizes */
    if (Seq_get(sizes, Id) != NULL) {
        free(Seq_get(sizes, Id));
        Seq_put(sizes, Id, NULL);
    }
}

/* void free_segments()
 * 
 * Description: Frees all remaining segments when the UM finishes running
 * Parameters: None
 * Returns: Nothing
 */
void free_segments()
{
    /* Free every segment */
    uint32_t length = (uint32_t) Seq_length(segments);
    for (uint32_t Id = 0; Id < length; Id++) {
        free_segment(Id);
    }
    
    /* Free the sequences */
    Seq_free(&segments);
    Seq_free(&sizes);
}

/* void copy_segment(uint32_t Id_from, uint32_t Id_to)
 * 
 * Description: Duplicates the contents of one segment and replaces the 
 * contents of another segment with the duplicate
 * Parameters: The address of the segment to replace and the adddress of the 
 * segment to duplicate
 * Returns: Nothing
 * Note: This function is really only used to replace segment 0 and so in 
 * practice Id_to is always 0
 */
void copy_segment(uint32_t Id_from, uint32_t Id_to)
{
    /* Free the segment being replaced */
    free_segment(Id_to);

    /* Allocate a new segment of the same size and copy contents over */
    uint32_t numWords = num_words(Id_from);
    new_segment(numWords);
    memcpy(Seq_get(segments, Id_to), 
           Seq_get(segments, Id_from), numWords * WORD_BYTES);
}

/* void num_words(uinta32_t Id)
 * 
 * Description: Gets the number of words stored in a segment
 * Parameters: The address of the segment to get the number of words of
 * Returns: The number of words stored in a segment
 */
uint32_t num_words(uint32_t Id) 
{
    return *(uint32_t *)Seq_get(sizes, Id);
}

/* void get_word(uinta32_t Id, uint32_t word)
 * 
 * Description: Gets a specific word stored in the segment specified
 * Parameters: The address of the segment to get the word of and the 'index'
 * of the word to get
 * Returns: A uint32_t representing the word retrieved
 */
uint32_t get_word(uint32_t Id, uint32_t word)
{
    return *((uint32_t *)Seq_get(segments, Id) + word);
}

/* void get_word(uinta32_t Id, uint32_t word, uint32_t value)
 * 
 * Description: Sets a specific word stored in the segment specified to a 
 * given value
 * Parameters: The address of the segment to set the word of, the 'index'
 * of the word to set, and the value of the word to set
 * Returns: Nothing dirctly but changes the word in memory
 */
void set_word(uint32_t Id, uint32_t word, uint32_t value)
{
    uint32_t *toSet = (uint32_t *)Seq_get(segments, Id) + word;
    *toSet = value;
}