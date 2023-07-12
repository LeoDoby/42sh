/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** env_utils.c
*/

#include "../include/my.h"
#include "mylist.h"

int print_env(linked_list_t *my_env)
{
    linked_list_t *tmp = my_env;
    while (tmp){
        my_putstr( (char*)tmp->data);
        my_putchar('\n');
        tmp = tmp->next;
    }
    return 0;
}
