/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** LLparser.c
*/

#include "../include/my.h"
#include "../include/mysh.h"
#include "mystring.h"

static int lexer_exec(cursor_t *cursor, lexer_t *lexer)
{
    int c = 0, line = 0, col = 0;
    string_t buf;
    my_string_init(&buf);
    while ((c = cursor_peek(cursor, &line, &col)) >= 0 && c != '\0') {
        cursor->cmd_done = 0;
        if (is_space(c)) ignore_to_non_whitespace(cursor);
        if (c == ';') lexer_add_separator(lexer, cursor);
        if (c == '&') lexer_add_ampersand(lexer, cursor);
        if (c == '|') lexer_add_pipe(lexer, cursor);
        if (c == '<') lexer_add_less_that(lexer, cursor);
        if (c == '>') lexer_add_greater_that(lexer, cursor);
        if (c == '\'' || c == '"') lexer_add_string(lexer, cursor, &buf);
        lexer_add_args(lexer, cursor, &buf);
        my_string_clear(&buf);
        if (cursor->cmd_done == -1)
            break;
    }
    my_string_destroy(&buf);
    return cursor->cmd_done;
}

static void print_debug_lexer(lexer_t lexer)
{
    for (int i = 0; (size_t)i < lexer.count; ++i) {
        my_putstr(TokenTextPairs[lexer.tokens[i].type].text);
        my_putstr(": '");
        my_putstr(lexer.tokens[i].value);
        my_putstr("'\n");
    }
}

void run_lexer(char* response, linked_list_t** myenv, alias_t *alias)
{
    int ret = 0;
    lexer_t lexer;
    cursor_t cursor;

    lexer_init(&lexer);
    init_cursor_from_str(&cursor, response);
    ret = lexer_exec(&cursor, &lexer);
    if (IS_DEBUG)
        print_debug_lexer(lexer);
    if (ret == 1)
        run_parser(&lexer, myenv, alias);
    lexer_free(&lexer);
    free_cursor(&cursor);
}
