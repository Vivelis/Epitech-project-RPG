/*
** EPITECH PROJECT, 2021
** pile-file
** File description:
** qcs_utility.c
*/

#include <stdio.h>
#include <unistd.h>

static size_t qcs_getstrlen(char const *str)
{
    size_t cmpt = 0;

    if (str == NULL)
        return 0;
    while (str[cmpt] != '\0')
        cmpt++;
    return cmpt;
}

int qcs_puterror(const char *error, int output)
{
    int len = 0;

    if (!error) {
        write(2, "error: missing str for my_puterror\n", 36);
        return 84;
    }
    len = qcs_getstrlen(error);
    write(2, error, len);
    return output;
}
