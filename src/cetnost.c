//
// Created by suk on 2.10.17.
//

#include "cetnost.h"

unsigned int string_size(char *value)
{
    unsigned int size;
    for (size = 0; value[size] != '\0'; size++) {}
    return size;
}

struct value *create_value()
{
    struct value *new_value = (struct value *) malloc(sizeof(struct value));

    return new_value;
}

struct value *add_value(struct value *last_value)
{
    last_value->next = create_value();
    return last_value->next;
}

bool get_value_by_char(char character, struct value *value, struct value **result)
{
    if (value->character != character) {
        if (!value->next)
            return false;

        return get_value_by_char(character, value->next, result);
    } else {
        *result = value;
        return true;
    }
}

void create_output(struct value *output)
{
    if (output) {
        printf("%c:%d \n", output->character, output->frequency);
        create_output(output->next);
    }
}

int *cetnost(char *text)
{
    unsigned int text_size = string_size(text);

    if (text_size == 0) {
        printf("error: prazdny retezec");
    }

    struct value *first = create_value();
    first->character = text[0];

    struct value *last = first;
    struct value *actual_value;

    unsigned int i;
    for (i = 0; i < text_size; i++) {
        if (get_value_by_char(text[i], first, &actual_value) == true) {
            actual_value->frequency++;
        } else {
            last = add_value(last);
            last->character = text[i];
            last->frequency++;
        }
    }

    int *result = (int *) malloc(i * sizeof(int));

    actual_value = first;
    unsigned int counter = 0;

    while (actual_value) {
        result[counter] = actual_value->frequency;
        actual_value = actual_value->next;
        counter++;
    }

    if (enable_output)
        create_output(first);

//    free_all2(first);
//    first = NULL;
//    actual_value = NULL;
//    last = NULLo
    t

    return result;
}

void free_all2(struct value *value)
{
    if (!value)
        return;

    if (value->next)
        free_all2(value->next);

    free(value);
}
