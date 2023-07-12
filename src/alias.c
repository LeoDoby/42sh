/*
** EPITECH PROJECT, 2023
** alias
** File description:
** alias
*/
#include "../include/my.h"
#include "../include/mysh.h"
#include "mylist.h"



void search_alias(char *str, alias_t *alias)
{
    alias_t *tmp;

    tmp = alias;
    while (tmp != NULL && tmp->base != NULL && my_strcmp(str, tmp->base) == 0) {
        if (my_strcmp(str, tmp->base) == 0)
            break;
        tmp = tmp->next;
    }
    if (tmp != NULL && tmp->base != NULL && my_strcmp(tmp->base, str) == 0)
        for (int i = 0; tmp->new[i] != NULL; i++)
            printf("%s",tmp->new[i]);
}

void remove_alias(char *str, alias_t *alias)
{
    alias_t *tmp = alias, *tmp2;

    if (alias->base != NULL && my_strcmp(str, alias->base) == 0) {
        if (alias->next == NULL)
            alias->next = initalias();
        *alias = *alias->next;
        return;
    }
    while (tmp->base != NULL && my_strcmp(str, tmp->base) != 0){
        tmp2 = tmp;
        tmp = tmp->next;
    }
    if (tmp->base != NULL && my_strcmp(str, tmp->base) == 0) {
        tmp2->next = tmp->next;
    }
}

int unaliases(char **args, alias_t *alias)
{
    if (args[1] == NULL) {
        printf("unalias: Too few arguments.\n");
        return 1;
    }
    for (int i = 1; args[i] != NULL; i++) {
        remove_alias(args[i], alias);
    }
    return 0;
}

int aliases(char **args, alias_t *alias)
{
    if (args[1] == NULL){
        list_alias(alias);
        return 0;
    }
    if (args[2] == NULL) {
        search_alias(args[1], alias);
    } else {
        add_alias(args, alias);
    }
    return 0;
}
