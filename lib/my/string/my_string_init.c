/*
** EPITECH PROJECT, 2023
** my_string_init.c
** File description:
** 42sh
*/

#include <stdlib.h>
#include "mystring.h"

void my_string_init(string_t *str)
{
    str->count = 0;
    str->size = STRING_BUFFER_SIZE_RATE;
    str->base = malloc(sizeof(char) * str->size);
    str->base[0] = 0;
}
