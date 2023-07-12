/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** lexer_utils.c
*/

#include "../include/my.h"
#include "../include/mysh.h"
#include <stdlib.h>
#include "mystring.h"

void lexer_init(lexer_t* lexer)
{
    lexer->tokens = malloc(sizeof(Token_t) * TOKEN_LIST_GROWBY);
    lexer->size = TOKEN_LIST_GROWBY;
    lexer->count = 0;
}

void lexer_free(lexer_t* lexer)
{
    for (int i = 0; (size_t)i < lexer->count; ++i) {
        free(lexer->tokens[i].value);
    }
    lexer->size = 0;
    free(lexer->tokens);
    lexer->tokens = NULL;
    lexer->count = 0;
}

void lexer_add_token(lexer_t *lexer, Token_t *token)
{
    if (lexer->count >= lexer->size) {
        lexer->size += TOKEN_LIST_GROWBY;
        lexer->tokens = my_realloc(lexer->tokens, sizeof(Token_t) *lexer->size);
    }
    my_memcpy(&lexer->tokens[lexer->count], token, sizeof(Token_t));
    lexer->count++;
}
