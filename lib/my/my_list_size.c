/*
** EPITECH PROJECT, 2022
** B-CPE-100-LIL-1-1-cpoolday11-lucas.doolaeghe
** File description:
** my_list_size.c
*/

#include "my.h"

int my_list_size(linked_list_t *begin)
{
    int size = 0;
    linked_list_t *tmp = begin;
    while (tmp){
        tmp = tmp->next;
        size++;
    }

    return size;
}
