/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** my_file_exists.c
*/
#include <fcntl.h>
#include <unistd.h>

int my_file_exists(char *path)
{
    int fd = open(path, O_RDONLY);
    if (fd == -1)
        return 0;
    close(fd);
    return 1;
}
