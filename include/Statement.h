#ifndef STATEMENT_H
#define STATEMENT_H

#include "Result.h"
#include "Row.h"

typedef enum {
    STATEMENT_INSERT,
    STATEMENT_SELECT 
} StatementType;

typedef struct {
    StatementType type;
    Row row_to_insert; 
} Statement;

PrepareResult prepare_statement(InputBuffer* input_buffer, Statement* statement);
ExecuteResult execute_insert(Statement* statement, Table* table);
ExecuteResult execute_select(Statement* statement, Table* table);
ExecuteResult execute_statement(Statement* statement, Table *table);

#endif