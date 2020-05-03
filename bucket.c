#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(int* input, size_t size) {
	const int BKTCAP = 10;
	const int BKTCNT = size / BKTCAP + 1;
	int* bktsizes = malloc(BKTCNT * sizeof(int));
	memset(bktsizes, 0, BKTCNT * sizeof(int));
	int** bkt = malloc(BKTCNT * sizeof(int*));
	for (int i = 0; i < BKTCNT; ++i)
		bkt[i] = malloc(size * sizeof(int));

	for (int i = 0; i < size; ++i) {
		bkt[input[i] / BKTCAP][bktsizes[input[i] / BKTCAP]] = input[i];
		++bktsizes[input[i] / BKTCAP];
	}
	for (int i = 0; i < BKTCNT; ++i) {
		for (int j = 0; j < bktsizes[i] - 1; ++j) {
			for (int k = j + 1; k < bktsizes[i]; ++k) {
				if (bkt[i][j] > bkt[i][k]) {
					int t = bkt[i][j];
					bkt[i][j] = bkt[i][k];
					bkt[i][k] = t;
				}
			}
		}
	}
	for (int c = 0, i = 0; i < BKTCNT; ++i) {
		for (int j = 0; j < bktsizes[i]; ++j)
			input[c++] = bkt[i][j];
	}

	for (int i = 0; i < BKTCNT; ++i)
		free(bkt[i]);
	free(bkt);

	free(bktsizes);
}

int main(int argc, char* argv[]) {
	size_t size = get_size(argc, argv);
	int* input = create_input(size);
	print_input(input, size);
	sort(input, size);
	print_input(input, size);
	return 0;
}
