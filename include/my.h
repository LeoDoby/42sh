/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** header for my libmy functions
*/

#ifndef MY_H_
    #define MY_H_
    #include "mylist.h"
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>

int my_put_nbr(int n);
void my_putchar(char c);
int my_is_prime(int nb);
char *int_to_str(int nb);
int my_isneg(int number);
char *int_to_str(int nb);
char *my_revstr(char *str);
void my_swap(int *a, int *b);
void my_put_error(char* str);
int my_find_prime_sup(int nb);
char *my_strupcase(char *str);
int my_getnbr(char const *str);
int my_strlen(char const *str);
char *my_strlowcase(char *str);
int my_putstr(char const *str);
int my_array_size(void** array);
int my_showstr(char const *str);
char *my_strdup(char const *src);
char *my_strcapitalize(char *str);
int my_str_isnum(char const *str);
int my_compute_square_root(int nb);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_compute_power_rec(int nb, int p);
void *my_realloc(void *ptr, size_t size);
int my_showmem(char const *str, int size);
char *get_env_value(char **env, char *name);
void my_sort_int_array(int *array, int size);
char *my_strcat(char *dest, char const *src);
char *my_strcpy(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
void my_free_linked_list(linked_list_t **list);
char** my_str_to_word_array(char* str, char *c);
char *my_strstr(char *str, char const *to_find);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(char const *s1, char const *s2, int n);
void *my_memcpy(void* dst, const void* src, unsigned int n);
int get_color(unsigned char red, unsigned char green, unsigned char blue);

#endif // MY_H_
