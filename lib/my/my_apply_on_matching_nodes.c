/*
** EPITECH PROJECT, 2022
** B-CPE-100-LIL-1-1-cpoolday11-lucas.doolaeghe
** File description:
** my_apply_on_matching_nodes.c
*/

#include "my.h"

int my_apply_on_matching_nodes(linked_list_t *begin, int (*f)(),
    void const *data_ref, int (*cmp)())
{
    linked_list_t const *tmp = begin;
    while (tmp){
        if (!cmp(tmp->data, data_ref))
            f(tmp->data);
        tmp = tmp->next;
    }
    return 0;
}
