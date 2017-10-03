//
// Created by suk on 2.10.17.
//

#ifndef PROGRAMOVANI1_ZAPOCET_CETNOST_H
#define PROGRAMOVANI1_ZAPOCET_CETNOST_H

#include <stdlib.h>
#include <stdio.h>
#include "types.h"

#define enable_output 1

/**
 * list hodnota a jejich frekvenci
 */
struct value
{
    char character;
    unsigned int frequency;
    struct value *next;
};

/**
 * textovy vystup
 */
void create_output(struct value *output);

/**
 * vyhledat znak a vratit jeho strukturu
 * @param character
 * @param value
 * @param result
 * @return
 */
bool get_value_by_char(char character, struct value *value, struct value **result);

/**
 * vytvorit novou hodnotu
 * @return
 */
struct value *create_value();

/**
 * pridat dalsi hodnotu a vratit na ni ukazatel
 * @param last_value
 * @return
 */
struct value *add_value(struct value *last_value);

/**
 * vratit delku retezce
 * @param value
 * @return
 */
unsigned int string_size(char *value);

/**
 * vratit cetnost znaku
 * @param text
 * @return
 */
int *cetnost(char *text);

#endif //PROGRAMOVANI1_ZAPOCET_CETNOST_H
