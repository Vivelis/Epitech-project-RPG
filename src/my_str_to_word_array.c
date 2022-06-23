/*
** EPITECH PROJECT, 2022
** Lib
** File description:
** Str_to_word_array
*/

#include <stdio.h>
#include <stdlib.h>

// @brief This function return a string copied from a given string using
// a starting index and an ending index.
// @param str The string to copy from.
// @param start The starting index.
// @param end The ending index.
// @return A string copied from the given string.
static char *my_word_copy(char *str, int start, int end)
{
    char *str_copy = NULL;
    int i = 0;

    str_copy = malloc(sizeof(char) * (end - start + 2));
    if (str_copy == NULL)
        return (NULL);
    for (int cnt = start; cnt < end; cnt++) {
        str_copy[i] = str[cnt];
        i++;
    }
    str_copy[i] = '\0';
    return (str_copy);
}

// @brief This function will return the index of the next word
// @param *str The string to analyze
// @param delim : the delimiter
// @param current_index the actual index of the word 
// @return int index of the next word
static int next_index_finder(char *str, char delim, int current_i)
{
    int i = current_i;

    while (str[i] != '\0' && str[i] != delim)
        i++;
    return (i);
}

// @brief: This function will return the number to mallocs for the array
// @param: char *str
// @param: char delim
// @return: int
static int my_word_count(char *str, char delim)
{
    if (str == NULL)
        return (0);

    int i = 0;
    int count = 0;

    while (str[i] != '\0') {
        if (str[i] == delim)
            count++;
        i++;
    }
    return (count + 1);
}

// @brief : This function splits a string into an array of words.
// @param : char *str : The string to split.
// @param : char delim : The delimiter.
// @return : char ** : The array of words.
char **my_str_to_word_array(char *str, char delim)
{
    char **array = NULL;
    int to_malloc = 0;
    int i = 0;
    int r = 0;
    int j = 0;

    if ((to_malloc = my_word_count(str, delim)) == 0)
        return (NULL);
    array = malloc(sizeof(char *) * (to_malloc + 1));
    if (array == NULL)
        return (NULL);
    for (int cnt = 0; cnt < to_malloc; cnt++) {
        r = next_index_finder(str, delim, i);
        array[j] = my_word_copy(str, i, r);
        i = r + 1;
        j++;
    }
    array[to_malloc] = NULL;
    return (array);
}
