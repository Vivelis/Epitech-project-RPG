/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-mickael1.peireto
** File description:
** my_itoa
*/

#include "my.h"
#include <stdlib.h>

char *my_itoa(int num)
{
    int i = 0;
    int stock = 0;
    char *str;

    str = malloc(100);
    if (num == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }
    while (num != 0) {
        stock = num % 10;
        num /= 10;
        str[i] = stock + 48;
        i++;
    }
    str[i] = '\0';
    my_revstr(str);
    return str;
}