/*
** EPITECH PROJECT, 2022
** check if is only upper
** File description:
** check if is only upper
*/

int my_str_isprintable(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < 32 || str[i] > 126)
            return 0;
        i++;
    }
    return 1;
}
