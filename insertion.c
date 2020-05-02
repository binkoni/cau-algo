#include "input.h"
#include <stdio.h>
#include <stdlib.h>
void sort(int* input, size_t size) {
	for (int i =  1; i < size; ++i) {
		int key = input[i];
		int j;
		for (j = i - 1; j >= 0 && input[j] > key; --j)
			input[j + 1] = input[j];
		input[j + 1] = key;
	}
}

int main(int argc, char* argv[]) {
	size_t size = get_size(argc, argv);
	int* input = create_input(size);
	print_input(input, size);
	sort(input, size);
	print_input(input, size);
	return 0;
}
