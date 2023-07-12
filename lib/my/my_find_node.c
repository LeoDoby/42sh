/*
** EPITECH PROJECT, 2022
** B-CPE-100-LIL-1-1-cpoolday11-lucas.doolaeghe
** File description:
** my_find_node.c
*/

#include "my.h"

linked_list_t *my_find_node(linked_list_t *begin, void *data_ref, int (*cmp)())
{
    linked_list_t *tmp = begin;
    linked_list_t *ret = ((void*)0);
    while (tmp->next != ((void*)0) && ret == ((void*)0)){
        if (!cmp(tmp->data, data_ref))
            ret = tmp;
        tmp = tmp->next;
    }
    return ret;
}
