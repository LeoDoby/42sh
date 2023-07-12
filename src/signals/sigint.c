/*
** EPITECH PROJECT, 2023
** sigint.c
** File description:
** B-PSU-200-LIL-2-1-42sh-lucas.doolaeghe
*/
#include "../../include/mysh.h"
#include "../../include/my.h"
#include <signal.h>

void sigint(int signum)
{
    if (signum == SIGINT) {
        my_putchar('\n');
        my_putstr("$>");
    }
}
