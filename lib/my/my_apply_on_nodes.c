/*
** EPITECH PROJECT, 2022
** B-CPE-100-LIL-1-1-cpoolday11-lucas.doolaeghe
** File description:
** my_apply_on_nodes.c
*/

#include "my.h"


int my_apply_on_nodes(linked_list_t *begin, int(*f)(void*))
{
    int size = 0;
    linked_list_t const *tmp = begin;
    while (tmp){
        f(tmp->data);
        tmp = tmp->next;
        size++;
    }
    return 0;
}
