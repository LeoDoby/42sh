/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** ignore_white_space.c
*/

#include "../include/mysh.h"

int is_space(int c)
{
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

void ignore_to_non_whitespace(cursor_t *cursor)
{
    int c;
    if (cursor->cmd_done)
        return;
    while ((c = cursor_peek(cursor, NULL, NULL)) >= 0 ) {
        if (is_space(c))
            (void)cursor_next(cursor, NULL, NULL);
        else
            break;
    }
    cursor->cmd_done = 1;
}
