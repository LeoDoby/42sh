/*
** EPITECH PROJECT, 2023
** int_to_str.c
** File description:
** 42sh
*/

#include "my.h"

char *int_to_str(int nb)
{
    int tmp = nb;
    int maxsize = 1, size = 0;;
    char *ret = NULL;
    while (tmp >= 10) {
        tmp /= 10;
        maxsize++;
    }
    ret = malloc(sizeof(char) * (maxsize + 1));
    while (size < maxsize) {
        ret[(maxsize - 1) - size] = 48 + (nb % 10);
        nb /= 10;
        size++;
    }
    ret[maxsize] = '\0';
    return ret;
}
