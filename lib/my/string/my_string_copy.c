/*
** EPITECH PROJECT, 2023
** my_string_copy.c
** File description:
** 42sh
*/

#include "my.h"
#include "mystring.h"

char* my_string_copy(string_t* string)
{
    return my_strdup(string->base);
}
