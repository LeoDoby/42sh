/*
** EPITECH PROJECT, 2022
** B-CPE-100-LIL-1-1-cpoolday11-lucas.doolaeghe
** File description:
** my_params_to_list .c
*/

#include "my.h"
#include "mylist.h"

linked_list_t *my_params_to_list(int ac, char** av)
{
    linked_list_t *ptr = NULL;

    for (int i = 0; i < ac; i++){
        my_add_node(&ptr, my_strdup(av[i]));
    }
    return ptr;
}
