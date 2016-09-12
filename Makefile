all: w4118_sh

w4118_sh: shell.o
	gcc shell.o -o w4118_sh

shell.o: shell.c
	gcc -c shell.c

clean:
	rm -f *.o 