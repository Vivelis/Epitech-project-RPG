/*
** EPITECH PROJECT, 2022
** My_rpg
** File description:
** Interact with the item in front of you
*/

#include "proj.h"

static void interact_up(game_t *game)
{
    int pos_x = 0;
    int pos_y = 0;

    pos_x = ((int)game->rpg.col_co.x / 80);
    pos_y = ((int)game->rpg.col_co.y / 80);
    if (pos_x < 0 || pos_y < 0)
        return;
    if (pos_y - 1 < 0)
        return;
    if (game->map.special[pos_y - 1][pos_x] == 'i')
       mushroom_interaction(game, pos_y - 1, pos_x);
    if (game->map.special[pos_y - 1][pos_x] == 'v')
        pnj_quest_interaction(game);
    if (game->map.special[pos_y - 1][pos_x] == 'a')
        help_interaction(game);
    return;
}

static void interact_down(game_t *game)
{
    int pos_x = 0;
    int pos_y = 0;

    pos_x = ((int)game->rpg.col_co.x / 80);
    pos_y = ((int)game->rpg.col_co.y / 80);
    if (pos_x < 0 || pos_y < 0)
        return;
    if (pos_y + 1 > game->map.number_of_line)
        return;
    if (game->map.special[pos_y + 1][pos_x] == 'i')
        mushroom_interaction(game, pos_y + 1, pos_x);
    if (game->map.special[pos_y + 1][pos_x] == 'v')
        pnj_quest_interaction(game);
    if (game->map.special[pos_y + 1][pos_x] == 'a')
        help_interaction(game);
    return;
}

static void interact_left(game_t *game)
{
    int pos_x = 0;
    int pos_y = 0;

    pos_x = ((int)game->rpg.col_co.x / 80);
    pos_y = ((int)game->rpg.col_co.y / 80);
    if (pos_x < 0 || pos_y < 0)
        return;
    if (pos_x - 1 < 0)
        return;
    if (game->map.special[pos_y][pos_x - 1] == 'i')
        mushroom_interaction(game, pos_y, pos_x - 1);
    if (game->map.special[pos_y][pos_x - 1] == 'v')
        pnj_quest_interaction(game);
    if (game->map.special[pos_y][pos_x - 1] == 'a')
        help_interaction(game);
    return;
}

static void interact_right(game_t *game)
{
    int pos_x = 0;
    int pos_y = 0;

    pos_x = ((int)game->rpg.col_co.x / 80);
    pos_y = ((int)game->rpg.col_co.y / 80);
    if (pos_x < 0 || pos_y < 0)
        return;
    if (pos_x + 1 > game->map.line_lenght)
        return;
    if (game->map.special[pos_y][pos_x + 1] == 'i')
        mushroom_interaction(game, pos_y, pos_x + 1);
    if (game->map.special[pos_y][pos_x + 1] == 'v')
        pnj_quest_interaction(game);
    if (game->map.special[pos_y][pos_x + 1] == 'a')
        pnj_quest_interaction(game);
    return;
}


void get_in_front_of_you(game_t *game)
{
    if (game->rpg.last_direction == 1)
        interact_up(game);
    if (game->rpg.last_direction == 2)
        interact_down(game);
    if (game->rpg.last_direction == 3)
        interact_left(game);
    if (game->rpg.last_direction == 4)
        interact_right(game);
}
