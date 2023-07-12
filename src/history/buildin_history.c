/*
** EPITECH PROJECT, 2023
** save_command.c
** File description:
** B-PSU-200-LIL-2-1-42sh-lucas.doolaeghe
*/

#include "../../include/my.h"
#include "../../include/mysh.h"

int history_buildin(char *home)
{
    char c;
    char *path = malloc(sizeof(char) * (my_strlen(home) + 15));
    int fd = -1;
    sprintf(path, "%s/.42sh_history", home);
    if (my_strcmp(path, "NULL/.42sh_history") == 0)
        return 0;
    fd = open(path, O_RDONLY);
    if (fd == -1)
        return 0;
    while (read(fd, &c, sizeof(char)) > 0) {
        printf("%c", c);
    }
    close(fd);
    free(path);
    return 0;
}
