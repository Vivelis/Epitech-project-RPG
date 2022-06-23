/*
** EPITECH PROJECT, 2022
** My_rpg
** File description:
** Check the colision
*/

#include "proj.h"

// @brief return if the tile is walkable
// @param the map struct
// @param c the character of normal map
// @param d the character of special map
// @return TRUE if the tile is walkable, FALSE if not
int is_it_walkable(map_t *map, char c, char d)
{
    for (int cnt = 0; map->not_walkable[cnt]; cnt++)
        if (map->not_walkable[cnt] == d || map->not_walkable[cnt] == c) {
            return (0);
        }
    return (1);
}

// @brief Verify if the player is beetween two cases and if he can walk
// @param game the game struct
// @param pos the player position
// @param index the case index
// @param direction 1 for up/down 2 for left/right
// @return 1 if the player can walk, 0 otherwise
int check_those_colision(game_t *game, sfVector2i pos, sfVector2i index, int dir)
{
    if (dir == 1) {
        if (pos.x % 80 + PLAYERHEIGHT > 80) {
            if (is_it_walkable(&game->map, game->map.map[index.y][index.x], game->map.special[index.y][index.x]) == 1 && is_it_walkable(&game->map, game->map.map[index.y][index.x + 1], game->map.special[index.y][index.x + 1]) == 1)
                return (1);
            return (0);
        }
        return (is_it_walkable(&game->map, game->map.map[index.y][index.x], game->map.special[index.y][index.x]));
    }
    if (dir == 2) {
        if (pos.y % 80 + PLAYERWIDTH > 80) {
            if (is_it_walkable(&game->map, game->map.map[index.y][index.x], game->map.special[index.y][index.x]) == 1 && is_it_walkable(&game->map, game->map.map[index.y + 1][index.x], game->map.special[index.y + 1][index.x]) == 1)
                return (1);
            return (0);
        }
        return (is_it_walkable(&game->map, game->map.map[index.y][index.x], game->map.special[index.y][index.x]));
    }
    return (0);
}

// @brief get the direction of the player
// @param game the game struct
// @param x the x position of where the player is going 
// @return 1 for up/down 2 for left/right
int get_direction(int x)
{
    if (x == 0)
        return (1);
    return (2);
}

// @brief return if i can move on the tile
// @param the game struct
// @param the x coordinate
// @param the y coordinate
// @return 1 if i can move on the tile, 0 if not
int can_move(game_t *game, int x, int y)
{
    sfVector2i pos = {0, 0};
    sfVector2i index = {0, 0};

    pos.x = (int)game->rpg.col_co.x + x;
    pos.y = (int)game->rpg.col_co.y + y;
    if (pos.x < 0 || pos.y < 0)
        return (0);
    index.x = pos.x / 80;
    index.y = pos.y / 80;
    if (index.x < 0 || index.x >= game->map.line_lenght ||
    index.y < 0 || index.y >= game->map.number_of_line)
        return 0;
    return (check_those_colision(game, pos, index, get_direction(x)));
}
