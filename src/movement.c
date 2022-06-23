/*
** EPITECH PROJECT, 2022
** My_rpg
** File description:
** the player movement handler
*/

#include "proj.h"

// @brief move the player up
// @param game the game struct
// @return void
static void player_go_up(game_t *game)
{
    sfSprite_move(game->rpg.player.sprite, (sfVector2f){0, -5});
    game->rpg.saved_pos_player = sfSprite_getPosition(game->rpg.player.sprite);
    game->rpg.saved_pos_player = game->rpg.player.pos;
    game->rpg.col_co.y = game->rpg.col_co.y - 5;
    game->rpg.last_direction = 1;
    anim_sprite(game, &game->rpg.player, &game->rpg.player_anim.walk_up);
}

// @brief move the player down
// @param game the game struct
// @return void
static void player_go_down(game_t *game)
{
    sfSprite_move(game->rpg.player.sprite, (sfVector2f){0, 5});
    game->rpg.saved_pos_player = sfSprite_getPosition(game->rpg.player.sprite);
    game->rpg.saved_pos_player = game->rpg.player.pos;
    game->rpg.col_co.y = game->rpg.col_co.y + 5;
    game->rpg.last_direction = 2;
    anim_sprite(game, &game->rpg.player, &game->rpg.player_anim.walk_down);
}

// @brief move the player left
// @param game the game struct
// @return void
static void player_go_left(game_t *game)
{
    sfSprite_move(game->rpg.player.sprite, (sfVector2f){-5, 0});
    game->rpg.saved_pos_player = sfSprite_getPosition(game->rpg.player.sprite);
    game->rpg.saved_pos_player = game->rpg.player.pos;
    game->rpg.col_co.x = game->rpg.col_co.x - 5;
    game->rpg.last_direction = 3;
    anim_sprite(game, &game->rpg.player, &game->rpg.player_anim.walk_left);
}

// @brief move the player right
// @param game the game struct
// @return void
static void player_go_right(game_t *game)
{
    sfSprite_move(game->rpg.player.sprite, (sfVector2f){5, 0});
    game->rpg.saved_pos_player = sfSprite_getPosition(game->rpg.player.sprite);
    game->rpg.saved_pos_player = game->rpg.player.pos;
    game->rpg.col_co.x = game->rpg.col_co.x + 5;
    game->rpg.last_direction = 4;
    anim_sprite(game, &game->rpg.player, &game->rpg.player_anim.walk_right);
}

// @brief call the static movement depending on status
// @param game the game struct
// @param status : 1 for up, 2 for down, 3 for left, 4 for right
void player_movement(game_t *game, int status)
{
    game->msg.is_displayed = 0;
    if (status == 1) {
        player_go_up(game);
    }
    if (status == 2) {
        player_go_down(game);
    }
    if (status == 3) {
        player_go_left(game);
    }
    if (status == 4) {
        player_go_right(game);
    }
}
