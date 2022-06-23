/*
** EPITECH PROJECT, 2022
** Lib
** File description:
** My_str_to_word_array, str_count, str_split
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my.h"

// @brief function that return the number of string in an array
// @param str the array to count
// @return the number of string in the array
int str_count(char **str)
{
    int cnt = 0;

    for (int i = 0; str[i] != NULL; i++)
        cnt++;
    return (cnt);
}

// @brief transform a string into an array of two string using a delimiter
// @param str the string to transform
// @param delim the delimiting character
// @return the array of string
char **my_str_split(char *str, char delim)
{
    char **array = NULL;
    
    if (str == NULL)
        return (NULL);
    array = malloc(sizeof(char*) * 3);
    if (array == NULL)
        return (NULL);
    array[0] = malloc(sizeof(char) * (my_strlen(str) + 1));
    array[1] = malloc(sizeof(char) * (my_strlen(str) + 1));
    for(int cnt = 0, x = 0, y = 0; str[cnt] != '\0'; cnt++) {
        if (str[cnt] == delim && x == 0) {
            x++;
            y = 0;
        } else {
            array[x][y] = str[cnt];
            y++;
        }
    }
    return (array);
}
