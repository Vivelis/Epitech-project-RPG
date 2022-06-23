/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-mickael1.peireto
** File description:
** pause_menu
*/

#include "../include/proj.h"

static const float upscaled_button = 1.2;

void destroy_pause_menu(game_t *game)
{
    destroy_sprite(&game->pause.back.sprite, &game->pause.back.texture);
    destroy_sprite(&game->pause.resume_button.sprite, &game->pause.resume_button.texture);
    destroy_sprite(&game->pause.save_button.sprite, &game->pause.save_button.texture);
    destroy_sprite(&game->pause.settings_button.sprite, &game->pause.settings_button.texture);
    destroy_sprite(&game->pause.exit_button.sprite, &game->pause.exit_button.texture);

}

void create_pause_menu_sprite(game_t *game)
{
    create_sprite("assets/sprites/pause.png", &game->pause.back.sprite, &game->pause.back.texture, &game->pause.back.pos);
    create_sprite("assets/sprites/ig_resume.png", &game->pause.resume_button.sprite, &game->pause.resume_button.texture, &game->pause.resume_button.pos);
    create_sprite("assets/sprites/ig_save.png", &game->pause.save_button.sprite, &game->pause.save_button.texture, &game->pause.save_button.pos);
    create_sprite("assets/sprites/ig_option.png", &game->pause.settings_button.sprite, &game->pause.settings_button.texture, &game->pause.settings_button.pos);
    create_sprite("assets/sprites/ig_exit.png", &game->pause.exit_button.sprite, &game->pause.exit_button.texture, &game->pause.exit_button.pos);
}

void draw_sprite_pause_menu_sprite(game_t *game)
{
    display_map(game->game, &game->map);
    sfRenderWindow_drawSprite(game->game, game->pause.back.sprite, NULL);
    sfRenderWindow_drawSprite(game->game, game->pause.resume_button.sprite, NULL);
    sfRenderWindow_drawSprite(game->game, game->pause.save_button.sprite, NULL);
    sfRenderWindow_drawSprite(game->game, game->pause.settings_button.sprite, NULL);
    sfRenderWindow_drawSprite(game->game, game->pause.exit_button.sprite, NULL);
}

void scale_pause_menu_sprite(game_t *game)
{
    sfVector2f increase_button_size = {upscaled_button, upscaled_button};

    if (game->pause.resume_button.is_scaled == true)
        sfSprite_setScale(game->pause.resume_button.sprite, increase_button_size);
    else
        sfSprite_setScale(game->pause.resume_button.sprite, (sfVector2f){1, 1});
    if (game->pause.save_button.is_scaled == true)
       sfSprite_setScale(game->pause.save_button.sprite, increase_button_size);
    else
       sfSprite_setScale(game->pause.save_button.sprite, (sfVector2f){1, 1});
    if (game->pause.settings_button.is_scaled == true)
        sfSprite_setScale(game->pause.settings_button.sprite, increase_button_size);
    else
        sfSprite_setScale(game->pause.settings_button.sprite, (sfVector2f){1, 1});
    if (game->pause.exit_button.is_scaled == true)
        sfSprite_setScale(game->pause.exit_button.sprite, increase_button_size);
    else
        sfSprite_setScale(game->pause.exit_button.sprite, (sfVector2f){1, 1});
}

void pause_menu_fun(game_t *game)
{
    sfVector2f pos = sfSprite_getPosition(game->rpg.player.sprite);
    game->pause.back.pos = (sfVector2f) {pos.x - 250, pos.y - 400};
    game->pause.resume_button.pos =  (sfVector2f) {game->pause.back.pos.x + 120, game->pause.back.pos.y + 250};
    game->pause.save_button.pos =  (sfVector2f) {game->pause.back.pos.x + 120, game->pause.back.pos.y + 350};
    game->pause.settings_button.pos =  (sfVector2f) {game->pause.back.pos.x + 120, game->pause.back.pos.y + 450};
    game->pause.exit_button.pos =  (sfVector2f) {game->pause.back.pos.x + 120, game->pause.back.pos.y + 550};

    if (game->cursor_is_visible == false)
        game->cursor_is_visible = true;
    if (game->settings.is_loaded == true) {
        destroy_settings(game);
        game->settings.is_loaded = false;
    }
    if (game->pause.is_loaded == false) {
        create_pause_menu_sprite(game);
        game->pause.is_loaded = true;
    }
    sfView_setCenter(game->rpg.camera.camera, pos);
    sfView_setSize(game->rpg.camera.camera, (sfVector2f){1920, 1080});
    sfView_zoom(game->rpg.camera.camera, 1);
    sfRenderWindow_setView(game->game, game->rpg.camera.camera);
    scale_pause_menu_sprite(game);
    draw_sprite_pause_menu_sprite(game);
    game->pause.is_paused = true;
}