/*
** EPITECH PROJECT, 2023
** alias
** File description:
** alias_loop
*/
#include "../include/my.h"
#include "../include/mysh.h"
#include "mylist.h"

alias_t *initalias(void)
{
    alias_t *alias;

    alias = malloc(sizeof(alias_t));
    alias->base = NULL;
    alias->new = NULL;
    alias->next = NULL;
    return alias;
}

void print_alias_b(alias_t *tmp)
{
    int i = 0;

    for (;tmp->new[i] != NULL; i++);
    if (i > 1)
        printf("(");
    for (int z = 0; z < i - 1; z++)
        printf("%s ", tmp->new[z]);
    printf("%s", tmp->new[i - 1]);
    if (i > 1)
        printf(")");
}

int *list_alias(alias_t *alias)
{
    alias_t *tmp;

    tmp = alias;
    while (tmp->base != NULL) {
        printf("%s\t",tmp->base);
        print_alias_b(tmp);
        printf("\n");
        tmp = tmp->next;
    }
    return 0;
}

int alias_loop(char *str, alias_t *alias)
{
    alias_t *tmp = alias;
    char *str2 = NULL;

    while (tmp->base != NULL) {
        if (tmp->new[1] == NULL && my_strcmp(str, tmp->base) == 0)
                str2 = tmp->new[0];
        tmp = tmp->next;
    }
    tmp = alias;
    while (tmp->base != NULL) {
        if (tmp->new[1] == NULL && str2 != NULL && my_strcmp(str2, tmp->base) ==
        0 && my_strcmp(str, tmp->new[0]) == 0){
                printf("Alias loop.\n");
                return 1;
            }
        tmp = tmp->next;
    }
    return 0;
}

char **transform_argv(char **args, alias_t *alias)
{
    alias_t *tmp = alias;
    char **result;
    int i, u;

    while (tmp->base != NULL && my_strcmp(tmp->base, args[0]) != 0)
        tmp = tmp->next;
    if (tmp->base == NULL)
        return args;
    for (i = 0; args[i] != NULL; i++);
    for (u = 0; tmp->new[u] != NULL; u++);
    result = malloc(sizeof(char *) * (i + u));
    for (u = 0; tmp->new[u] != NULL; u++)
        result[u] = tmp->new[u];
    for (i = 1; args[i] != NULL; i++, u++)
        result[u] = args[i];
    result[u] = NULL;
    return result;
}
