/*
 * Copyright by Lars Sommer, <lasg@lasg.dk> 2009-03-11, Beerware license.
 * Do with the code what you want, but keep this license note.
 * Give me a beer or cup of coffee if we ever meet and you like this program.
 */

#include <stdio.h>
#include <stdlib.h>
#include <libc.h>
#define LEN 36
#define MAXVALUE 100
#define DEBUG 0

int build_max_heap(int*,int);
int printtree(int*,int);
int parray(int*,int);
int max_heapify(int*,int,int);
int merge(int*,int*,int*,int,int);
int insertion_sort(int*,int);
int merge_sort(int*,int);
int heap_sort(int*,int);
int generate_input(int,char);


