/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** cursor_utils.c
*/

#include "../include/my.h"
#include "../include/mysh.h"

int cursor_next(cursor_t *cursor, int *line, int *col)
{
    int v = cursor_peek(cursor, line, col);

    if (v >= 0) {
        cursor->next++;
        cursor->col++;
        if (v == '\n') {
            cursor->col = 1;
            cursor->line++;
        }
    }
    return v;
}

int cursor_peek(cursor_t *cursor, int *line, int *col)
{
    if (cursor->next >= cursor->size)
        return -1;

    if (col != NULL)
        (*col) = cursor->col;
    if (line != NULL)
        (*line) = cursor->line;
    return cursor->text[cursor->next];
}

void init_cursor_from_str(cursor_t *cursor, char* str)
{
    cursor->col = 1;
    cursor->line = 1;
    cursor->next = 0;
    cursor->cmd_done = 0;
    cursor->text = my_strdup(str);
    cursor->size = my_strlen(str);
}

void free_cursor(cursor_t *cursor)
{
    free(cursor->text);
    cursor->text = NULL;
    cursor->next = 0;
}
