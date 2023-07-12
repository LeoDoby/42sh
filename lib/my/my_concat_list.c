/*
** EPITECH PROJECT, 2022
** B-CPE-100-LIL-1-1-cpoolday11-lucas.doolaeghe
** File description:
** my_concat_list.c
*/

#include "my.h"

void my_concat_list(linked_list_t **begin1, linked_list_t *begin2)
{
    linked_list_t *tmp;

    tmp = *begin1;
    while (tmp->next){
        tmp = tmp->next;
    }
    tmp->next = begin2;
}
