CC=gcc
CFLAGS=-c -Wall
all: myadder

myadder: main.o adder.o print.o 
	$(CC) main.o adder.o print.o -o myadder

main.o: main.c 
	$(CC) $(CFLAGS) main.c

adder.o: adder.c
	$(CC) $(CFLAGS) adder.c

print.o: print.c 
	      $(CC) $(CFLAGS) print.c

clean:
	rm -f myadder print.c *.o *-
