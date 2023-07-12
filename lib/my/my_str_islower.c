/*
** EPITECH PROJECT, 2022
** check if is only lower
** File description:
** check if is only lower
*/

int my_str_islower(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < 97 || str[i] > 122)
            return 0;
        i++;
    }
    return 1;
}
