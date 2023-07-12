/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** prompt_file.c
*/

#include "../include/my.h"
#include "../include/mysh.h"

void print_prompt(char** env)
{
    if (isatty(0)) {
        if (*env == NULL) {
            my_putstr("$>");
            return;
        } else {
            char cwd[512];
            my_putchar('[');
            my_putstr(get_env_value(env, "USER"));
            my_putchar('@');
            my_putstr(get_env_value(env, "HOSTNAME"));
            my_putchar(' ');
            my_putstr(getcwd(cwd, sizeof(cwd)));
            my_putstr("]$ ");
        }
    }
}
