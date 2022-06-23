/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** menu
*/

#include "../include/proj.h"

static const float upscaled_button = 1.2;

void destroy_main_menu(game_t *game)
{
    if (game->menu.is_loaded == true) {
        sfSprite_destroy(game->menu.back.sprite);
        sfTexture_destroy(game->menu.back.texture);
        sfSprite_destroy(game->menu.start_button.sprite);
        sfTexture_destroy(game->menu.start_button.texture);
        sfSprite_destroy(game->menu.settings_button.sprite);
        sfTexture_destroy(game->menu.settings_button.texture);
        sfSprite_destroy(game->menu.exit_button.sprite);
        sfTexture_destroy(game->menu.exit_button.texture); 
        destroy_player(game);
        destroy_enemy(game);
        game->rpg.player.is_loaded = false;
    }
}

void create_main_menu_sprite(game_t *game)
{
    create_sprite("assets/sprites/background.jpg", &game->menu.back.sprite, &game->menu.back.texture, NULL);
    create_sprite("assets/sprites/mm_newgame.png", &game->menu.start_button.sprite, &game->menu.start_button.texture, &game->menu.start_button.pos);
    create_sprite("assets/sprites/mm_option.png", &game->menu.settings_button.sprite, &game->menu.settings_button.texture, &game->menu.settings_button.pos);
    create_sprite("assets/sprites/mm_load.png", &game->menu.load_game.sprite, &game->menu.load_game.texture, &game->menu.load_game.pos);
    create_sprite("assets/sprites/mm_exit.png", &game->menu.exit_button.sprite, &game->menu.exit_button.texture, &game->menu.exit_button.pos);
}

void scale_main_menu_sprite(game_t *game)
{
    sfVector2f increase_button_size = {upscaled_button, upscaled_button};

    if (game->menu.start_button.is_scaled == true)
        sfSprite_setScale(game->menu.start_button.sprite, increase_button_size);
    else
        sfSprite_setScale(game->menu.start_button.sprite, (sfVector2f){1, 1});
    if (game->menu.load_game.is_scaled == true)
        sfSprite_setScale(game->menu.load_game.sprite, increase_button_size);
    else
        sfSprite_setScale(game->menu.load_game.sprite, (sfVector2f){1, 1});
    if (game->menu.settings_button.is_scaled == true)
        sfSprite_setScale(game->menu.settings_button.sprite, increase_button_size);
    else
        sfSprite_setScale(game->menu.settings_button.sprite, (sfVector2f){1, 1});
    if (game->menu.exit_button.is_scaled == true)
        sfSprite_setScale(game->menu.exit_button.sprite, increase_button_size);
    else
        sfSprite_setScale(game->menu.exit_button.sprite, (sfVector2f){1, 1});
}

void draw_sprite_menu_sprite(game_t *game)
{
    sfRenderWindow_drawSprite(game->game, game->menu.back.sprite, NULL);
    sfRenderWindow_drawSprite(game->game, game->menu.start_button.sprite, NULL);
    sfRenderWindow_drawSprite(game->game, game->menu.load_game.sprite, NULL);
    sfRenderWindow_drawSprite(game->game, game->menu.settings_button.sprite, NULL);
    sfRenderWindow_drawSprite(game->game, game->menu.exit_button.sprite, NULL);
}

void do_main_menu(game_t *game)
{
    game->is_loaded = true;
    game->menu.start_button.pos = (sfVector2f) {100, 100};
    game->menu.load_game.pos = (sfVector2f) {100, 300};
    game->menu.settings_button.pos = (sfVector2f) {100, 500};
    game->menu.exit_button.pos = (sfVector2f) {100, 700};

    if (game->pause.is_paused == true)
        game->pause.is_paused = false;
    if (game->settings.is_loaded == true) {
        destroy_settings(game);
        game->settings.is_loaded = false;
    }
    if (game->rpg.is_loaded == true) {
        destroy_rpg(game);
        game->rpg.player.is_loaded = false;
        game->rpg.is_loaded = false;
    }
    if (game->menu.is_loaded == false) {
        create_main_menu_sprite(game);
        game->menu.is_loaded = true;
    }
    if (game->game_over.is_loaded == true) {
        destroy_game_over_menu(game);
        game->game_over.is_loaded = false;
    }
    if (game->rpg.camera_is_loaded == true)
        reset_camera(game);
    scale_main_menu_sprite(game);
    draw_sprite_menu_sprite(game);
}
