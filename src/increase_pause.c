/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-mickael1.peireto
** File description:
** increase_pause
*/

#include "proj.h"
#include "manage_file.h"

void detect_if_button_pressed_pause(game_t *game, sfSprite *sprite, int status)
{
    sfVector2f pos = sfSprite_getPosition(sprite);
    sfVector2f size = {240, 70};
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->game);
    sfVector2f mouse_pos_rel = {mouse_pos.x - pos.x, mouse_pos.y - pos.y};

    if (mouse_pos_rel.x >= 0 && mouse_pos_rel.x <= size.x &&
    mouse_pos_rel.y >= 0 && mouse_pos_rel.y <= size.y && status == 1)
        game->status = rpg;
    else if (mouse_pos_rel.x >= 0 && mouse_pos_rel.x <= size.x &&
    mouse_pos_rel.y >= 0 && mouse_pos_rel.y <= size.y && status == 2)
        save_game(game, "p1");
    else if(mouse_pos_rel.x >= 0 && mouse_pos_rel.x <= size.x &&
    mouse_pos_rel.y >= 0 && mouse_pos_rel.y <= size.y && status == 3) {
        game->status = settings;
        game->pause.is_paused = true;
    }
    else if(mouse_pos_rel.x >= 0 && mouse_pos_rel.x <= size.x &&
    mouse_pos_rel.y >= 0 && mouse_pos_rel.y <= size.y && status == 4)
        game->status = main_menu;
}

void increase_resume(game_t *game)
{
    sfVector2f pos;
    sfVector2f size = {240, 70};
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->game);
    sfVector2f mouse_pos_rel;

    if (game->pause.resume_button.sprite == NULL)
        return;
    pos = sfSprite_getPosition(game->pause.resume_button.sprite);
    mouse_pos_rel.x = mouse_pos.x - pos.x;
    mouse_pos_rel.y = mouse_pos.y - pos.y;
    if (mouse_pos_rel.x >= 0 && mouse_pos_rel.x <= size.x &&
    mouse_pos_rel.y >= 0 && mouse_pos_rel.y <= size.y)
        game->pause.resume_button.is_scaled = true;
    else
        game->pause.resume_button.is_scaled = false;
}

void increase_save(game_t *game)
{
    sfVector2f pos;
    sfVector2f size = {240, 70};
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->game);
    sfVector2f mouse_pos_rel;

    if (game->pause.save_button.sprite == NULL)
        return;
    pos = sfSprite_getPosition(game->pause.save_button.sprite);
    mouse_pos_rel.x = mouse_pos.x - pos.x;
    mouse_pos_rel.y = mouse_pos.y - pos.y;
    if (mouse_pos_rel.x >= 0 && mouse_pos_rel.x <= size.x &&
    mouse_pos_rel.y >= 0 && mouse_pos_rel.y <= size.y)
        game->pause.save_button.is_scaled = true;
    else
        game->pause.save_button.is_scaled = false;
}

void increase_settings_pause(game_t *game)
{
    sfVector2f pos;
    sfVector2f size = {240, 70};
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->game);
    sfVector2f mouse_pos_rel;

    if (game->pause.settings_button.sprite == NULL)
        return;
    pos = sfSprite_getPosition(game->pause.settings_button.sprite);
    mouse_pos_rel.x = mouse_pos.x - pos.x;
    mouse_pos_rel.y = mouse_pos.y - pos.y;
    if (mouse_pos_rel.x >= 0 && mouse_pos_rel.x <= size.x &&
    mouse_pos_rel.y >= 0 && mouse_pos_rel.y <= size.y)
        game->pause.settings_button.is_scaled = true;
    else
        game->pause.settings_button.is_scaled = false;
}

void increase_exit_pause(game_t *game)
{
    sfVector2f pos;
    sfVector2f size = {240, 70};
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->game);
    sfVector2f mouse_pos_rel;

    if (game->pause.exit_button.sprite == NULL)
        return;
    pos = sfSprite_getPosition(game->pause.exit_button.sprite);
    mouse_pos_rel.x = mouse_pos.x - pos.x;
    mouse_pos_rel.y = mouse_pos.y - pos.y;
    if (mouse_pos_rel.x >= 0 && mouse_pos_rel.x <= size.x &&
    mouse_pos_rel.y >= 0 && mouse_pos_rel.y <= size.y)
        game->pause.exit_button.is_scaled = true;
    else
        game->pause.exit_button.is_scaled = false;
}
