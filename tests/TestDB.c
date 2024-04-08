#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Statement.h"
#include "Result.h"


static FILE* temp_file = NULL;



char* run_script(const char* commands) {
    FILE* pipe = popen("./db", "w");
    if (!pipe) {
        return NULL;
    }

    InputBuffer* input_buffer = new_input_buffer();

    int numCommands = sizeof(commands) / sizeof(commands[0]);

    // Loop through the array
    for (int i = 0; i < numCommands; ++i) {
        FILE *fake_input = fmemopen(commands[i], strlen(commands[i]), "r");
        if (fake_input == NULL) {
            printf("Error creating fake input stream\n");
            exit(EXIT_FAILURE);
        }

        // Redirect stdin to the fake input stream
        FILE *original_stdin = stdin;
        stdin = fake_input;


        read_input(&input_buffer);

        stdin = original_stdin;
        fclose(fake_input);

        // Print the result
        printf("Read input: %s\n", input_buffer.buffer);

        // Free allocated memory
        free(input_buffer.buffer);
    }

    fclose(pipe);
    return "adf";
}


void test_insert_and_retrieve_row() {
    const char* commands[] = {
        "insert 1 user1 person1@example.com",
        "select",
        ".exit"
    };

    char* result = run_script(commands);

    CU_ASSERT_STRING_EQUAL(result, "db > Executed.\ndb > (1, user1, person1@example.com)\nExecuted.\ndb > \n");
    free(result);
}

int main(void)
{
    CU_pSuite pSuite = NULL;

    /* initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    CU_pSuite suite = CU_add_suite("DatabaseTests", NULL, NULL);

    CU_add_test(suite, "test_insert_and_retrieve_row", test_insert_and_retrieve_row);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return CU_get_error();


}