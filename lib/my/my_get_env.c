/*
** EPITECH PROJECT, 2023
** my_get_env.c.c
** File description:
** PSU2
*/
#include <stdlib.h>

int my_strlen(char const *str);
int my_strncmp(char const *s1, char const *s2, int n);

char *get_env_value(char **env, char *name)
{
    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], name, my_strlen(name)) == 0 &&
            env[i][my_strlen(name)] == '=')
            return &(env[i])[my_strlen(name) + 1];
    }

    return "NULL";
}
