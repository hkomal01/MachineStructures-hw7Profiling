#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "bookend.h"
#include "boundscheck.h"
#include "io.h"
#include "registers.h"
#include "segments.h"
#include "unpack.h"

int main(int argc, char *argv[])
{       
    /* Error checking for the arguments passed */
    if (argc != 2) {
        exit(EXIT_FAILURE);
    }
    
    FILE *fp = file_open(argv[1]);

    constructor(fp);
    execute();
    if (!halted()) {
        destructor();
    }

    file_close(fp);

    return EXIT_SUCCESS;
}