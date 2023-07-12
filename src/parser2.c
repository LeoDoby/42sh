/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** parser2
*/

#include "../include/my.h"
#include "../include/mysh.h"
#include "mystring.h"

int last_pipe(lexer_t *lexer)
{
    int last = 0;
    for (size_t i = 0; i < lexer->count; i++) {
        if (lexer->tokens[i].type == Token_Pipe)
            last = i;
    }
    return last;
}

void double_less(command_t *cmd, lexer_t *lexer, size_t i)
{
    if ((i + 2) >= lexer->count && lexer->tokens[i + 2].type != 6) {
        my_putstr("Missing name for redirect.\n");
        lexer->tokens[i].type = Token_Ignore_Next;
        lexer->tokens[i + 1].type = Token_Ignore_Next;
        cmd->error = 1;
        return;
    }
    cmd->input_file = strdup(lexer->tokens[i + 2].value);
    cmd->redirect = Token_Less_That * 2;
    lexer->tokens[i + 1].type = Token_Ignore_Next;
    lexer->tokens[i + 2].type = 21;
}

void less_than(command_t *cmd, lexer_t *lexer, size_t i)
{
    if ((i + 1) >= lexer->count && lexer->tokens[i + 1].type != 6) {
        my_putstr("Missing name for redirect.\n");
        lexer->tokens[i].type = Token_Ignore_Next;
        cmd->error = 1;
        return;
    } if ((open(lexer->tokens[i + 1].value, O_RDONLY)) == -1) {
        my_putstr(lexer->tokens[i + 1].value);
        my_putstr(": No such file or directory.\n");
        lexer->tokens[i].type = Token_Ignore_Next;
        lexer->tokens[i + 1].type = Token_Ignore_Next;
        cmd->error = 1;
        return;
    } cmd->input_file = strdup(lexer->tokens[i + 1].value);
    cmd->redirect = Token_Less_That;
}

void greate_than(command_t *cmd, lexer_t *lexer, size_t i)
{
    if ((i + 1) >= lexer->count && lexer->tokens[i + 1].type != 7) {
        my_putstr("Missing name for redirect.\n");
        lexer->tokens[i].type = Token_Ignore_Next;
        cmd->error = 1;
        return;
    } cmd->output_file = strdup(lexer->tokens[i + 1].value);
    cmd->input_file = strdup(lexer->tokens[i - 1].value);
    cmd->redirect = Token_Greater_That;
    if (lexer->tokens[i + 1].type == Token_Greater_That) {
        if (lexer->tokens[i + 2].type != 2) {
            my_putstr("Missing name for redirect.\n");
            lexer->tokens[i + 1].type = Token_Ignore_Next;
            cmd->error = 1;
            return;
        }
        cmd->output_file = strdup(lexer->tokens[i + 2].value);
        cmd->redirect *= 2;
        lexer->tokens[i + 1].type = Token_Ignore_Next;
        lexer->tokens[i + 2].type = Token_Greater_That * 3;
    }
}
