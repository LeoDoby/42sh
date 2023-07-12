/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** parser.c
*/

#include "../include/my.h"
#include "../include/mysh.h"
#include "mystring.h"

static int get_pipe_nbr(lexer_t *lexer, int i)
{
    int pipe = 0;
    for (; i > 0; i--) {
        if (lexer->tokens[i].type == Token_Pipe)
            pipe++;
    }
    return pipe;
}

static void set_pipe(lexer_t *lexer, command_t *cmd, int i)
{
    if (get_pipe_nbr(lexer, i) % 2 == 0)
        cmd->redirect = Token_Pipe * 2;
    else
        cmd->redirect = Token_Pipe;

}

static void check_redirections(lexer_t *lexer, command_t *cmd, int i)
{
    int t = lexer->tokens[i].type;
    int t1 = lexer->tokens[i + 1].type;
    if (i == 0) return;
    if (t == Token_Greater_That)
        greate_than(cmd, lexer, i);
    if (t == Token_Less_That && t1 == Token_Less_That) {
        double_less(cmd, lexer, i);
        return;
    } if (t == Token_Less_That && t1 != Token_Less_That)
        less_than(cmd, lexer, i);
    if (t == Token_Pipe)
        set_pipe(lexer, cmd, i);
    if (i > 1 && lexer->tokens[i - 1].type == Token_Pipe) {
        cmd->redirect = Token_Pipe * 2;
    } if (lexer->tokens[i - 1].type == Token_Greater_That) {
        cmd->redirect = Token_Greater_That * 3;
    } if (lexer->tokens[i].type == 21)
        cmd->redirect = 21;
}

command_t make_argv(lexer_t* lexer, size_t start_at)
{
    command_t cmd;
    cmd.argv = NULL; cmd.lastpipe = 0;
    cmd.error = 0; cmd.input_file = NULL;
    cmd.output_file = NULL; cmd.redirect = 0;
    size_t args_list_len = 0;
    while (start_at + args_list_len < lexer->count) {
        int i = start_at + args_list_len;
        check_redirections(lexer, &cmd, i);
        if (cmd.error) return cmd;
        if (lexer->tokens[i].type == Token_Ignore_Next) break;
        if (lexer->tokens[i].type != Token_String) break;
        args_list_len++;
    } cmd.argv = malloc(sizeof(char*) * ((args_list_len) + 1));
    for (size_t i = 0; i < args_list_len; i++)
        cmd.argv[i] = my_strdup(lexer->tokens[start_at + i].value);
    cmd.argv[args_list_len] = NULL;
    return cmd;
}

void run_parser(lexer_t* lexer, linked_list_t** myenv, alias_t *alias)
{
    size_t i = 0;
    int *pipefd = calloc(2, sizeof(int));
    pipe(pipefd);
    int default_pipe = dup(STDOUT_FILENO);
    while (i < lexer->count){
        command_t cmd = make_argv(lexer, i);
        cmd.pipefd = dup(default_pipe);
        if (cmd.argv != NULL && cmd.argv[0] != NULL)
            exec_command_by_child(cmd, myenv, pipefd, alias);
        i += my_array_size((void**)cmd.argv) + 1;
        for (int j = 0; j < my_array_size((void**)cmd.argv); ++j) {
            free(cmd.argv[j]);
        }
        if (cmd.argv)
            free(cmd.argv);
        cmd.error = 0;
    }
}
