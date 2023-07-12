/*
** EPITECH PROJECT, 2022
** dup a str
** File description:
** dup a str
*/

#include <stdlib.h>
int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);

char *my_strdup(char const *src)
{
    char *ptr;
    ptr = malloc(sizeof(char) * (my_strlen(src) + 1));
    my_strcpy(ptr,src);
    return ptr;
}
