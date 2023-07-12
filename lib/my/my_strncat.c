/*
** EPITECH PROJECT, 2022
** strncat
** File description:
** strncat
*/

int my_strlen(char const *str);
char *my_strncpy(char *dest, char const *src, int n);

char *my_strncat(char *dest, char const *src, int nb)
{
    my_strncpy((&dest[my_strlen(dest)]), src, nb);
    return dest;
}
