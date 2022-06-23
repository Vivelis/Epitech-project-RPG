/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-mickael1.peireto
** File description:
** manage_button_settings
*/

#include "../include/proj.h"

void disable_sound(game_t *game)
{
    if (game->sound == NULL)
        return;
    if (sfSound_getVolume(game->sound) == 100) {
        sfSound_setVolume(game->sound, 0);
        game->settings.sound_is_checked = false;
    } else if (sfSound_getVolume(game->sound) == 0) {
        sfSound_setVolume(game->sound, 100);
        game->settings.sound_is_checked = true;
    }
}

void disable_musique(game_t *game)
{
    if (sfMusic_getStatus(game->music) == sfPlaying) {
        sfMusic_pause(game->music);
        game->settings.music_is_checked = false;
    }
    else if (sfMusic_getStatus(game->music) == sfPaused) {
        sfMusic_play(game->music);
        game->settings.music_is_checked = true;
    }
}

void detect_if_button_pressed_settings(game_t *game, sfSprite *sprite, int status)
{
    sfVector2f pos = sfSprite_getPosition(sprite);
    sfVector2f size = {50, 50};
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->game);
    sfVector2f mouse_pos_rel = {mouse_pos.x - pos.x, mouse_pos.y - pos.y};

    if (mouse_pos_rel.x >= 0 && mouse_pos_rel.x <= size.x &&
    mouse_pos_rel.y >= 0 && mouse_pos_rel.y <= size.y && status == 1) {
        disable_sound(game);
    }
    else if (mouse_pos_rel.x >= 0 && mouse_pos_rel.x <= size.x &&
    mouse_pos_rel.y >= 0 && mouse_pos_rel.y <= size.y && status == 2)
        disable_musique(game);
    else if (mouse_pos_rel.x >= 0 && mouse_pos_rel.x <= size.x &&
    mouse_pos_rel.y >= 0 && mouse_pos_rel.y <= size.y && status == 3) {
        if (game ->framerate >= 240)
            game->framerate = 60;
        else 
            game->framerate += 60;
    }
    else if (mouse_pos_rel.x >= 0 && mouse_pos_rel.x <= size.x &&
    mouse_pos_rel.y >= 0 && mouse_pos_rel.y <= size.y && status == 4) {
        sfRenderWindow_destroy(game->game);
        create_window_fullscreen(game);
    }
}