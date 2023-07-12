/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** exec_utils.c
*/

#include "../include/my.h"
#include "../include/mysh.h"
#include <errno.h>
#include "mylist.h"
#include <sys/wait.h>
#include <unistd.h>
#include <sys/stat.h>

int cmd_permissions(char *path)
{
    struct stat st;
    stat(path, &st);
    if (access(path, R_OK) == -1 || S_ISDIR(st.st_mode)) {
        my_put_error(path);
        my_put_error(": Permission denied.\n");
        return 1;
    }
    if (access(path, F_OK) == -1 ) {
        my_put_error(path);
        my_put_error(": Command not found.\n");
        return 1;
    }
    if (access(path, X_OK) == -1) {
        my_put_error(path);
        my_put_error(": Permission denied.\n");
        return 1;
    }
    return 0;
}

static void to_run(char* full_path, command_t cmd, linked_list_t *env)
{
    if (cmd_permissions(full_path))
        exit(1);
    int status = execve(full_path, cmd.argv, linked_list_to_word_array(env));

    if (errno == ENOEXEC) {
        my_put_error(full_path);
        my_put_error(": Exec format error. Wrong Architecture.\n");
        exit(1);
    }
    exit(status);
}

static void exec_path(command_t cmd, linked_list_t *env)
{
    if (cmd.redirect == 21 || my_file_exists(cmd.argv[0]))
        return;
    if (my_file_exists(cmd.argv[0]))
        to_run(cmd.argv[0], cmd, env);
    char **PATH = my_str_to_word_array(get_env_value
            (linked_list_to_word_array(env), "PATH"), ":");
    int size = my_array_size((void**)PATH);
    for (int i = 0; i < size; ++i) {
        char *full_path = malloc(sizeof(char) * (my_strlen(cmd.argv[0]) +
            my_strlen(PATH[i]) + 2));
            sprintf(full_path, "%s/%s", PATH[i],cmd.argv[0]);
        if (my_file_exists(full_path))
            to_run(full_path, cmd, env);
        free(full_path);
    }
    dprintf(2, "%s: Command not found.\n", cmd.argv[0]);
}

static int exec_build_in(char* cmd, char** args, linked_list_t **env,
alias_t *alias)
{
    if (!my_strcmp(cmd, "echo"))
        return echo_buidin(args, env);
    if (!my_strcmp(cmd, "cd"))
        return !change_directory(args, env);
    if (!my_strcmp(cmd, "env") || (!my_strcmp(cmd, "setenv") && my_array_size
        ((void**)args) == 1))
        return get_env(*env);
    if (!my_strcmp(cmd, "setenv"))
        return set_env(env, args[1], args[2] ? args[2] : "");
    if (!my_strcmp(cmd, "unsetenv"))
        return unset_env(env, args[1]);
    if (!my_strcmp(cmd, "history"))
        return history_buildin(get_env_value(linked_list_to_word_array(*env),
        "HOME"));
    if (!my_strcmp(cmd, "alias") || !my_strcmp(cmd, "unalias"))
        return check_alias(cmd, args, alias);
    if (!my_strcmp(cmd, "exit")) {
        return exit_builtin(args, env);
    }
    return 2;
}

void exec_command_by_child(command_t cmd, linked_list_t **env, int *pipefd,
alias_t *alias)
{
    int status; pid_t pid = 0;
    change_pipe(&cmd);
    if (alias_loop(cmd.argv[0], alias) == 1)
        return;
    cmd.argv = transform_argv(cmd.argv, alias);
    if (!exec_build_in(cmd.argv[0], cmd.argv, env, alias))
        return;
    pid = fork();
    if (pid == 0) {
        pipe_red(&cmd, pipefd);
        exec_path(cmd, *env);
        exit(0);
    } if (cmd.redirect == Token_Pipe * 2) {
        close(pipefd[0]);
        close(pipefd[1]);
    } change_pipe(&cmd);
    if (pid > 0) {
        pid = wait(&status);
        exit_status(status, env);
    }
}
