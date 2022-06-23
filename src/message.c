/*
** EPITECH PROJECT, 2022
** My_rpg
** File description:
** Display a message in the game
*/

#include "proj.h"

// @brief Init the message structure
// @param game The game structure*
// @return int Return 0 if everything is ok
int init_msg(game_t *game)
{
    sfVector2f pos = {0, 0};

    if (does_file_exist("assets/fonts/font.ttf") != 1)
        return (84);
    game->msg.is_displayed = 0;
    game->msg.color = sfBlack;
    game->msg.text = sfText_create();
    game->msg.font = sfFont_createFromFile("assets/fonts/font.ttf");
    game->msg.pos = pos;
    game->msg.is_init = 1;
    return (0);
}

void set_msg(game_t *game, char *str)
{
    sfVector2f pos = {0, 0};

    if (game->msg.is_init == 0)
        if (init_msg(game) == 84)
            return;
    pos = game->rpg.player.pos;
    pos.x = ((int)game->rpg.col_co.x - 250);
    pos.y = ((int)game->rpg.col_co.y - 250);
    game->msg.pos = pos;
    sfText_setPosition(game->msg.text, pos);
    sfText_setString(game->msg.text, str);
    sfText_setFont(game->msg.text, game->msg.font);
    sfText_setCharacterSize(game->msg.text, 300);
    sfText_setColor(game->msg.text, game->msg.color);
    sfText_setPosition(game->msg.text, game->msg.pos);
    game->msg.is_displayed = 1;
    game->msg.is_with_text = 1;
}

void display_msg(sfRenderWindow *rpg, game_t *game)
{
    sfVector2f pos = {0, 0};

    if (game->msg.is_with_text == 0)
        return;
    if (game->msg.is_displayed == 0)
        return;
    pos = game->rpg.player.pos;
    pos.x = ((int)game->rpg.col_co.x - 180);
    pos.y = ((int)game->rpg.col_co.y + 200);
    game->msg.pos = pos;
    sfText_setFont(game->msg.text, game->msg.font);
    sfText_setCharacterSize(game->msg.text, 20);
    sfText_setColor(game->msg.text, game->msg.color);
    sfText_setPosition(game->msg.text, game->msg.pos);
    sfRenderWindow_drawText(rpg, game->msg.text, NULL);
}
