#
# Makefile for HW6 UM
# 
CC = gcc

IFLAGS  = -I/comp/40/build/include -I/usr/sup/cii40/include/cii
CFLAGS  = -g -std=gnu99 -Wall -Wextra -Werror -Wfatal-errors -pedantic $(IFLAGS)
LDFLAGS = -g -L/comp/40/build/lib -L/usr/sup/cii40/lib64
LDLIBS  = -lbitpack -larith40 -l40locality -lcii40 -lm

#################################################

all: um

# To get *any* .o file, compile its .c file with the following rule.
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

um: um.o io.o unpack.o handle.o instructions_arith_data.o instructions_io.o \
	instructions_logical.o instructions_memory.o bookend.o \
	addresses.o registers.o segments.o boundscheck.o 
	$(CC) $(LDFLAGS) $^ -o $@ $(LDLIBS)

clean:
	rm -f all  *.o