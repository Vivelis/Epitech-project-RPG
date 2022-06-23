/*
** EPITECH PROJECT, 2021
** B-MUL-200-TLS-2-1-myrpg-mickael1.peireto
** File description:
** config.c
*/

#include <string.h>
#include "manage_file.h"
#include "c_list.h"
#include "rpg.h"
#include "my.h"

static int set_line_config(game_t *game, char * line)
{
    int end_index = 0;

    if (my_strncmp(line, "framerate:i=", 12) == 0) {
        game->framerate = my_strtol(&line[12], &end_index);
        return 0;
    }
    return 0;
}

static int check_config(game_t *game)
{
    if (game == NULL)
        return my_puterror("check_config: game is NULL.\n", 84);
    if (game->framerate <= 0)
        return my_puterror("check_config: framerate : bad format.\n", 84);
    return 0;
}

static int set_file_config(game_t *game, c_list_t *buffer)
{
    list_element_t *curr_line = NULL;

    if (buffer == NULL || buffer->first == NULL) {
        return my_puterror("set_file_config: buffer or buffer->first is NULL.\
        \n", 84);
    }
    curr_line = buffer->first;
    while (curr_line != NULL) {
        set_line_config(game, (char *)curr_line->content);
        curr_line = curr_line->next;
    }
    return 0;
}

static game_t *set_base_config(void)
{
    game_t *game = malloc(sizeof(game_t));

    memset(game, 0, sizeof(game_t));
    game->framerate = 60;
    return game;
}

static void write_config(game_t *game)
{
    writestr_file(INVENTORY_FILE, "framerate:i=");
    writestr_file(INVENTORY_FILE, my_inttos(game->framerate));
    writestr_file(INVENTORY_FILE, "\n");
}

game_t *get_config(void)
{
    c_list_t *list = NULL;
    game_t *game = NULL;

    list = read_file(CONFIG_FILE);
    game = set_base_config();
    if (list == NULL) {
        my_puterror("get_config: can't read the config_file.\n", 0);
        write_config(game);
        my_puterror("get_config: config_file created.\n", 0);
    } else {
        set_file_config(game, list);
    }
    if (check_config(game) == 84) {
        free(game);
        game = set_base_config();
    }
    game->rpg.col_co = (sfVector2f){960, 540};
    return game;
}
