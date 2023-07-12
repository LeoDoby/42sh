/*
** EPITECH PROJECT, 2022
** check if is only upper
** File description:
** check if is only upper
*/

int my_str_isupper(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < 65 || str[i] > 90)
            return 0;
        i++;
    }
    return 1;
}
