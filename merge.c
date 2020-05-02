#include "input.h"
#include <stdio.h>
#include <stdlib.h>

void sort(int* input, size_t size) {
	if (size <= 1) {
		return;
	}

	int left[size / 2], right[(size + 1) / 2];

	for (int i = 0; i < size / 2; ++i)
		left[i] = input[i];

	for (int i = 0; i < (size + 1) / 2; ++i)
		right[i] = input[size / 2 + i];

	sort(left, size / 2);
	sort(right, (size  + 1) / 2);

	int i = 0, j = 0, k = 0;
	for (; k < size && i < size / 2 && j < (size + 1) / 2; ++k) {
		if (left[i] < right[j]) {
			input[k] = left[i];
			++i;
		} else {
			input[k] = right[j];
			++j;
		}
	}

	for (; k < size && i < size / 2; ++k) {
		input[k] = left[i];
		++i;
	}

	for (; k < size; ++k) {
		input[k] = right[j];
		++j;
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
