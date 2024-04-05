#ifndef INPUTBUFFER_H
#define INPUTBUFFER_H

#include <stdio.h>

typedef struct InputBuffer
{
    char* buffer;
    size_t buffer_length;
    ssize_t input_length;
} InputBuffer;

InputBuffer* new_input_buffer();
void print_prompt();
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
void read_input(InputBuffer* input_buffer);
void close_input_buffer(InputBuffer* input_buffer);

#endif 
