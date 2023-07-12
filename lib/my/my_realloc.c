/*
** EPITECH PROJECT, 2023
** my_realloc.c
** File description:
** 42sh
*/

#include "my.h"
#include <stdlib.h>

void *my_realloc (void *ptr, size_t size)
{
    if (size == 0) {
        free(ptr);
        return NULL;
    }

    if (ptr == NULL)
        return malloc(size);

    void *new_ptr = malloc(size);
    if (new_ptr == NULL)
        return NULL;

    my_memcpy(new_ptr, ptr, my_strlen((char*)ptr));
    free(ptr);
    return new_ptr;
}
