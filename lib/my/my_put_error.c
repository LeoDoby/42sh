/*
** EPITECH PROJECT, 2023
** my_put_error.c
** File description:
** B-PSU-200-LIL-2-1-42sh-lucas.doolaeghe
*/

#include "my.h"

void my_put_error(char* str)
{
    write(2, str, my_strlen(str));
}
