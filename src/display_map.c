/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** display the map
*/

#include "proj.h"

// @brief return the index of a char in a string
// @param c the char to find
// @param str the string to search
static int get_spr_index(char c, char *str)
{
    for (int cnt = 0; str[cnt] != '\0'; cnt++) {
        if (str[cnt] == c)
            return (cnt);
    }
    return (-1);
}

// @brief display the map->map selected char
// @param rpg the window
// @param map_t *map
// @param y the y position
// @param x the x position
// @return void
static void display_index(sfRenderWindow *rpg, map_t *map, int y, int x)
{
    int spr_i = 0;
    sfVector2f coord = {(x * 80), (y * 80)};
    sfVector2f scale = {1, 1};

    spr_i = get_spr_index(map->map[y][x], map->char_list);
    if (spr_i == -1)
        return;
    sfSprite_setScale(map->spr[spr_i], scale);
    sfSprite_setPosition(map->spr[spr_i], coord);
    sfSprite_setTexture(map->spr[spr_i], map->tex[spr_i], sfFalse);
    sfRenderWindow_drawSprite(rpg, map->spr[spr_i], NULL);
}

// @brief display the map->special selected char
// @param rpg the window
// @param map_t *map
// @param y the y position
// @param x the x position
// @return void
static void display_special(sfRenderWindow *rpg, map_t *map, int y, int x)
{
    int spr_i = 0;
    sfVector2f coord = {(x * 80), (y * 80)};
    sfVector2f scale = {1, 1};

    spr_i = get_spr_index(map->special[y][x], map->char_list);
    if (spr_i == -1)
        return;
    sfSprite_setScale(map->spr[spr_i], scale);
    sfSprite_setPosition(map->spr[spr_i], coord);
    sfSprite_setTexture(map->spr[spr_i], map->tex[spr_i], sfFalse);
    sfRenderWindow_drawSprite(rpg, map->spr[spr_i], NULL);
}

// @brief display the whole map
// @param rpg the window
// @param map_t *map the structure of the map
void display_map(sfRenderWindow *Rpg, map_t *map)
{
    for (int x = 0, y = 0; map->map[y]; x++) {
        if (map->map[y][x] == '\0') {
            y++;
            x = -1;
        } else {
            display_index(Rpg, map, y, x);
        }
    }
    for (int x = 0, y = 0; map->special[y]; x++) {
        if (map->special[y][x] == '\0') {
            y++;
            x = -1;
        } else {
            display_special(Rpg, map, y, x);
        }
    }
}
