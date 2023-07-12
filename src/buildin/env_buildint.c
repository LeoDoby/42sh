/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** env_buildint.c
*/

#include "../../include/my.h"
#include "../../include/mysh.h"
#include "mylist.h"

int get_env(linked_list_t *linked_list)
{
    linked_list_t *tmp = linked_list;
    while (tmp) {
        my_putstr((void*)tmp->data);
        my_putchar('\n');
        tmp = tmp->next;
    }
    return 0;
}

int set_env(linked_list_t **linked_list,char *key, char *value)
{
    if (!((key[0] >= 65 && key[0] <= 90) || (key[0] >= 97 && key[0] <= 122))){
        my_putstr("setenv: Variable name must begin with a letter.\n");
        return 0;
    }
    if (my_str_contains(key, "_AZERTYUIOPQSDFGHJKLMWXCVBNazertyuiopmlkjhgfdsq"
        "wxcvbn1234567890/") == 0) {
        my_put_error("setenv: Variable name must contain alphanumeric"
        " characters.\n");
        return 0;
    }
    char *data = malloc(sizeof(char) * (my_strlen(key) + my_strlen(value) + 2));
    sprintf(data, "%s=%s", key, value);
    for (linked_list_t *tmp = *linked_list; tmp; tmp = tmp->next)
        if (!my_strncmp((char*)tmp->data, key, my_strlen(key))) {
            free(tmp->data);
            tmp->data = data;
            return 0;
        }
    my_add_node(linked_list, (void*)data);
    return 0;
}

int unset_env(linked_list_t **my_env, char *key)
{
    linked_list_t *tmp = *my_env;
    while (tmp && my_strncmp(key, tmp->data, my_strlen(key))) {
        tmp = tmp->next;
    }
    if (tmp == NULL)
        return 0;
    my_delete_nodes(my_env, tmp->data, my_strcmp);
    return 0;
}
