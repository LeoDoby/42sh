/*
** EPITECH PROJECT, 2022
** B-CPE-100-LIL-1-1-cpoolday11-lucas.doolaeghe
** File description:
** my_delete_nodes.c
*/

#include "my.h"

static void delete_nodes(linked_list_t **begin, linked_list_t **first_node,
                    linked_list_t **prev_node)
{
    if (*first_node == *begin) {
        (*begin) = (*first_node)->next;
        free((*first_node)->data);
        free((*first_node));
        return;
    }
    if (*first_node != NULL) {
        (*prev_node)->next = (*first_node)->next;
        free((*first_node)->data);
        free((*first_node));
    }
}

int my_delete_nodes(linked_list_t **begin,void const *data_ref, int (*cmp)())
{
    if (*begin == NULL)
        return -84;
    int index = 0;
    linked_list_t *first_node = *begin;
    linked_list_t *prev_node = NULL;

    while (first_node) {
        if (cmp(first_node->data, data_ref) == 0)
            break;
        index++;
        prev_node = first_node;
        first_node = first_node->next;
    }
    delete_nodes(begin, &first_node, &prev_node);
    return index;
}
