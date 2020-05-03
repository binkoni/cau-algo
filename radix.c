#include "input.h"
#include <stdio.h>
#include <stdlib.h>

void sort(int* input, size_t size) {
	int max = -1;
	for (int i = 0; i < size; ++i) {
		if (input[i] > max)
			max = input[i];
	}

	int max_radix;
	for (max_radix = 1; max >= max_radix * 10; max_radix *= 10) ;

	for (int radix = 1; radix <= max_radix; radix *= 10) {
		int count[10] = {0,};
		for (int i = 0; i < size; ++i) {
			++count[(input[i] / radix) % 10];
		}
		for (int i = 1; i < 10; ++i)
			count[i] += count[i - 1];
		int input_copy[size];
		for (int i = 0; i < size; ++i)
			input_copy[i] = input[i];
		for (int i = size - 1; i >= 0; --i) {
			input[--count[(input_copy[i] / radix) % 10]] = input_copy[i];
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
