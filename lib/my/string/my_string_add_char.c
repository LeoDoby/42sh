/*
** EPITECH PROJECT, 2023
** my_string_add_char.c
** File description:
** 42sh
*/

#include "my.h"
#include <stdlib.h>
#include "mystring.h"

void my_string_add_char(string_t *str, int c)
{
    if (c >= 0) {
        if (str->count + 1 >= str->size) {
            str->size += STRING_BUFFER_SIZE_RATE;
            str->base = my_realloc(str->base, str->size);
        }

        str->base[str->count] = (char)c;
        str->count++;
    }
    str->base[str->count] = 0;
}
