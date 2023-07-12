/*
** EPITECH PROJECT, 2022
** my rev str
** File description:
** reverce a str
*/

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    int len_str = my_strlen(str) - 1;
    char tmp;
    for (int i = 0; i < len_str - i; i++){
        tmp = str[i];
        str[i] = str[len_str - i];
        str[len_str - i] = tmp;
    }

    return (&str[0]);
}
