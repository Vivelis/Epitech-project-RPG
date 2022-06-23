/*
** EPITECH PROJECT, 2021
** B-MUL-200-TLS-2-1-myrpg-mickael1.peireto
** File description:
** save_game.c
*/

#include <stddef.h>
#include "rpg.h"
#include "manage_file.h"

void save_game(game_t *game, char *save_name)
{
    char *save_path = NULL;

    if (game == NULL)
        return;
    save_path = my_strdup(SAVE_PATH);
    my_strcatm(&save_path, save_name);
    my_strcatm(&save_path, "/");
    write_inventory(game, save_path);
    write_stats(game, save_path);
}

void get_save(game_t *game, char *save_name)
{
    if (game == NULL)
        return;
    get_inventory(game, save_name);
    get_stats(game, save_name);
}
