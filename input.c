#include "input.h"
#include <stdlib.h>
#include <stdio.h>
int* create_input(size_t size) {
	int* input = malloc(size * sizeof(int));
	for (int i = size - 1; i >= 0; --i) {
		input[i] = size - i;	
	}
	return input;
}

void print_input(int* input, size_t size) {
	for (int i = 0; i < size; ++i)
		printf("%d ", input[i]);

	printf("\n");
}

size_t get_size(int argc, char* argv[]) {
	if (argc < 2) {
		printf("need an arg");
		exit(1);
	}
	size_t size;
	{
		char* p;
		size = strtol(argv[1], &p, 10);
	}
}
