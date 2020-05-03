#include "input.h"
#include <stdio.h>
#include <stdlib.h>

void sort(int* input, size_t size) {
	int i = 0, j = size - 1, p = size / 2;
	if (i >= j)
		return;
	while (i <= j) {
		while (input[i] < input[p]) ++i;
		while (input[j] > input[p]) --j;
		if (i <= j) {
			int t = input[i];
			input[i] = input[j];
			input[j] = t;
			++i; --j;
		}
	}
	sort(input, size / 2);
	sort(input + size / 2, (size + 1) / 2);
}

int main(int argc, char* argv[]) {
	size_t size = get_size(argc, argv);
	int* input = create_input(size);
	print_input(input, size);
	sort(input, size);
	print_input(input, size);
	return 0;
}
