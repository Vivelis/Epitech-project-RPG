/*
** EPITECH PROJECT, 2021
** B-MUL-200-TLS-2-1-myrpg-mickael1.peireto
** File description:
** write_item.c
*/

#include <stddef.h>
#include "manage_file.h"
#include "rpg.h"

int write_item_name(game_t *game, unsigned int item_index, char *save_path)
{
    if (game->inventory[item_index].name == NULL)
        return 84;
    writestr_file(save_path, my_inttos(item_index));
    writestr_file(save_path, ":");
    writestr_file(save_path, "name");
    writestr_file(save_path, "=");
    writestr_file(save_path, game->inventory[item_index].name);
    writestr_file(save_path, "\n");
    return 0;
}

int write_item_health(game_t *game, unsigned int item_index, char *save_path)
{
    if (game->inventory[item_index].health == 0)
        return 84;
    writestr_file(save_path, my_inttos(item_index));
    writestr_file(save_path, ":");
    writestr_file(save_path, "health");
    writestr_file(save_path, "=");
    writestr_file(save_path, my_inttos(game->inventory[item_index].health));
    writestr_file(save_path, "\n");
    return 0;
}

int write_item_damages(game_t *game, unsigned int item_index, char *save_path)
{
    if (game->inventory[item_index].damages == 0)
        return 84;
    writestr_file(save_path, my_inttos(item_index));
    writestr_file(save_path, ":");
    writestr_file(save_path, "damages");
    writestr_file(save_path, "=");
    writestr_file(save_path, my_inttos(game->inventory[item_index].damages));
    writestr_file(save_path, "\n");
    return 0;
}

int write_item_shield(game_t *game, unsigned int item_index, char *save_path)
{
    if (game->inventory[item_index].shield == 0)
        return 84;
    writestr_file(save_path, my_inttos(item_index));
    writestr_file(save_path, ":");
    writestr_file(save_path, "shield");
    writestr_file(save_path, "=");
    writestr_file(save_path, my_inttos(game->inventory[item_index].shield));
    writestr_file(save_path, "\n");
    return 0;
}

int write_item_durability(game_t *game, unsigned int item_index, char *save_path)
{
    if (game->inventory[item_index].durability == 0)
        return 84;
    writestr_file(save_path, my_inttos(item_index));
    writestr_file(save_path, ":");
    writestr_file(save_path, "durability");
    writestr_file(save_path, "=");
    writestr_file(save_path, my_inttos(game->inventory[item_index].durability));
    writestr_file(save_path, "\n");
    return 0;
}

int write_item_texture_path(game_t *game, unsigned int item_index, char *save_path)
{
    if (game->inventory[item_index].texture_path == NULL)
        return 84;
    writestr_file(save_path, my_inttos(item_index));
    writestr_file(save_path, ":");
    writestr_file(save_path, "texture_path");
    writestr_file(save_path, "=");
    writestr_file(save_path, game->inventory[item_index].texture_path);
    writestr_file(save_path, "\n");
    return 0;
}