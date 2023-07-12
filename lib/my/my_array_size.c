/*
** EPITECH PROJECT, 2023
** my_array_size.c
** File description:
** PSU2
*/

#include "my.h"

int my_array_size(void** array)
{
    int len = 0;
    if (!array)
        return len;
    while (*array){
        len++;
        array++;
    }
    return len;
}
