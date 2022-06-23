/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** options
*/

#include "../include/proj.h"

void destroy_settings(game_t *game)
{
    destroy_sprite(&game->settings.back.sprite, &game->settings.back.texture);
    destroy_sprite(&game->settings.sound.sprite, &game->settings.sound.texture);
    destroy_sprite(&game->settings.music.sprite, &game->settings.music.texture);
    destroy_sprite(&game->settings.framerate.sprite, &game->settings.framerate.texture);
    destroy_sprite(&game->settings.fullscreen_button.sprite, &game->settings.fullscreen_button.texture);
    destroy_sprite(&game->settings.music_checked.sprite, &game->settings.music_checked.texture);
    destroy_sprite(&game->settings.sound_checked.sprite, &game->settings.sound_checked.texture);
    sfText_destroy(game->settings.music_text.text);
    sfText_destroy(game->settings.sound_text.text);
    sfText_destroy(game->settings.framerate_text.text);
    sfText_destroy(game->settings.fullscreen_text.text);
}

void create_settings_sprite(game_t *game)
{
    create_text("assets/fonts/font.ttf", &game->settings.framerate_text.text, &game->settings.framerate_text.font, &game->settings.framerate_text.pos);
    create_text("assets/fonts/font.ttf", &game->settings.fullscreen_text.text, &game->settings.fullscreen_text.font, &game->settings.fullscreen_text.pos);
    create_text("assets/fonts/font.ttf", &game->settings.music_text.text, &game->settings.music_text.font, &game->settings.music_text.pos);
    create_text("assets/fonts/font.ttf", &game->settings.sound_text.text, &game->settings.sound_text.font, &game->settings.sound_text.pos);
    create_sprite("assets/sprites/background.jpg", &game->settings.back.sprite, &game->settings.back.texture, NULL);
    create_sprite("assets/sprites/non-checked.png", &game->settings.sound.sprite, &game->settings.sound.texture, &game->settings.sound.pos);
    create_sprite("assets/sprites/non-checked.png", &game->settings.music.sprite, &game->settings.music.texture, &game->settings.music.pos);
    create_sprite("assets/sprites/checked.png", &game->settings.music_checked.sprite, &game->settings.music_checked.texture, &game->settings.music.pos);
    create_sprite("assets/sprites/checked.png", &game->settings.sound_checked.sprite, &game->settings.sound_checked.texture, &game->settings.sound.pos);
    create_sprite("assets/sprites/non-checked.png", &game->settings.fullscreen_button.sprite, &game->settings.fullscreen_button.texture, &game->settings.fullscreen_button.pos);
    create_sprite("assets/sprites/checked.png", &game->settings.fullscreen_button_checked.sprite, &game->settings.fullscreen_button_checked.texture, &game->settings.fullscreen_button.pos);
    create_sprite("assets/sprites/arrow.png", &game->settings.change_framerate.sprite, &game->settings.change_framerate.texture, &game->settings.change_framerate.pos);
    center_origin_sp(game->settings.change_framerate.sprite);
    sfSprite_rotate(game->settings.change_framerate.sprite, 180);
}

void scale_setting_sprite(game_t *game)
{
    sfSprite_setScale(game->settings.sound.sprite, (sfVector2f) {0.1, 0.1});
    sfSprite_setScale(game->settings.music.sprite, (sfVector2f) {0.1, 0.1});
    sfSprite_setScale(game->settings.fullscreen_button.sprite, (sfVector2f) {0.1, 0.1});
    sfSprite_setScale(game->settings.change_framerate.sprite, (sfVector2f) {0.2, 0.2});
    if (game->settings.music_is_checked == true)
        sfSprite_setScale(game->settings.music_checked.sprite, (sfVector2f) {0.05, 0.05});
    if (game->is_fullscreen == true)
        sfSprite_setScale(game->settings.fullscreen_button_checked.sprite, (sfVector2f) {0.05, 0.05});
    if (game->settings.sound_is_checked == false)
        sfSprite_setScale(game->settings.sound_checked.sprite, (sfVector2f) {0.05, 0.05});
}

void render_setting_sprite(game_t *game)
{
    char str1[20] = "Framerate : ";
    char *str2 = my_itoa(game->framerate);
    my_strcat(str1, str2);
    sfText_setString(game->settings.framerate_text.text, str1);
    sfText_setString(game->settings.fullscreen_text.text, "Fullscreen : ");
    sfText_setString(game->settings.music_text.text, "Music : ");
    sfText_setString(game->settings.sound_text.text, "Sound : ");
    sfRenderWindow_drawSprite(game->game, game->settings.back.sprite, NULL);
    sfRenderWindow_drawSprite(game->game, game->settings.sound.sprite, NULL);
    sfRenderWindow_drawSprite(game->game, game->settings.music.sprite, NULL);
    sfRenderWindow_drawSprite(game->game, game->settings.fullscreen_button.sprite, NULL);
    sfRenderWindow_drawSprite(game->game, game->settings.change_framerate.sprite, NULL);
    sfRenderWindow_drawText(game->game, game->settings.framerate_text.text, NULL);
    sfRenderWindow_drawText(game->game, game->settings.fullscreen_text.text, NULL);
    sfRenderWindow_drawText(game->game, game->settings.music_text.text, NULL);
    sfRenderWindow_drawText(game->game, game->settings.sound_text.text, NULL);
    if (game->settings.music_is_checked == 1)
        sfRenderWindow_drawSprite(game->game, game->settings.music_checked.sprite, NULL);
    if (game->is_fullscreen == 1)
        sfRenderWindow_drawSprite(game->game, game->settings.fullscreen_button_checked.sprite, NULL);
    if (game->settings.sound_is_checked == false)
        sfRenderWindow_drawSprite(game->game, game->settings.sound_checked.sprite, NULL);
}

void do_settings(game_t *game)
{
    game->settings.sound.pos = (sfVector2f) {800, 500};
    game->settings.music.pos = (sfVector2f) {800, 400};
    game->settings.fullscreen_button.pos = (sfVector2f) {800, 200};
    game->settings.fullscreen_text.pos = (sfVector2f) {500, 200};
    game->settings.framerate_text.pos = (sfVector2f) {500, 300};
    game->settings.music_text.pos = (sfVector2f) {500, 400};
    game->settings.sound_text.pos = (sfVector2f) {500, 500};
    game->settings.change_framerate.pos = (sfVector2f) {850, 320};

    if (game->menu.is_loaded == true) {
        destroy_main_menu(game);
        game->menu.is_loaded = false;
    }
    if (game->pause.is_loaded == true) {
        destroy_pause_menu(game);
        game->pause.is_loaded = false;
    }
    if (game->settings.is_loaded == false) {
        create_settings_sprite(game);
        game->settings.music_is_checked = true;
        game->settings.is_loaded = true;
    }
    if (game->rpg.camera_is_loaded == true) {
        reset_camera(game);
    }
    scale_setting_sprite(game);
    render_setting_sprite(game);
}