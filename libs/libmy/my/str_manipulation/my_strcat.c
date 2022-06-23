/*
** EPITECH PROJECT, 2021
** my_strcat
** File description:
** concatenate two strings
*/

#include "../../headers/my.h"
#include <stddef.h>

char *my_strcat(char *dest, char const *src)
{
    int index_dest = 0;
    int index_src = 0;

    while (dest[index_dest] != '\0') {
        index_dest++;
    }
    while (src[index_src] != '\0') {
        dest[index_dest] = src[index_src];
        index_dest++;
        index_src++;
    }
    dest[index_dest] = '\0';
    return dest;
}

char *my_strcatm(char **dest, char *src)
{
    char *result = NULL;
    long index = 0;
    long src_index = 0;
    long len = 0;

    len = my_strlen(*dest);
    len += my_strlen(src);
    if (src == NULL)
        return *dest;
    if (*dest == NULL)
        return src;
    if (do_strmalloc(&result, len) == 84)
        return NULL;
    for (; (*dest)[index] != '\0'; index++)
        result[index] = (*dest)[index];
    for (; src[src_index] != '\0'; src_index++)
        result[index + src_index] = src[src_index];
    result[index + src_index] = '\0';
    free(*dest);
    *dest = result;
    return result;
}
