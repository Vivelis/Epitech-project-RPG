/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** create_things
*/

#include "../include/proj.h"
#include "manage_file.h"

void create_window_fullscreen(game_t *game)
{
    static bool isFull = true;

    if (isFull == false) {
        create_rpg_window(game, true);
        isFull = true;
    } else {
        create_rpg_window(game, false);
        isFull = false;
    }
}

void create_text(char *path, sfText **text, sfFont **font, sfVector2f *pos)
{
    *text = sfText_create();
    if (does_file_exist(path) == false)
        return;
    *font = sfFont_createFromFile(path);
    sfText_setFont(*text, *font);
    sfText_setColor(*text, sfRed);
    sfText_setPosition(*text, *pos);
}

int create_sprite(char *path, sfSprite **sprite, sfTexture **texture, sfVector2f *basepos)
{
    if (!does_file_exist(path))
        return 84;
    *sprite = sfSprite_create();
    *texture = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(*sprite, *texture, sfTrue);
    if (basepos == NULL)
        sfSprite_setPosition(*sprite, (sfVector2f) {0, 0});
    else
        sfSprite_setPosition(*sprite, *basepos);
    return 0;
}

int center_origin_sp(sfSprite *sprite)
{
    sfFloatRect bounds = {0, 0, 0, 0};

    if(sprite == NULL)
        return (84);
    bounds = sfSprite_getGlobalBounds(sprite);
    sfSprite_setOrigin(sprite, (sfVector2f){bounds.width / 2,
    bounds.height / 2});
    return 0;
}

void move_cursor(game_t *game)
{
    sfVector2i vector = sfMouse_getPositionRenderWindow(game->game);
    sfVector2f cursor_pos;
    int reajust_cursor_x = 5;
    int reajust_cursor_y = 3;

    vector.x -= reajust_cursor_x;
    vector.y -= reajust_cursor_y;
    cursor_pos = (sfVector2f) {vector.x, vector.y};
    sfSprite_setPosition(game->cursor, cursor_pos);
}