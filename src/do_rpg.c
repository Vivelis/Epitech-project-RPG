/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-mickael1.peireto
** File description:
** do_rpg
*/

#include "proj.h"

void destroy_rpg(game_t *game)
{
    destroy_sprite(&game->rpg.back.sprite, &game->rpg.back.texture);
    destroy_step_particles(&game->rpg.steps);
    destroy_blood_particles(&game->rpg.blood);
    destroy_player(game);
}

void display_rpg_sprite(game_t *game)
{
    sfRenderWindow_drawSprite(game->game, game->rpg.back.sprite, NULL);
}

void do_rpg(game_t *game, map_t *map)
{
    if (game->rpg.is_loaded == false)
        game->rpg.is_loaded = true;
    if (game->menu.is_loaded == true) {
        destroy_main_menu(game);
        game->menu.is_loaded = false;
    }
    if (game->pause.is_loaded == true) {
        destroy_pause_menu(game);
        game->pause.is_loaded = false;
    }
    if (game->status_menu.is_loaded == true) {
        destroy_status_menu(game);
        game->status_menu.is_loaded = false;
    }
    if (game->cursor_is_visible == true)
        game->cursor_is_visible = false;
    display_map(game->game, map);
    event_manage_player(game);
    manage_player(game);
    manage_camera(game);
    display_steps(game, &game->rpg.steps);
    manage_enemy(game);
    manage_damage(game);
    generate_blood(game, &game->rpg.blood);
    display_msg(game->game, game);
    create_and_display_heal(game);
    display_player(game);
    display_blood(game, &game->rpg.blood);
    game->pause.is_paused = false;
}
