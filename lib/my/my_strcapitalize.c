/*
** EPITECH PROJECT, 2022
** str capitalize
** File description:
** capitalize str
*/

char *my_strlowcase(char *str);

char *my_strcapitalize(char *str)
{
    int i = 0;
    my_strlowcase(str);
    while (str[i] != '\0'){
        if ((str[i] >= 97 && str[i] <= 122) &&
            !((str[i - 1] >= 97 && str[i - 1] <= 122) ||
            (str[i - 1] >= 65 && str[i - 1] <= 90) ||
            (str[i - 1] >= 48 && str[i - 1] <= 57)))
            str[i] -= 32;
        i++;
    }
    return str;
}
