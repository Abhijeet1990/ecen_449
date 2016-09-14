
CC=gcc
CFLAGS=-c -Wall
all: ThirdAns

ThirdAns: Abhijeet_HW2_Q3_main.o Abhijeet_HW2_Q3_swap.o Abhijeet_HW2_Q3_sort.o Abhijeet_HW2_Q3_Prime.o 
	$(CC) Abhijeet_HW2_Q3_main.o Abhijeet_HW2_Q3_swap.o Abhijeet_HW2_Q3_sort.o Abhijeet_HW2_Q3_Prime.o -o ThirdAns

Abhijeet_HW2_Q3_main.o: Abhijeet_HW2_Q3_main.c 
	$(CC) $(CFLAGS) Abhijeet_HW2_Q3_main.c

Abhijeet_HW2_Q3_swap.o: Abhijeet_HW2_Q3_swap.c
	$(CC) $(CFLAGS) Abhijeet_HW2_Q3_swap.c

Abhijeet_HW2_Q3_sort.o: Abhijeet_HW2_Q3_sort.c 
	      $(CC) $(CFLAGS) Abhijeet_HW2_Q3_sort.c 

Abhijeet_HW2_Q3_Prime.o: Abhijeet_HW2_Q3_Prime.c 
	$(CC) $(CFLAGS) Abhijeet_HW2_Q3_Prime.c



clean:
	rm *o ThirdAns 
