/*
** EPITECH PROJECT, 2021
** B-MUL-200-TLS-2-1-myrpg-mickael1.peireto
** File description:
** read_file.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include "c_list.h"
#include "manage_file.h"

char *read_line(FILE *fd)
{
    size_t size = 0;
    char *buffer = NULL;
    ssize_t errorh = 0;

    errorh = getline(&buffer, &size, fd);
    if (errorh <= 0) {
        free(buffer);
        return NULL;
    }
    return buffer;
}

c_list_t *read_file(char *path)
{
    FILE *fd = NULL;
    c_list_t *buffer = NULL;
    char *line = NULL;

    fd = open_file(path, "r");
    if (fd == NULL)
        return NULL;
    buffer = init_list();
    if (buffer == NULL) {
        fclose(fd);
        return NULL;
    }
    do {
        line = read_line(fd);
        put_on_list(buffer, line);
    } while (line != NULL);
    fclose(fd);
    return buffer;
}
