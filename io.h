/* io.h
 * 
 * The interface for the I/O module which deals with file I/O.
 */

#include <stdio.h>
#include <stdint.h>

#ifndef IO_INCLUDED
#define IO_INCLUDED

/* Opens the file specified by a filepath and returns a pointer to the file */
extern FILE *file_open(char *filepath);

/* Closes the file specified by the file pointer */
extern void file_close(FILE *f);

/* Gets the size of the file specified by the file pointer */
extern uint32_t get_size(FILE *f);

/* Reads every 4 bytes of the file specified by the file pointer */
extern uint32_t read_line(FILE *f);

/* Writes the given character to standard output */
extern void write_char(uint32_t character);

/* Readsd a character from standard input */
extern uint32_t read_char();

#endif