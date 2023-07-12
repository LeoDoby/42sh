/*
** EPITECH PROJECT, 2023
** my_memcpy.c
** File description:
** 42sh
*/

#include <stdlib.h>

void *my_memcpy(void* dst, const void* src, unsigned int n)
{
    char *dest_ptr = (char*)dst;
    const char *src_ptr = (const char*)src;
    if ((dest_ptr != NULL) && (src_ptr != NULL)) {
        while (n) {
            *(dest_ptr++) = *(src_ptr++);
            --n;
        }
    }
    return dst;
}
