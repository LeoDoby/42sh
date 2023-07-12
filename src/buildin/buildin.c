/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** buildin.c
*/
#include "../../include/my.h"
#include "../../include/mysh.h"
#include "mylist.h"
#include <string.h>
#include <errno.h>

static int is_accessible(char** args)
{
    if (!args[1] || args[1][0] == '-' || args[1][0] == '~' || (args[1][0] ==
    '.' && args[1][1] == '.'))
        return 0;
    if (args[1] && args[2] != NULL) {
        my_putstr("cd: Too many arguments.\n");
        return 1;
    }
    if (chdir(args[1])) {
        my_putstr(args[1]);
        my_putstr(": ");
        my_putstr(strerror(errno));
        my_putstr(".\n");
        return 1;
    }
    return 0;
}

int change_directory(char** args, linked_list_t **env)
{
    if (is_accessible(args))
        return 1;
    char *pwd = NULL;
    char *old = my_strdup(get_env_value(linked_list_to_word_array(*env),
        "OLDPWD"));
    if (!args[1] || (args[1][0] == '~' && args[1][1] == '\0'))
        chdir(get_env_value(linked_list_to_word_array(*env), "HOME"));
    if (args[1] && args[1][0] != '-')
        chdir(args[1]);
    if (args[1] && args[1][0] == '-' && !args[1][1])
        chdir(old);
    set_env(env,"OLDPWD", get_env_value(linked_list_to_word_array(*env),
        "PWD"));
    set_env(env,"PWD", getcwd(pwd, 0));
    free(old);
    free(pwd);
    return 1;
}
