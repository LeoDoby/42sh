/*
** EPITECH PROJECT, 2023
** alias
** File description:
** exit_status
*/
#include "../include/my.h"
#include "../include/mysh.h"
#include "mylist.h"
#include <sys/wait.h>

int exit_builtin(char** args, linked_list_t **env)
{
    set_env(env, "exit_status", args[1] ? args[1] : "0");
    set_env(env, "exit", "exit");
    return 0;
}

void exit_status(int status, linked_list_t **env)
{
    if (WTERMSIG(status) == SIGSEGV)
        my_putstr("Segmentation fault");
    if (WTERMSIG(status) == SIGFPE && status & FPE_INTDIV) {
        if (status & FPE_INTDIV) {
            my_putstr("Division by zero error");
        } else {
            my_putstr("Floating-point exception");
        }
    }
    if (WCOREDUMP(status))
        my_putstr(" (core dumped)");
    if (!WIFEXITED(status))
        my_putchar('\n');
    set_env(env, "exit_status", int_to_str(WEXITSTATUS(status)));
}
