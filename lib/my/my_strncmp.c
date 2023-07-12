/*
** EPITECH PROJECT, 2022
** strncmp
** File description:
** compare n char in a str
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    for (int x = 0; x < n && (s1[x] != '\0' || s2[x] != '\0'); x++){
        if (s1[x] != s2[x])
            return (s1[x] - s2[x]);
    }
    return 0;
}
