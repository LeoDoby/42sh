/*
** EPITECH PROJECT, 2022
** my strcmp
** File description:
** strcmp
*/

int my_strcmp(char const *s1, char const *s2)
{
    int x = 0;
    while (s1[x] != '\0' || s2[x] != '\0'){
        if (s1[x] != s2[x])
            return (s1[x] - s2[x]);
        x++;
    }
    return 0;
}
