//
// Created by suk on 2.10.17.
//

#ifndef PROGRAMOVANI1_ZAPOCET_TEST_H
#define PROGRAMOVANI1_ZAPOCET_TEST_H

#include <stdio.h>
#include "types.h"

/**
 * success message
 */
void success();

/**
 * error message
 */
void error();

/**
 * test (int == int)
 * @param value1
 * @param value2
 */
void assert_int(int value1, int value2);

/**
 * test (unisnged int == unsigned int)
 * @param value1
 * @param value2
 */
void assert_unsigned_int(unsigned int value1, unsigned int value2);

/**
 * test (string == string)
 * @param value1
 * @param value2
 */
void assert_string(char *value1, char *value2);

#endif //PROGRAMOVANI1_ZAPOCET_TEST_H
