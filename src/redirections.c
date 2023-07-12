/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** redirections
*/
#include "../include/my.h"
#include "../include/mysh.h"

static void double_less_than(command_t *cmd)
{
    cmd->redirect = 0; char output[4096];
    int size = strlen(cmd->input_file); int ot_size = 0;
    while (1) {
        printf("? ");
        char *line = NULL;
        size_t len = 0;
        ssize_t read = getline(&line, &len, stdin);
        if (read == -1 || my_strncmp(cmd->input_file, line, size) == 0)
            break;
        for (int i = 0; line[i]; i++, ot_size++)
            output[ot_size] = line[i];
    } output[ot_size] = '\0';
    int fd = open("/tmp/aaa", O_WRONLY | O_CREAT, 0644);
    write(fd, output, strlen(output));
    close(fd);
    int input_fd = open("/tmp/aaa", O_RDONLY);
    int stdin_copy = dup(STDIN_FILENO);
    dup2(input_fd, STDIN_FILENO);
    close(input_fd);
    close(stdin_copy); remove("/tmp/aaa");
}

static void red_less_than(command_t *cmd)
{
    cmd->redirect = 0;
    fflush(stdin);
    int input_fd = open(cmd->input_file, O_RDONLY);
    int stdin_copy = dup(STDIN_FILENO);
    dup2(input_fd, STDIN_FILENO);
    close(input_fd);
    close(stdin_copy);
}

static void greater_than(command_t *cmd)
{
    fflush(stdout);
    if (cmd->redirect == Token_Greater_That * 2) {
        int new_stdout_fd = open(cmd->output_file,
        O_WRONLY | O_APPEND | O_CREAT, 0644);
        if (new_stdout_fd != -1) {
            dup2(new_stdout_fd, STDOUT_FILENO);
            close(new_stdout_fd);
        }
    } if (cmd->redirect == Token_Greater_That) {
        int new_stdout_fd = open(cmd->output_file,
        O_WRONLY | O_TRUNC | O_CREAT, 0644);
        if (new_stdout_fd != -1) {
            dup2(new_stdout_fd, STDOUT_FILENO);
            close(new_stdout_fd);
        }
    }
}

void pipe_red(command_t *cmd, int *pipefd)
{
    if (cmd->redirect != Token_Pipe && cmd->redirect != Token_Pipe * 2)
        return;
    if (cmd->redirect == Token_Pipe * 2) {
        close(pipefd[1]);
        dup2(pipefd[0], STDIN_FILENO);
        close(pipefd[0]);
        return;
    } if (cmd->redirect == Token_Pipe) {
        close(pipefd[0]);
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[1]);
    }
}

void change_pipe(command_t *cmd)
{
    if (cmd->redirect == 0)
        return;
    if (cmd->redirect == 666) {
        dup2(cmd->pipefd, STDOUT_FILENO);
        close(cmd->pipefd);
        return;
    }
    if (cmd->redirect == 7 || cmd->redirect == 7 * 2) {
        greater_than(cmd);
    }
    if (cmd->redirect == Token_Less_That) {
        red_less_than(cmd);
    }
    if (cmd->redirect == Token_Less_That * 2) {
        double_less_than(cmd);
    }
    if (cmd->redirect == 7 || cmd->redirect == Token_Greater_That * 2)
        cmd->redirect = 666;
}
