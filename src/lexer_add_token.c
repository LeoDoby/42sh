/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** lexer_add_token.c
*/

#include "../include/my.h"
#include "../include/mysh.h"
#include <stdlib.h>
#include "mystring.h"

void lexer_add_string(lexer_t *lexer, cursor_t* cursor, string_t* buf)
{
    int c;
    Token_t token;
    if (cursor->cmd_done)
        return;
    char term = cursor_next(cursor, NULL, NULL);
    while ((c = cursor_next(cursor, NULL, NULL)) >= 0) {
        if (c == term)
            break;
        else
            my_string_add_char(buf, c);
    }
    token.type = Token_String;
    token.value = my_string_copy(buf);
    lexer_add_token(lexer, &token);
    cursor->cmd_done = 1;
    if (c != term) {
        cursor->cmd_done = -1;
        dprintf(2, "Unmatched '%c'.\n", term);
    }
}

void lexer_add_args(lexer_t *lexer, cursor_t* cursor, string_t* buf)
{
    int c;
    Token_t token;
    if (cursor->cmd_done)
        return;
    while ((c = cursor_peek(cursor, NULL, NULL)) >= 0) {
        if (c == ' ' || c == '\t' || c == ';' || c == '\0')
            break;
        my_string_add_char(buf, c);
        (void)cursor_next(cursor, NULL, NULL);
    }
    token.type = Token_String;
    token.value = my_string_copy(buf);
    lexer_add_token(lexer, &token);
    cursor->cmd_done = 1;
}

void lexer_add_separator(lexer_t *lexer, cursor_t* cursor)
{
    int c;
    Token_t token;
    if (cursor->cmd_done)
        return;
    while ((c = cursor_peek(cursor, NULL, NULL)) >= 0){
        if (c == ';')
            (void)cursor_next(cursor, NULL, NULL);
        else
            break;
    }
    token.type = Token_SemiColon;
    token.value = my_strdup(";");
    lexer_add_token(lexer, &token);
    cursor->cmd_done = 1;
}

void lexer_add_ampersand(lexer_t *lexer, cursor_t* cursor)
{
    int c;
    Token_t token;
    if (cursor->cmd_done)
        return;
    c = cursor_peek(cursor, NULL, NULL);
    if (c == '&')
        (void)cursor_next(cursor, NULL, NULL);
    else
        return;
    token.type = Token_Ampersand;
    token.value = my_strdup("&");
    lexer_add_token(lexer, &token);
    cursor->cmd_done = 1;
}

void lexer_add_pipe(lexer_t *lexer, cursor_t* cursor)
{
    int c;
    Token_t token;
    if (cursor->cmd_done)
        return;
    c = cursor_peek(cursor, NULL, NULL);
    if (c == '|')
        (void)cursor_next(cursor, NULL, NULL);
    else
        return;
    token.type = Token_Pipe;
    token.value = my_strdup("|");
    lexer_add_token(lexer, &token);
    cursor->cmd_done = 1;
}
