CFLAGS=-Wall -g
OFILE= -c -o

ex22_main: ex22.o ex22_main.o
	$(CC) ex22.o ex22_main.o -o ex22_main

ex22.o: ex22.c
	$(CC) -c ex22.c

ex22_main.o: ex22_main.c
	$(CC) -c ex22_main.c

clean:
	rm -f ex22 ex22_main
