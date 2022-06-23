/*
** EPITECH PROJECT, 2022
** My_rpg
** File description:
** Function used in the main getmap fonc
*/

#include "proj.h"

// @brief get the char and their path
// @param map_t *map
// @return void
void get_char_path_list(map_t *map)
{
    char **array = NULL;
    char **array2 = NULL;
    int cnt = 0;

    array = my_str_to_word_array(map->whole_array[0], '\n');
    map->char_list = malloc(sizeof(char*) * (my_strlen(array[0]) + 1));
    map->path_list = malloc(sizeof(char*) * (my_strlen(array[0]) + 1));
    for (; array[cnt] != NULL; cnt++) {
        array2 = my_str_to_word_array(array[cnt], '=');
        if (str_count(array2) != 2) {
            map->char_list[cnt] = '\0';
            map->path_list[cnt] = '\0';
            return;
        }
        map->char_list[cnt] = array2[0][0];
        map->path_list[cnt] = my_strdup(array2[1]);
    }
    map->char_list[cnt] = '\0';
    map->path_list[cnt] = NULL;
}

// @brief get the background map and the overmap
// @param map_t *map
// @return void
void get_map_special(map_t *map)
{
    map->map = my_str_to_word_array(map->whole_array[2], '\n');
    map->special = my_str_to_word_array(map->whole_array[3], '\n');
}

// @brief get the char in which you can walk and those where you can't
// @param map_t *map
// @return void
void get_walk_unwalk(map_t *map)
{
    char **array = NULL;
    char **array2 = NULL;

    array = my_str_to_word_array(map->whole_array[1], '\n');
    if (array == NULL || str_count(array) != 2)
        return;
    array2 = my_str_to_word_array(array[0], '=');
    if (array2 == NULL || str_count(array2) != 2) {
        map->walkable = NULL;
        return;
    }
    map->walkable = my_strdup(array2[1]);
    array2 = my_str_to_word_array(array[1], '=');
    if (array2 == NULL || str_count(array2) != 2) {
        map->not_walkable = NULL;
        return;
    }
    map->not_walkable = my_strdup(array2[1]);
}

// @brief verify the lenght of all line and set line_lenght at 0 if so
// @param map_t the whole map struct
void get_all_line(map_t *map)
{
    for (int cnt = 0; map->map[cnt] != NULL; cnt++) {
        if (cnt == 0) {
            map->line_lenght = my_strlen(map->map[cnt]);
        }
        if (map->line_lenght != my_strlen(map->map[cnt])) {
            my_putnbr(map->line_lenght);
            my_putstr("Error: line is not the same lenght as other:");
            my_putnbr(cnt);
            map->line_lenght = 0;
            return;      
        }
        if (map->special[cnt] && map->line_lenght != my_strlen(map->special[cnt])) {
            map->line_lenght = 0;
            return;
        }
    }
    map->number_of_line = str_count(map->map);
}

// @brief Fill all the map_t struct
// @param map_t *map
// @return void
void get_everything(map_t *map)
{
    map->whole_array = my_str_to_word_array(map->whole_file, 'L');
    if (map->whole_array == NULL || str_count(map->whole_array) != 4)
        return;
    get_char_path_list(map);
    get_map_special(map);
    get_walk_unwalk(map);
    get_all_line(map);
}
