/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** lexer_add_token_2.c
*/

#include "../include/my.h"
#include "../include/mysh.h"
#include <stdlib.h>
#include "mystring.h"

void lexer_add_less_that(lexer_t *lexer, cursor_t* cursor)
{
    int c;
    Token_t token;
    if (cursor->cmd_done)
        return;
    c = cursor_peek(cursor, NULL, NULL);
    if (c == '<')
        (void)cursor_next(cursor, NULL, NULL);
    else
        return;
    token.type = Token_Less_That;
    token.value = my_strdup("<");
    lexer_add_token(lexer, &token);
    cursor->cmd_done = 1;
}

void lexer_add_greater_that(lexer_t *lexer, cursor_t* cursor)
{
    int c;
    Token_t token;
    if (cursor->cmd_done)
        return;
    c = cursor_peek(cursor, NULL, NULL);
    if (c == '>')
        (void)cursor_next(cursor, NULL, NULL);
    else
        return;
    token.type = Token_Greater_That;
    token.value = my_strdup(">");
    lexer_add_token(lexer, &token);
    cursor->cmd_done = 1;
}
