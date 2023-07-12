/*
** EPITECH PROJECT, 2023
** my_linked_list_to_word_array.c
** File description:
** 42sh
*/

#include "my.h"
#include "mylist.h"

char **my_linked_list_to_word_array(linked_list_t *linked_list)
{
    int len = 0;
    char **list_char = NULL;
    linked_list_t *tmp = linked_list;
    for (len = 0; tmp; ++len) {
        tmp = tmp->next;
    }
    list_char = malloc(sizeof(char*) * (len + 1));
    tmp = linked_list;
    for (int i = 0; tmp; ++i) {
        list_char[i] = my_strdup((char*)tmp->data);
        tmp = tmp->next;
    }
    list_char[len] = NULL;
    return list_char;
}
