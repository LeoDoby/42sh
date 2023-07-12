/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** header for my string functions
*/

#ifndef MY_STRING_H_
    #define MY_STRING_H_
    #define STRING_BUFFER_SIZE_RATE 16
    #include <stdlib.h>

typedef struct string_s {
    size_t size;
    size_t count;
    char * base;
} string_t;

void my_string_init(string_t *str);
void my_string_clear(string_t *str);
void my_string_destroy(string_t *str);
char* my_string_copy(string_t* string);
void my_string_add_char(string_t *str, int c);
int my_str_contains(const char *str, const char *cmp);

#endif
