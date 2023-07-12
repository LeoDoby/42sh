/*
** EPITECH PROJECT, 2022
** my put str
** File description:
** put a string
*/

void my_putchar(char c);

int my_putstr(char const *str)
{
    int x = 0;
    while (str[x] != '\0'){
        my_putchar(str[x]);
        x++;
    }
    return 0;
}
