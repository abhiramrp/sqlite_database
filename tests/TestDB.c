#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


static FILE* temp_file = NULL;

int init_suite1(void)
{
   if (NULL == (temp_file = fopen("temp.txt", "w+"))) {
      return -1;
   }
   else {
      return 0;
   }
}

int clean_suite1(void)
{
   if (0 != fclose(temp_file)) {
      return -1;
   }
   else {
      temp_file = NULL;
      return 0;
   }
}


char* run_script(const char* commands) {
    FILE* pipe = popen("./db", "w");
    if (!pipe) {
        return NULL;
    }

    // Write commands to the pipe
    fputs(commands, pipe);
    fclose(pipe);

    // Open pipe again to read output
    pipe = popen("./db", "r");
    if (!pipe) {
        return NULL;
    }

    char* output = NULL;
    size_t len = 0;
    ssize_t read;

    // Read entire output
    while ((read = getline(&output, &len, pipe)) != -1) {
        // Process output here if needed
    }

    fclose(pipe);
    return output;
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