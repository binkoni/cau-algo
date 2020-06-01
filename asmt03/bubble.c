#include "input.h"
#include <stdio.h>
#include <stdlib.h>
void sort(int* input, size_t size) {
	for (int i = size - 1; i >= 1; --i) {
		for (int j = 0; j < i; ++j) {
			if (input[j + 1] < input[j]) {
				int tmp = input[j + 1];
				input[j + 1] = input[j];
				input[j] = tmp;
			}
		}
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
