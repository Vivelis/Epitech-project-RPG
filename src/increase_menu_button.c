/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** increase_menu_button
*/

#include "../include/proj.h"

void detect_if_button_pressed_menu(game_t *game, sfSprite *sprite, int status)
{
    sfVector2f pos = sfSprite_getPosition(sprite);
    sfVector2f size = {220, 40};
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->game);
    sfVector2f mouse_pos_rel = {mouse_pos.x - pos.x, mouse_pos.y - pos.y};

    if (mouse_pos_rel.x >= 0 && mouse_pos_rel.x <= size.x &&
    mouse_pos_rel.y >= 0 && mouse_pos_rel.y <= size.y && status == 1) {
        game->status = rpg;
        sfSound_setBuffer(game->sound, game->sound_click);
        sfSound_play(game->sound);
    }
    else if (mouse_pos_rel.x >= 0 && mouse_pos_rel.x <= size.x &&
    mouse_pos_rel.y >= 0 && mouse_pos_rel.y <= size.y && status == 2) {
        game->status = settings;
        sfSound_setBuffer(game->sound, game->sound_click);
        sfSound_play(game->sound);
    }
        
    else if(mouse_pos_rel.x >= 0 && mouse_pos_rel.x <= size.x &&
    mouse_pos_rel.y >= 0 && mouse_pos_rel.y <= size.y && status == 3) {
        game->status = quit;
        sfSound_setBuffer(game->sound, game->sound_click);
        sfSound_play(game->sound);
    }
}

void increase_start(game_t *game)
{
    sfVector2f pos = sfSprite_getPosition(game->menu.start_button.sprite);
    sfVector2f size = {220, 40};
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->game);
    sfVector2f mouse_pos_rel = {mouse_pos.x - pos.x, mouse_pos.y - pos.y};

    if (mouse_pos_rel.x >= 0 && mouse_pos_rel.x <= size.x &&
    mouse_pos_rel.y >= 0 && mouse_pos_rel.y <= size.y)
        game->menu.start_button.is_scaled = true;
    else
        game->menu.start_button.is_scaled = false;
}

void increase_load(game_t *game)
{
    sfVector2f pos = sfSprite_getPosition(game->menu.load_game.sprite);
    sfVector2f size = {220, 40};
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->game);
    sfVector2f mouse_pos_rel = {mouse_pos.x - pos.x, mouse_pos.y - pos.y};

    if (mouse_pos_rel.x >= 0 && mouse_pos_rel.x <= size.x &&
    mouse_pos_rel.y >= 0 && mouse_pos_rel.y <= size.y)
        game->menu.load_game.is_scaled = true;
    else
        game->menu.load_game.is_scaled = false;
}

void increase_settings(game_t *game)
{
    sfVector2f pos = sfSprite_getPosition(game->menu.settings_button.sprite);
    sfVector2f size = {220, 40};
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->game);
    sfVector2f mouse_pos_rel = {mouse_pos.x - pos.x, mouse_pos.y - pos.y};

    if (mouse_pos_rel.x >= 0 && mouse_pos_rel.x <= size.x &&
    mouse_pos_rel.y >= 0 && mouse_pos_rel.y <= size.y)
        game->menu.settings_button.is_scaled = true;
    else
        game->menu.settings_button.is_scaled = false;
}

void increase_exit(game_t *game)
{
    sfVector2f pos = sfSprite_getPosition(game->menu.exit_button.sprite);
    sfVector2f size = {220, 40};
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->game);
    sfVector2f mouse_pos_rel = {mouse_pos.x - pos.x, mouse_pos.y - pos.y};

    if (mouse_pos_rel.x >= 0 && mouse_pos_rel.x <= size.x &&
    mouse_pos_rel.y >= 0 && mouse_pos_rel.y <= size.y)
        game->menu.exit_button.is_scaled = true;
    else
        game->menu.exit_button.is_scaled = false;
}