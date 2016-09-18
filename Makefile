CC = gcc
CFLAGS = -g -Wall


all: w4118_sh

w4118_sh: shell.o
	$(CC) $(CFLAGS) shell.o -o w4118_sh

shell.o: shell.c
	$(CC) $(CFLAGS) -c shell.c

clean:
	rm -f *.o 