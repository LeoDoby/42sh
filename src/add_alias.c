/*
** EPITECH PROJECT, 2023
** alias
** File description:
** add_alias
*/
#include "../include/my.h"
#include "../include/mysh.h"
#include "mylist.h"

void add_alias2(alias_t *tmp, int i, char **args)
{
    for (int u = 2, z = 0; u != i; u++, z++){
        tmp->new[z] = my_strdup(args[u]);
    }
    tmp->new[i - 2] = NULL;
}

void add_alias(char **args, alias_t *alias)
{
    alias_t *tmp = alias;
    int i = 0;
    while (tmp != NULL && tmp->base != NULL) {
        if (my_strcmp(args[1], tmp->base) == 0)
            break;
        tmp = tmp->next;
    }
    if (tmp != NULL && tmp->base != NULL && my_strcmp(args[1], tmp->base) == 0){
        free(tmp->new);
        free(tmp->base);
    } else
        while (tmp->next != NULL)
            tmp = tmp->next;
    if (tmp->next == NULL)
        tmp->next = initalias();
    tmp->base = my_strdup(args[1]);
    for (i = 2; args[i] != NULL; i++);
    tmp->new = malloc(sizeof(char *) * (i - 1));
    add_alias2(tmp,i,args);
}

int check_alias(char *cmd, char **args, alias_t *alias)
{
    if (!my_strcmp(cmd, "alias"))
        return aliases(args,alias);
    if (!my_strcmp(cmd, "unalias"))
        return unaliases(args, alias);
    return 0;
}
