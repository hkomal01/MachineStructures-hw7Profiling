/* bookend.h
 *
 * Header file for the module responsible for maing sure the UM initializes
 * as well as terminates properly.
 * 
 */

#include "bookend.h"

#include "addresses.h"
#include "io.h"
#include "registers.h"
#include "segments.h"
#include "unpack.h"

/* void constructor(FILE *f)
 * Takes in a .um file and initializes the UM interpreter for use by 
 * calling various initializer helepr functions from other modules
 */ 
void constructor(FILE *f)
{
    new_addresses();
    new_segments();
    new_segment_0(f);
    new_registers();
}

/* void halt()
 *
 * Description: Stops the UM interpreter and calls two helper functions in 
 * order to properly free the memory used by the program
 * Parameters: None
 * Returns: Nothing
 */
void halt()
{
    halt_execute();
    destructor();
}

/* void destructor()
 *
 * Description: frees all segments used by the UM by calling the respective
 * functions in the addresses and segments modules
 * Parameters: None
 * Returns: Nothing
 */
void destructor()
{
    free_segments();
    free_addresses();
}