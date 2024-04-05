#ifndef RESULT_H
#define RESULT_H

#include <string.h>

#include "InputBuffer.h"

typedef enum {
  META_COMMAND_SUCCESS,
  META_COMMAND_UNRECOGNIZED_COMMAND
} MetaCommandResult;

typedef enum { 
  PREPARE_SUCCESS, 
  PREPARE_SYNTAX_ERROR,
  PREPARE_UNRECOGNIZED_STATEMENT 
} PrepareResult;

typedef enum { 
  EXECUTE_SUCCESS, 
  EXECUTE_TABLE_FULL 
} ExecuteResult;

MetaCommandResult do_meta_command(InputBuffer* input_buffer);

#endif