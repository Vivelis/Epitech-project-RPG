/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-mickael1.peireto
** File description:
** manage_camera
*/

#include "../include/proj.h"

void manage_camera(game_t *game)
{
    game->rpg.camera.camera = sfView_create();
    sfView_setCenter(game->rpg.camera.camera, sfSprite_getPosition(game->rpg.player.sprite));
    sfView_setSize(game->rpg.camera.camera, (sfVector2f){1920, 1080});
    sfView_zoom(game->rpg.camera.camera, 0.5f);
    sfRenderWindow_setView(game->game, game->rpg.camera.camera);
    game->rpg.camera_is_loaded = true;
}

void reset_camera(game_t *game)
{
    sfView_setCenter(game->rpg.camera.camera, (sfVector2f){1920 / 2, 1080 / 2});
    sfView_setSize(game->rpg.camera.camera, (sfVector2f){1920, 1080});
    sfView_zoom(game->rpg.camera.camera, 1);
    sfRenderWindow_setView(game->game, game->rpg.camera.camera);
}