#include "Constants.h"
#include "Row.h"

const uint32_t ID_SIZE = sizeof(((Row*)0)->id);
const uint32_t USERNAME_SIZE = sizeof(((Row*)0)->username);
const uint32_t EMAIL_SIZE = sizeof(((Row*)0)->email);
const uint32_t ID_OFFSET = 0;
const uint32_t USERNAME_OFFSET = ID_OFFSET + ID_SIZE;
const uint32_t EMAIL_OFFSET = USERNAME_OFFSET + USERNAME_SIZE;
const uint32_t ROW_SIZE = ID_SIZE + USERNAME_SIZE + EMAIL_SIZE;

const uint32_t PAGE_SIZE = 4096;
const uint32_t ROWS_PER_PAGE = PAGE_SIZE / ROW_SIZE;
const uint32_t TABLE_MAX_ROWS = ROWS_PER_PAGE * TABLE_MAX_PAGES;