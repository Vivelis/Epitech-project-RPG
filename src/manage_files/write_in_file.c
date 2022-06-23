/*
** EPITECH PROJECT, 2021
** B-MUL-200-TLS-2-1-myrpg-mickael1.peireto
** File description:
** write_in_file.c
*/


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "../../include/my.h"

int writestr_file(char *path, char *buffer)
{
    int fd = 0;
    int errorh = 0;

    fd = open(path, O_CREAT | O_WRONLY | O_APPEND, S_IRWXU);
    if (fd == -1) {
        return my_puterror("write_in_file: can't open file.\n", 84);
    }
    errorh = write(fd, buffer, my_strlen(buffer));
    if (errorh < 0) {
        close(fd);
        return my_puterror("write_in_file: can't write.\n", 84);
    }
    close(fd);
    return 0;
}

int writeint_file(char *path, int nbr)
{
    int fd = 0;
    int errorh = 0;

    fd = open(path, O_CREAT | O_WRONLY | O_APPEND, S_IRWXU);
    if (fd == -1) {
        return my_puterror("write_in_file: can't open file.\n", 84);
    }
    errorh = write(fd, &nbr, sizeof(int));
    if (errorh < 0) {
        close(fd);
        return my_puterror("write_in_file: can't write.\n", 84);
    }
    close(fd);
    return 0;
}

int writechar_file(char *path, char character)
{
    int fd = 0;
    int errorh = 0;

    fd = open(path, O_CREAT | O_WRONLY | O_APPEND, S_IRWXU);
    if (fd == -1) {
        return my_puterror("write_in_file: can't open file.\n", 84);
    }
    errorh = write(fd, &character, sizeof(char));
    if (errorh < 0) {
        close(fd);
        return my_puterror("write_in_file: can't write.\n", 84);
    }
    close(fd);
    return 0;
}
