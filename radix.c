#include "input.h"
#include <stdio.h>
#include <stdlib.h>

void sort(int* input, size_t size) {
	for (int i = 0
}

int main(int argc, char* argv[]) {
	size_t size = get_size(argc, argv);
	int* input = create_input(size);
	print_input(input, size);
	sort(input, size);
	print_input(input, size);
	return 0;
}
