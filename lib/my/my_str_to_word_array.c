/*
** EPITECH PROJECT, 2023
** my_str_to_word_array.c.c
** File description:
** PSU2
*/

#include <stdlib.h>
#include "my.h"

static int char_is_in_str(char *str, char c)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == c)
            return 1;
    return 0;
}

int count_words(char *str, char *c)
{
    int num = 0;
    int len = my_strlen(str) + 1;
    int  i = 0;

    for (; i < len; ++i) {
        while (str[i] && !char_is_in_str(c, str[i])) ++i;
        for (; str[i] && char_is_in_str(c, str[i]); ++i)
            str[i] = '\0';
        num++;
    }
    return num;
}

void set_str(char **word_array, char *str, int num)
{
    int i = 0;
    int word_index = 0;

    for (; word_index < num; ++word_index) {
        for (; !str[i]; ++i);
        word_array[word_index] = &str[i];
        for (; str[i]; ++i);
    }
    word_array[word_index] = NULL;
}

char **my_str_to_word_array(char *str, char *c)
{
    char **word_array = NULL;
    char *str_dup = NULL;
    int num = 0;

    str_dup = my_strdup(str);
    if (!str_dup)
        return (NULL);
    num = count_words(str_dup, c);
    word_array = malloc(sizeof(char *) * (num + 1));
    if (!word_array) {
        free (str_dup);
        return (NULL);
    }
    set_str(word_array, str_dup, num);
    return (word_array);
}
