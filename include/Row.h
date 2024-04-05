#ifndef ROW_H
#define ROW_H

#include <stdlib.h>
#include <string.h>

#include "Table.h"

typedef struct {
    uint32_t id;
    char username[COLUMN_USERNAME_SIZE];
    char email[COLUMN_EMAIL_SIZE];
} Row;

void serialize_row(Row* source, void* destination);
void deserialize_row(void* source, Row* destination);
void* row_slot(Table* table, uint32_t row_num);
void print_row(Row* row);

#endif
