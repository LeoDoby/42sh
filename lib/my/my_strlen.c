/*
** EPITECH PROJECT, 2022
** my strlen
** File description:
** my strlen
*/

int my_strlen(char const *str)
{
    int i = 0;
    if (!str)
        return i;
    while (str[i] != '\0'){
        i++;
    }
    return i;
}
