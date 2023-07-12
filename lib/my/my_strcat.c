/*
** EPITECH PROJECT, 2022
** strcat
** File description:
** strcat
*/

int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);

char *my_strcat(char *dest, char const *src)
{
    my_strcpy((&dest[my_strlen(dest)]), src);
    return dest;
}
