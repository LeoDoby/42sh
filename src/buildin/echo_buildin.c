/*
** EPITECH PROJECT, 2023
** echo_buildin.c.c
** File description:
** B-PSU-200-LIL-2-1-42sh-lucas.doolaeghe
*/

#include "my.h"
#include "mysh.h"
#include <stdio.h>
#include <string.h>

static int variable(char* var, linked_list_t** my_env, int *i)
{
    if (strstr(var, "$") == NULL)
        return 0;
    char *s = get_env_value(linked_list_to_word_array(*my_env),
                            &(strstr(var, "$")[1]));
    if (!strcmp(s, "NULL")) {
        printf("Undefined variable.\n");
        return 1;
    }
    (*i)++;
    printf("%s ", s);
    return 0;
}

int echo_buidin(char** args, linked_list_t** my_env)
{
    int size = my_array_size((void**)args);

    for (int i = 1; i < size; ++i) {
        if (variable(args[i], my_env, &i))
            return 0;
        if (i < size)
            printf("%s ", args[i]);
    }
    printf("\n");
    return 0;
}
