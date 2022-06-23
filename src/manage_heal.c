/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-mickael1.peireto
** File description:
** manage_damage
*/

#include "proj.h"

void create_and_display_heal(game_t *game)
{
    sfVector2f pos = {sfSprite_getPosition(game->rpg.player.sprite).x - 450, sfSprite_getPosition(game->rpg.player.sprite).y - 250};
    char *str1 = my_itoa(game->stats.hp);
    char str2[100] = "heal ";
    char *str = my_strcat(str2, str1);

    if (game->rpg.heal_is_loaded == false) {
        game->rpg.heal = sfText_create();
        game->rpg.font = sfFont_createFromFile("assets/fonts/font.ttf");
    }
    sfText_setFont(game->rpg.heal, game->rpg.font);
    sfText_setCharacterSize(game->rpg.heal, 20);
    sfText_setString(game->rpg.heal, str);
    sfText_setPosition(game->rpg.heal, pos);
    sfText_setColor(game->rpg.heal, sfWhite);
    sfRenderWindow_drawText(game->game, game->rpg.heal, NULL);
    game->rpg.heal_is_loaded = true;
}

void manage_damage(game_t *game)
{
    sfTime time;
    sfTime time2;
    if (game->rpg.is_clock_loaded == false) {
            game->rpg.as = sfClock_create();
            game->rpg.player_as = sfClock_create();
            game->rpg.is_clock_loaded = true;
    }
    time = sfClock_getElapsedTime(game->rpg.as);
    time2 = sfClock_getElapsedTime(game->rpg.player_as);
    float seconds = time.microseconds / 1000000.0;
    float seconds2 = time2.microseconds / 1000000.0;

    if (game->rpg.enemy[game->rpg.i].is_damaged == true && seconds2 > 0.5) {
        game->rpg.enemy[game->rpg.i].life -= game->stats.dmg;
        game->stats.xp += 10;
        game->rpg.enemy[game->rpg.i].is_damaged = false;
        sfClock_restart(game->rpg.player_as);
    }
    if (game->rpg.is_damaged == true && seconds >= 1) {
        game->stats.hp -= 1;
        game->rpg.is_damaged = false;
        game->rpg.blood.call_time_elapsed = 0;
        sfClock_restart(game->rpg.as);
    }
}
