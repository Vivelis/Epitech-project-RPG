/*
** EPITECH PROJECT, 2021
** B-MUL-200-TLS-2-1-myrpg-mickael1.peireto
** File description:
** stats_text.c
*/

#include <stddef.h>
#include "rpg.h"
#include "manage_file.h"

static const char font_path[] = "assets/fonts/font.ttf";

void create_text_fun(text_t *text, char *str, sfVector2f *pos)
{
    const int size = 35;

    if (!does_file_exist(font_path))
        return;
    text->font = sfFont_createFromFile(font_path);
    text->color = sfYellow;
    text->pos.x = pos->x;
    text->pos.y = pos->y;
    text->text = sfText_create();
    sfText_setString(text->text, str);
    sfText_setFont(text->text, text->font);
    sfText_setColor(text->text, text->color);
    sfText_setCharacterSize(text->text, size);
    sfText_setPosition(text->text, text->pos);
    text->is_loaded = true;
}

void create_status_menu_text(game_t *game)
{
    sfVector2f pos = {game->status_menu.menu.pos.x, game->status_menu.menu.pos.y + 100};
    float x_offset = 250;
    float y_offset = 90;

    create_text_fun(&game->status_menu.text[0], "xp: ", &(sfVector2f){pos.x + 100, pos.y});
    create_text_fun(&game->status_menu.text[1], "lvl: ", &(sfVector2f){pos.x + 100, pos.y + y_offset});
    pos.x = game->status_menu.menu.pos.x + 400;
    for (int index = 2; index <= 5; index++) {
        create_text_fun(&game->status_menu.text[index], "init", &(sfVector2f){pos.x, pos.y});
        if (pos.x + x_offset < game->status_menu.max_x - 100)
            pos.x += x_offset;
        else {
            pos.y += y_offset;
            pos.x = game->status_menu.menu.pos.x + 400;
        }
    }
}

static void set_stat_text(text_t *text, char *str, int value)
{
    char *final_str = NULL;

    final_str = my_strdup(str);
    my_strcatm(&final_str, my_inttos(value));
    sfText_setString(text->text, final_str);
    free(final_str);
}

void set_status_menu_text(game_t *game)
{
    set_stat_text(&game->status_menu.text[0], "xp: ", game->stats.xp);
    set_stat_text(&game->status_menu.text[1], "lvl: ", game->stats.lvl);
    set_stat_text(&game->status_menu.text[2], "hp: ", game->stats.hp);
    set_stat_text(&game->status_menu.text[3], "gold: ", game->stats.gold);
    set_stat_text(&game->status_menu.text[4], "dmg: ", game->stats.dmg);
    set_stat_text(&game->status_menu.text[5], "shield: ", game->stats.shield);
}

void destroy_status_menu_texts(game_t *game)
{
    if (game == NULL)
        return;
    for (int index = 0; index <= 5; index++) {
        if (game->status_menu.text[index].text != NULL)
            sfText_destroy(game->status_menu.text[index].text);
        if (game->status_menu.text[index].font != NULL)
            sfFont_destroy(game->status_menu.text[index].font);
        game->status_menu.text[index].is_loaded = false;
    }
}

void draw_status_menu_text(game_t *game)
{
    if (game == NULL)
        return;
    for (int index = 0; index <= 5; index++) {
        if (game->status_menu.text[index].text != NULL)
            sfRenderWindow_drawText(game->game, game->status_menu.text[index].text, NULL);
    }
}