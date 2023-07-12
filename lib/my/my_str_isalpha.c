/*
** EPITECH PROJECT, 2022
** is alpha like me
** File description:
** return if a str only as char
*/

char *my_strlowcase(char *str);
int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);

int my_str_isalpha(char const *str)
{
    int i = 0;
    char arr[my_strlen(str)];
    my_strcpy(arr, str);
    my_strlowcase(arr);

    while (arr[i] != '\0') {
        if (arr[i] < 97 || arr[i] > 122)
            return 0;
        i++;
    }
    return 1;
}
