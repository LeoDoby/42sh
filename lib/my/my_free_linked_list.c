/*
** EPITECH PROJECT, 2023
** my_free_linked_list.c
** File description:
** 42sh
*/

#include "my.h"
#include "mylist.h"

void my_free_linked_list(linked_list_t **list)
{
    if (*list == NULL)
        return;
    my_free_linked_list(&((*list)->next));
    my_delete_nodes(list, (*list)->data, my_strcmp);
}
