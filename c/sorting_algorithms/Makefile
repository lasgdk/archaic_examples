sorting: sorting.o heap_sort.o merge_sort.o insertion_sort.o generate_input.o
	cc -Wall -ansi -pedantic -o sorting sorting.o heap_sort.o merge_sort.o insertion_sort.o generate_input.o
sorting.c heap_sort.o merge_sort.o insertion_sort.o generate_input.o: sorting.h
	cc -Wall -ansi -pedantic -c $*.c

clean:
	rm -f *.o
