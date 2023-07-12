/*
** EPITECH PROJECT, 2023
** my_add_node.c
** File description:
** 42sh
*/

#include "my.h"
#include "mylist.h"

linked_list_t* my_add_node(linked_list_t** list, void *value)
{
    if (*list == NULL) {
        (*list) = malloc(sizeof(linked_list_t));
        (*list)->data = value;
        (*list)->next = NULL;
        return *list;
    }
    linked_list_t *tmp = *list;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = malloc(sizeof(linked_list_t));
    tmp->next->data = value;
    tmp->next->next = NULL;
    return *list;
}
