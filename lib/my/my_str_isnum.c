/*
** EPITECH PROJECT, 2022
** check if is only num
** File description:
** check if is only num
*/

int my_str_isnum(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < 48 || str[i] > 57)
            return 0;
        i++;
    }
    return 1;
}
