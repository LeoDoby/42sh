/*
** EPITECH PROJECT, 2023
** mini_shell2.c
** File description:
** B-PSU-200-LIL-2-1-minishell2-lucas.doolaeghe
*/

#include "../include/my.h"
#include "../include/mysh.h"
#include "mylist.h"
#include <signal.h>

char *get_input(void)
{
    char *response = NULL;
    size_t len = 0;
    if (getline(&response, &len, stdin) < 0) {
        if (isatty(0))
            my_putstr("exit\n");
        free(response);
        return NULL;
    }
    if (response[my_strlen(response) - 1] == '\n')
        response[my_strlen(response) - 1] = 0;
    return response;
}

int cmd_input(linked_list_t **my_env, alias_t *alias)
{
    char *response = NULL;
    char **env = linked_list_to_word_array(*my_env);
    print_prompt(env);
    response = get_input();
    if (response == NULL){
        set_env(my_env, "exit", "exit");
        return 0;
    }
    if (my_strcmp(response, "") != 0)
        save_command(response, get_env_value(env, "HOME"));
    free(env);
    run_lexer(response, my_env, alias);
    free(response);
    return 1;
}

int mini_shell(__attribute__((unused))int ac, __attribute__((unused)) char
**av, char **env)
{
    int exit_code = 0;
    signal(SIGINT, sigint);
    alias_t *alias = initalias();
    linked_list_t *my_env = my_params_to_list(my_array_size((void**)env), env);
    while (cmd_input(&my_env, alias) && my_strcmp(get_env_value
    (linked_list_to_word_array(my_env), "exit"), "exit")) {
        exit_code = my_getnbr(get_env_value(linked_list_to_word_array(my_env),
        "exit_status"));
    };
    my_free_linked_list(&my_env);
    return exit_code;
}
