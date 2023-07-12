/*
** EPITECH PROJECT, 2022
** mysh
** File description:
** headerfile for mysh project
*/

#ifndef mysh_
    #define mysh_
    #define TOKEN_LIST_GROWBY 32
    #define IS_DEBUG !my_strcmp(get_env_value(linked_list_to_word_array \
    (*myenv), "DEBUG"), "1")
    #include <stdio.h>
    #include "mylist.h"
    #include <stdlib.h>
    #include <unistd.h>
    #include <string.h>
    #include <fcntl.h>
    #include "mystring.h"

enum TokenType {
    Token_Unknown,
    Token_DoubleQuote,
    Token_String,
    Token_SemiColon,
    Token_Pipe,
    Token_Ampersand,
    Token_Less_That,
    Token_Greater_That,
    Token_Ignore_Next,
};

typedef struct Token_s {
    enum TokenType type;
    char *value;
}Token_t;

typedef struct TokenTextPair_s {
    enum TokenType type;
    const char *text;
}TokenTextPair_t;

typedef struct cursor_s {
    int col;
    int line;
    char *text;
    size_t next;
    size_t size;
    int cmd_done;
} cursor_t;

typedef struct env_s {
    char* name;
    char* value;
} env_t;

static const TokenTextPair_t TokenTextPairs[] = {
        { Token_Unknown, "Unknown Symbol"},
        {Token_DoubleQuote, "Quote"},
        {Token_String, "String"},
        {Token_SemiColon, "Separator"},
        {Token_Pipe, "Pipe"},
        {Token_Ampersand, "Ampersand"},
        {Token_Less_That, "less that"},
        {Token_Greater_That, "greater that"},
        {Token_Ignore_Next, "Ignore Next Token"},

};

typedef struct alias_s {
    char *base;
    char **new;
    struct alias_s *next;
} alias_t;

typedef struct lexer_s {
    size_t size;
    size_t count;
    Token_t* tokens;
} lexer_t;

typedef struct command_s {
    int error;
    int append;
    char **argv;
    int redirect;
    char *input_file;
    char *output_file;
    int pipefd;
    int lastpipe;
} command_t;

int is_space(int c);
char* get_input(void);
void sigint(int signum);
alias_t *initalias(void);
void print_prompt(char** env);
int my_file_exists(char *path);
int history_buildin(char* home);
void lexer_free(lexer_t* lexer);
void lexer_init(lexer_t* lexer);
int *list_alias(alias_t *alias);
void change_pipe(command_t *cmd);
void free_cursor(cursor_t *cursor);
linked_list_t *init_env(char** env);
int print_env(linked_list_t *my_env);
int get_env(linked_list_t *linked_list);
int aliases(char **args, alias_t *alias);
int alias_loop(char *str, alias_t *alias);
void pipe_red(command_t *cmd, int *pipefd);
int unaliases(char **args, alias_t *alias);
void add_alias(char **args, alias_t *alias);
void save_command(char *command, char *home);
int mini_shell(int ac, char **av, char **env);
void ignore_to_non_whitespace(cursor_t *cursor);
void exit_status(int status, linked_list_t **env);
char **transform_argv(char **args, alias_t *alias);
int exit_builtin(char** args, linked_list_t **env);
int echo_buidin(char** args, linked_list_t** my_env);
void lexer_add_token(lexer_t *lexer, Token_t *token);
int unset_env(linked_list_t **linked_list, char *key);
void lexer_add_pipe(lexer_t *lexer, cursor_t* cursor);
int change_directory(char** args, linked_list_t **env);
int cursor_peek(cursor_t *cursor, int *line, int *col);
int cursor_next(cursor_t *cursor, int *line, int *col);
void init_cursor_from_str(cursor_t *cursor, char* str);
int check_alias(char *cmd, char **args, alias_t *alias);
void less_than(command_t *cmd, lexer_t *lexer, size_t i);
void lexer_add_separator(lexer_t *lexer, cursor_t* cursor);
void lexer_add_ampersand(lexer_t *lexer, cursor_t* cursor);
void lexer_add_less_that(lexer_t *lexer, cursor_t* cursor);
void greate_than(command_t *cmd, lexer_t *lexer, size_t i);
void double_less(command_t *cmd, lexer_t *lexer, size_t i);
char **linked_list_to_word_array(linked_list_t *linked_list);
void lexer_add_greater_that(lexer_t *lexer, cursor_t* cursor);
int set_env(linked_list_t **linked_list,char *key, char *value);
void lexer_add_args(lexer_t *lexer, cursor_t* cursor, string_t* buf);
void run_lexer(char* response, linked_list_t** myenv, alias_t *alias);
void lexer_add_string(lexer_t *lexer, cursor_t* cursor, string_t* buf);
void run_parser(lexer_t* lexer, linked_list_t** myenv, alias_t *alias);
void exec_command_by_child(command_t cmd, linked_list_t **env, int *pipefd,
alias_t *alias);
#endif
