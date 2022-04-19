/* io.c
 * 
 * The implementation of the I/O module described in the interface.
 */

#include "io.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

#include "bitpack.h"
#include "boundscheck.h"

#define BYTE 8

/* FILE *file_open(char *filepath)
 * 
 * Description: Opens the file at a given path
 * Parameters: A string specifying the filepath of the file to open
 * Returns: A pointer to the opened file
 */
FILE *file_open(char *filepath)
{
    /* check that the filepath exists */
    assert (filepath != NULL);
    /* open file and check that it opened properly */
    FILE *fp = fopen(filepath, "r");
    assert(fp != NULL);
    
    return fp;
}

/* FILE *file_close(FILE *f)
 * 
 * Description: Closes a given file
 * Parameters: A pointer to the file to close
 * Returns: Nothing
 */
void file_close(FILE *f)
{
    assert(f != NULL);
    fclose(f); 
}

/* uint32_t get_size(FILE *f)
 * 
 * Description: Gets the size of a given file
 * Parameters: A pointer to the file
 * Returns: An unsigned integer holding the size of the file in bytes.
 */
uint32_t get_size(FILE *f)
{
    /* seek to the end of the file  and check number of characters read */
    fseek(f, 0L, SEEK_END);
    uint32_t size = ftell(f);
    rewind(f);
    return size;
}

/* uint32_t read_line(FILE *f)
 * 
 * Description: Reads every 4 bytes of a file and returns the,
 * Parameters: A pointer to the file
 * Returns: An unsigned integers holding 4 bytes of the file or one UM
 * instruction
 */
uint32_t read_line(FILE *f)
{ 
    uint32_t instruction = 0;
    /* Concatenate every 4 characters of the file into a uint32_t */
    for (int lsb = 24; lsb >= 0; lsb -= 8) {
        assert(!feof(f));     
        instruction = Bitpack_newu(instruction, BYTE, lsb, getc(f));
    }
    return instruction;
}

/* void write_char(uint32_t character)
 * 
 * Description: Writes a character to stdout
 * Parameters: The character to output 
 * Returns: Nothing but writes to standard output
 */
void write_char(uint32_t character)
{
    putchar((int) character);
}

/* uint32_t read_char()
 * 
 * Description: Reads a character from stdin
 * Parameters: None
 * Returns: The character read as a uint32_t
 */
uint32_t read_char()
{
    if (feof(stdin)) {
        return ~0;
    }
    return (uint32_t) getchar();
}