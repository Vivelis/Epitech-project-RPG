/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-mickael1.peireto
** File description:
** manage_player
*/

#include "proj.h"

void destroy_player(game_t *game)
{
    destroy_sprite(&game->rpg.player.sprite, &game->rpg.player.texture);
    if (game->rpg.player_anim.walk_left.pos_array) {
        free(game->rpg.player_anim.walk_left.pos_array);
        game->rpg.player_anim.walk_left.pos_array = NULL;
    }
    if (game->rpg.player_anim.walk_right.pos_array) {
        free(game->rpg.player_anim.walk_right.pos_array);
        game->rpg.player_anim.walk_right.pos_array = NULL;
    }
    if (game->rpg.player_anim.walk_up.pos_array) {
        free(game->rpg.player_anim.walk_up.pos_array);
        game->rpg.player_anim.walk_up.pos_array = NULL;
    }
    if (game->rpg.player_anim.walk_down.pos_array) {
        free(game->rpg.player_anim.walk_down.pos_array);
        game->rpg.player_anim.walk_down.pos_array = NULL;
    }
}

void event_manage_player(game_t *game)
{
    set_player_idle_anim(game);
    if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue && can_move(game, 0, -5) == 1)
        player_movement(game, 1);
    if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue && can_move(game, 0, 5 + PLAYERHEIGHT) == 1)
        player_movement(game, 2);
    if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue && can_move(game, -5, 0) == 1)
        player_movement(game, 3);
    if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue && can_move(game, 5 + PLAYERWIDTH, 0) == 1)
        player_movement(game, 4);
    if (game->msg.is_displayed == 0 && sfKeyboard_isKeyPressed(sfKeyP) == sfTrue) {
        get_in_front_of_you(game);
    }
}

void manage_player(game_t *game)
{
    game->rpg.player.pos = (sfVector2f) {960, 540};

    if (game->rpg.saved_pos_player.x != 0 || game->rpg.saved_pos_player.y != 0)
        game->rpg.player.pos = game->rpg.saved_pos_player;
    if (game->rpg.player.is_loaded == false) {
        game->rpg.player.rect = (sfIntRect){0, 0, 16, 16};
        create_sprite(PLAYER_SPRITE_FILE, &game->rpg.player.sprite, &game->rpg.player.texture, &game->rpg.player.pos);
        sfSprite_setTextureRect(game->rpg.player.sprite, game->rpg.player.rect);
        sfSprite_setScale(game->rpg.player.sprite, (sfVector2f){2.5, 2.5});
        set_player_anim(game);
        game->rpg.player.is_loaded = true;
    }
    if (game->stats.hp <= 0){
        game->status = game_over;
    }
    generate_step(game, &game->rpg.steps);
}

void display_player(game_t *game)
{
    sfRenderWindow_drawSprite(game->game, game->rpg.player.sprite, NULL);
}
