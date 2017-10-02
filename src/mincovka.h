//
// Created by suk on 2.10.17.
//

#ifndef PROGRAMOVANI1_ZAPOCET_MINCOVKA_H
#define PROGRAMOVANI1_ZAPOCET_MINCOVKA_H

#include "types.h"
#include <stdlib.h>
#include <stdio.h>

#define enable_output 1

struct coin
{
    unsigned int value;
    unsigned int count;
    struct coin *next;
};

/**
 * uklid
 * @param value
 */
void free_all(struct coin* value);

/**
 * textovy vystup
 */
void coin_create_output(struct coin *output);

/**
 * vyhledat znak a vratit jeho strukturu
 * @param character
 * @param coin
 * @param result
 * @return
 */
bool get_coin_by_value(unsigned int value, struct coin *coin, struct coin **result);

/**
 * vytvorit novou hodnotu
 * @return
 */
struct coin *create_coin();

/**
 * pridat dalsi hodnotu a vratit na ni ukazatel
 * @param last_coin
 * @return
 */
struct coin *add_coin(struct coin *last_coin);

/**
 * pocet pouzitych minci
 * @param castka
 * @param platidla
 * @return
 */
int mincovka(unsigned int castka, unsigned int **platidla);

#endif //PROGRAMOVANI1_ZAPOCET_MINCOVKA_H
