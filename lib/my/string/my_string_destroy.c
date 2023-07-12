/*
** EPITECH PROJECT, 2023
** my_string_destroy.c
** File description:
** 42sh
*/

#include <stdlib.h>
#include "mystring.h"

void my_string_destroy(string_t *str)
{
    free(str->base);
    str->base = NULL;
    str->count = 0;
    str->size = 0;
}
