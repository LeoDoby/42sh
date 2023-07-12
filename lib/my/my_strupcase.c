/*
** EPITECH PROJECT, 2022
** my upper case
** File description:
** my upper case
*/

char *my_strupcase(char *str)
{
    int i = 0;
    while (str[i] != '\0'){
        if (str[i] >= 97 && str[i] <= 122)
            str[i] -= 32;
        i++;
    }
    return str;
}
