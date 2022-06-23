/*
** EPITECH PROJECT, 2022
** My_rpg
** File description:
** Errorhandling for the getmap
*/

#include "proj.h"

// @brief verify the file extension
// @param path the path of the file
// @return 1 if the file as a good extension else 0
int is_good_file_extension(char *path)
{
    int index = 0;

    index = find_a_char_index(path, '.');
    if (index == -1) {
        my_putstr("The file extension is missing\n");
        return (0);
    }
    if (index + 4 != my_strlen(path)) {
        my_putstr("The file extension is not good\n");
        return (0);
    }
    if (my_strcmp(path + index, ".png") != 0 && my_strcmp(path + index, ".jpg") != 0) {
        my_putstr("The file extension is not good\n");
        return (0);
    }
    return (1);
}

// @brief verify if the assets is good
// @param tje path of the assets
// @return 84 if the assets is wrong
int is_it_good_assets(char *path)
{
    if (does_file_exist(path) == 0)
        return (84);
    if (is_good_file_extension(path) == 0) {
        my_putstr(path);
        my_putstr(": Wrong file extension\n");
        return (84);
    }
    return 0;
}

// @brief Verify is the map is playable
// @param *map the map to verify
// @return 84 is the map is unplayable
int check_error_map(map_t *map)
{
    int cnt = 0;

    if (map->whole_array == NULL || str_count(map->whole_array) != 4)
        return (84);
    if (map->char_list == NULL || map->path_list == NULL)
        return (84);
    if (map->line_lenght == 0)
        return (84);
    for (; map->char_list[cnt] != '\0'; cnt++) {
        if (map->char_list[cnt] == '\n' || map->path_list[cnt] == NULL)
            return (84);
        if (is_it_good_assets(map->path_list[cnt]) == 84)
            return (84);
    }
    if (map->walkable == NULL || map->not_walkable == NULL)
        return (84);
    return (0);
}
