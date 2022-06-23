/*
** EPITECH PROJECT, 2022
** My_rpg
** File description:
** Map_handler
*/

#include "proj.h"

// @brief set the sprite and texture of the map
// @param *map the struct to set the sprite and texture
// @return void
void get_map_spr(map_t *map)
{
    sfVector2f scale = {0, 0};

    map->spr = malloc(sizeof(sfSprite *) * my_strlen(map->char_list));
    map->tex = malloc(sizeof(sfTexture *) * my_strlen(map->char_list));
    map->scale = scale;
    for (int cnt = 0; map->char_list[cnt] != '\0'; cnt++) {
        map->spr[cnt] = sfSprite_create();
        map->tex[cnt] = sfTexture_createFromFile(map->path_list[cnt], NULL);
    }
}

// @brief open a file with a path using stat for the malloc
// @param path the path of the file
// @return the file
// @return NULL if the file doesn't exist
// @return NULL if the file is empty
map_t new_map(char *path)
{
    map_t map;
    struct stat st;
    int fd = open(path, O_RDONLY);
    int size = 0;

    if (fd == -1)
        return (map);
    stat(path, &st);
    size = st.st_size;
    map.whole_file = malloc(sizeof(char) * (size + 1));
    read(fd, map.whole_file, size);
    map.whole_file[size] = '\0';
    get_everything(&map);
    return (map);
}

int find_a_char_index(char *path, char char_to_find)
{
    int cnt = 0;

    for (; path[cnt] != '\0'; cnt++) {
        if (path[cnt] == char_to_find)
            return (cnt);
    }
    return -1;
}

// int main(char *path)
// {
//     map_t map = new_map(path);
//     if (check_error_map(&map) == 84)
//         return (84);
//     get_spr(&map);
//     return (0);
// }
