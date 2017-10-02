//
// Created by suk on 2.10.17.
//

#include "test.h"

void success()
{
    printf("\x1B[32m > test passed\033[0m\n");
}

void error()
{
    printf("\x1B[31m > test error\033[0m\n");
}

void assert_int(int value1, int value2)
{
    if (value1 == value2) {
        success();
    } else {
        error();
        printf("\x1B[31m %d != %d \033[0m\n", value1, value2);
    }
}

void assert_unsigned_int(unsigned int value1, unsigned int value2)
{
    if (value1 == value2) {
        success();
    } else {
        error();
        printf("\x1B[31m %d != %d \033[0m\n", value1, value2);
    }
}

void assert_string(char *value1, char *value2)
{
    bool result = true;

    unsigned int counter = 0;
    while (value1[counter] != '\0' && value2[counter] != '\0') {
        if (value1[counter] != value2[counter]) {
            result = false;
            break;
        }
    }

    if (result)
        success();
    else
        error();
}
