/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-mickael1.peireto
** File description:
** manage_enemy
*/

#include "proj.h"

void destroy_enemy(game_t *game)
{
    for (int i = 0; i != 6; i++) {
        destroy_sprite(&game->rpg.enemy[i].sprite.sprite, &game->rpg.enemy[i].sprite.texture);
        game->rpg.enemy[i].is_loaded = false;
    }
}

void create_enemy(game_t *game)
{
    for (int i = 0; i != 6; i++) {
        create_sprite("assets/sprites/npc.png", &game->rpg.enemy[i].sprite.sprite , &game->rpg.enemy[i].sprite.texture, &game->rpg.enemy[i].sprite.pos);
        sfSprite_setTextureRect(game->rpg.enemy[i].sprite.sprite, (sfIntRect){0, 0, 16, 16});
        sfSprite_setScale(game->rpg.enemy[i].sprite.sprite, (sfVector2f){2, 2});
        game->rpg.enemy[i].life = 20;
        game->rpg.enemy[i].is_alive = true;
    }
}

void render_enemy(game_t *game)
{
    if (game->rpg.enemy[0].is_alive == true)
        sfRenderWindow_drawSprite(game->game, game->rpg.enemy[0].sprite.sprite, NULL);
    if (game->rpg.enemy[1].is_alive == true)
        sfRenderWindow_drawSprite(game->game, game->rpg.enemy[1].sprite.sprite, NULL);
    if (game->rpg.enemy[2].is_alive == true)
        sfRenderWindow_drawSprite(game->game, game->rpg.enemy[2].sprite.sprite, NULL);
    if (game->rpg.enemy[3].is_alive == true)
        sfRenderWindow_drawSprite(game->game, game->rpg.enemy[3].sprite.sprite, NULL);
    if (game->rpg.enemy[4].is_alive == true)
        sfRenderWindow_drawSprite(game->game, game->rpg.enemy[4].sprite.sprite, NULL);
    if (game->rpg.enemy[5].is_alive == true)
        sfRenderWindow_drawSprite(game->game, game->rpg.enemy[5].sprite.sprite, NULL);
}

void manage_enemy(game_t *game)
{
    srand(time(NULL));
    for (int i = 0; i != 6 && game->rpg.enemy->is_loaded == false; i++) {
        game->rpg.enemy[i].sprite.pos.x = rand() % (game->map.line_lenght * 80);
        game->rpg.enemy[i].sprite.pos.y = rand() % (game->map.number_of_line * 80);
    }
    if (game->rpg.enemy->is_loaded == false) {
        create_enemy(game);
        game->rpg.enemy->is_loaded = true;
    }
    for (int i = 0; i < 6; i++) {
        if (get_distance_sp(game->rpg.player.sprite, game->rpg.enemy[i].sprite.sprite) <= 200) {
            game->rpg.i = i;
            game->rpg.enemy[i].need_to_move = true;
        } else
            game->rpg.enemy[i].need_to_move = false;
        if (game->rpg.enemy[i].need_to_move == true) {
            move_to_sp(game->rpg.enemy[i].sprite.sprite, game->rpg.player.sprite, 200, game->delta_time);
        }
        if (get_distance_sp(game->rpg.player.sprite, game->rpg.enemy[i].sprite.sprite) <= 50 && game->rpg.enemy[i].is_alive == true) {
            game->rpg.is_damaged = true;
            game->rpg.enemy[i].is_damaged = true;
        }
        if (game->rpg.enemy[i].life <= 0)
            game->rpg.enemy[i].is_alive = false;
    }
    render_enemy(game);
}
