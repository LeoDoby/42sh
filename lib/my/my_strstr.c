/*
** EPITECH PROJECT, 2022
** my strstr
** File description:
** find a string in a str
*/

#include <stdlib.h>
int my_strncmp(char const *s1, char const *s2, int n);
int my_strlen(char const *str);

char *my_strstr(char *str, char const *to_find)
{
    int str_size = my_strlen(str);
    int to_find_size = my_strlen(to_find);

    for (int i = 0; i < str_size; i++){
        int tmp = my_strncmp((&str[i]), to_find, to_find_size);
        if (tmp == 0)
            return (&str[i]);
    }
    return NULL;
}
