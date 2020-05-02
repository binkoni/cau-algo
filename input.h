#ifndef INPUT_H
#define INPUT_H
#include <stddef.h>
int* create_input(size_t size);
void print_input(int* input, size_t size);
size_t get_size(int argc, char* argv[]);
#endif
