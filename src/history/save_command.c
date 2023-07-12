/*
** EPITECH PROJECT, 2023
** save_command.c
** File description:
** B-PSU-200-LIL-2-1-42sh-lucas.doolaeghe
*/
#include "../../include/my.h"
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

int get_command_len(int fd)
{
    char c = -1;
    int len = 0;
    if (fd == -1)
        return 0;
    while (read(fd, &c, sizeof(char)) > 0) {
        if (c == '\n') {
            len++;
        }
    }
    close(fd);
    return len;
}

void save_command(char *command, char *home)
{
    time_t current_time;
    struct tm * time_info;
    char *path = malloc(sizeof(char) * (my_strlen(home) + 15));
    char *time_str = malloc(sizeof(char) * 6);
    int fd = -1;
    int command_id = 0;
    time(&current_time);
    time_info = localtime(&current_time);
    strftime(time_str, 6, "%H:%M", time_info);
    sprintf(path, "%s/.42sh_history", home);
    if (my_strcmp(path, "NULL/.42sh_history") == 0)
        return;
    command_id = get_command_len(open(path, O_RDONLY));
    fd = open(path, O_CREAT | O_WRONLY | O_APPEND, 0666);
    if (fd == -1)
        return;
    dprintf(fd, "%6i  %s   %s\n", command_id, time_str, command);
    close(fd);
    free(path);
}
