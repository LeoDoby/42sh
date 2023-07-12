/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** init_env.c
*/

#include "../include/my.h"
#include "../include/mysh.h"
#include "mylist.h"

linked_list_t *init_env(char** env)
{
    if (*env == NULL)
        return NULL;
    linked_list_t *my_env = my_params_to_list(my_array_size((void**)env), env);
    return my_env;
}

void free_env(linked_list_t* my_env)
{
    if (my_env == NULL)
        return;
    linked_list_t* tmp = my_env;
    for (int i = 0; tmp != NULL; ++i) {
        free(tmp->data);
        tmp = tmp->next;
    }
}
