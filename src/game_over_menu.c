/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-mickael1.peireto
** File description:
** game_over_menu
*/

#include "proj.h"

void detect_if_button_game_over_pressed(game_t *game, sfSprite *sprite)
{
    sfVector2f pos = sfSprite_getPosition(sprite);
    sfVector2f size = {220, 40};
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->game);
    sfVector2f mouse_pos_rel = {mouse_pos.x - pos.x, mouse_pos.y - pos.y};

    if (mouse_pos_rel.x >= 0 && mouse_pos_rel.x <= size.x &&
    mouse_pos_rel.y >= 0 && mouse_pos_rel.y <= size.y) {
        game->status = main_menu;
    }
}

void event_game_over_menu(game_t *game, sfEvent event)
{
    if (event.type == sfEvtMouseButtonPressed && event.mouseButton.button == sfMouseLeft && game->status == game_over) {
        detect_if_button_game_over_pressed(game, game->game_over.sprite);
    }
}

void destroy_game_over_menu(game_t *game)
{
    sfSprite_destroy(game->game_over.sprite);
    sfTexture_destroy(game->game_over.texture);
    sfText_destroy(game->game_over.text);
    sfFont_destroy(game->game_over.font);
}

void game_over_menu(game_t *game)
{
    sfVector2f pos = {1920 / 2 - 220 / 2, 1080 / 2 - 70 / 2};
    if (game->rpg.camera_is_loaded == true)
        reset_camera(game);
    if (game->cursor_is_visible == false)
        game->cursor_is_visible = true;
    if (game->game_over.is_loaded == false) {
        create_sprite("./assets/sprites/ig_exit.png", &game->game_over.sprite, &game->game_over.texture, &pos);
        create_text("./assets/fonts/font.ttf", &game->game_over.text, &game->game_over.font, &(sfVector2f){1920 / 2 - 125, 1080 / 2 - 200});
        sfRenderWindow_clear(game->game, sfBlack);
        game->game_over.is_loaded = true;
    }
    sfText_setString(game->game_over.text, "GAME OVER");
    sfText_setCharacterSize(game->game_over.text, 40);
    sfRenderWindow_drawText(game->game, game->game_over.text, NULL);
    sfRenderWindow_drawSprite(game->game, game->game_over.sprite, NULL);
}