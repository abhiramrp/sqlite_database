#ifndef STATEMENT_H
#define STATEMENT_H

#include "Result.h"

typedef enum {
    STATEMENT_INSERT,
    STATEMENT_SELECT 
} StatementType;

typedef struct {
    StatementType type;
} Statement;

PrepareResult prepare_statement(InputBuffer* input_buffer, Statement* statement);
void execute_statement(Statement* statement);

#endif