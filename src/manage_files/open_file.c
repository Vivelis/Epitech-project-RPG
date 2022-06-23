/*
** EPITECH PROJECT, 2021
** B-MUL-200-TLS-2-1-myrpg-mickael1.peireto
** File description:
** open_file.c
*/

#include <stdio.h>

FILE *open_file(const char *pathname, const char *mode)
{
    FILE *fd = NULL;

    fd = fopen(pathname, mode);
    return fd;
}


