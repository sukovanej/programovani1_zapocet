//
// Created by suk on 2.10.17.
//

#include "mincovka.h"

unsigned int COINS_ARRAY[12] = {5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};

int mincovka(unsigned int castka, unsigned int **platidla)
{
    unsigned int remaining = castka;
    unsigned int sum = 1;
    unsigned int i = 0;

    struct coin *first = create_coin();
    struct coin *actual = first;

    while (remaining < COINS_ARRAY[i])
        i++;

    first->count = 1;
    first->value = COINS_ARRAY[i];
    remaining -= COINS_ARRAY[i];

    while (remaining != 0) {
        while (remaining < COINS_ARRAY[i])
            i++;

        if (actual->value == COINS_ARRAY[i]) {
            actual->count++;
        } else {
            actual = add_coin(actual);
            actual->value = COINS_ARRAY[i];
            actual->count = 1;
        }

        remaining -= COINS_ARRAY[i];

        sum++;
    }

    unsigned int counter = 0;
    *platidla = (unsigned int *) malloc(sum * sizeof(unsigned int *));
    actual = first;

    while (actual) {
        for (unsigned int i = 0; i < actual->count; i++) {
            (*platidla)[counter] = actual->value;
            counter++;
        }

        actual = actual->next;
    }


    if (enable_output) {
        coin_create_output(first);
    }

    /** ukliad */
    free_all(&first);

    return sum;
}

struct coin *create_coin()
{
    struct coin *new_value = (struct coin *) malloc(sizeof(struct coin));

    return new_value;
}

struct coin *add_coin(struct coin *last_coin)
{
    last_coin->next = create_coin();
    return last_coin->next;
}

void coin_create_output(struct coin *output)
{
    if (output) {
        printf("%dKč (x%d), ", output->value, output->count);
        coin_create_output(output->next);
    } else {
        printf("\n");
    }
}

void free_all(struct coin **value)
{
    if ((*value)->next)
        free_all(&((*value)->next));

    free(*value);
}
