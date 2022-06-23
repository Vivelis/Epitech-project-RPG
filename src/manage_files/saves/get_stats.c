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

static void set_base_stats(game_t *game)
{
    game->stats.hp = MAX_LIFE;
    game->stats.xp = 0;
    game->stats.lvl = 0;
    game->stats.gold = 0;
    game->stats.dmg = 1;
    game->stats.shield = 1;
}

static int set_line_stats(game_t *game, char * line)
{
    int end_index = 0;

    if (my_strncmp(line, "hp:i=", 5) == 0 && !is_end(line, 5)) {
        game->stats.hp = my_strtol(&line[5], &end_index);
    }
    if (my_strncmp(line, "xp:i=", 5) == 0 && !is_end(line, 5)) {
        game->stats.xp = my_strtol(&line[5], &end_index);
    }
    if (my_strncmp(line, "lvl:i=", 6) == 0 && !is_end(line, 6)) {
        game->stats.lvl = my_strtol(&line[6], &end_index);
    }
    if (my_strncmp(line, "gold:i=", 7) == 0 && !is_end(line, 7)) {
        game->stats.gold = my_strtol(&line[7], &end_index);
    }
    if (my_strncmp(line, "dmg:i=", 6) == 0 && !is_end(line, 6)) {
        game->stats.dmg = my_strtol(&line[6], &end_index);
    }
    if (my_strncmp(line, "shield:i=", 9) == 0 && !is_end(line, 9)) {
        game->stats.shield = my_strtol(&line[9], &end_index);
    }
    return 0;
}

static int check_stats(game_t *game)
{
    if (game == NULL)
        return my_puterror("check_stats: game is NULL.\n", 84);
    if (game->stats.hp < 0 || game->stats.hp > MAX_LIFE)
        return my_puterror("check_stats: hp : bad format.\n", 84);
    if (game->stats.xp < 0)
        return my_puterror("check_stats: xp : bad format.\n", 84);
    if (game->stats.lvl < 0)
        return my_puterror("check_stats: lvl : bad format.\n", 84);
    if (game->stats.gold < 0)
        return my_puterror("check_stats: gold : bad format.\n", 84);
    if (game->stats.dmg < 0)
        return my_puterror("check_stats: dmg : bad format.\n", 84);
    if (game->stats.shield < 0)
        return my_puterror("check_stats: shield : bad format.\n", 84);
    return 0;
}

static int set_file_stats(game_t *game, c_list_t *buffer)
{
    list_element_t *curr_line = NULL;

    if (buffer == NULL || buffer->first == NULL) {
        return my_puterror("set_file_stats: buffer or buffer->first is NULL.\
        \n", 84);
    }
    curr_line = buffer->first;
    while (curr_line != NULL) {
        set_line_stats(game, (char *)curr_line->content);
        curr_line = curr_line->next;
    }
    return 0;
}

void write_stat(const char *stat, int value, const char *path)
{
    char *str = NULL;

    str = my_strdup(stat);
    my_strcatm(&str, my_inttos(value));
    my_strcatm(&str, "\n");
    writestr_file(path, str);
    free(str);
}

void write_stats(game_t *game, char *save_path)
{
    FILE *fd = NULL;
    char *path = my_strdup(save_path);

    my_strcatm(&path, STATS_FILE);
    fd = fopen(path, "w");
    if (fd != NULL)
        fclose(fd);
    write_stat("hp:i=", game->stats.hp, path);
    write_stat("xp:i=", game->stats.xp, path);
    write_stat("lvl:i=", game->stats.lvl, path);
    write_stat("gold:i=", game->stats.gold, path);
    write_stat("dmg:i=", game->stats.dmg, path);
    write_stat("shield:i=", game->stats.shield, path);
    free(path);
}

int get_stats(game_t *game, char *save)
{
    c_list_t *list = NULL;
    char *save_path = my_strdup(SAVE_PATH);

    if (game == NULL)
        return 84;
    set_base_stats(game);
    my_strcatm(&save_path, save);
    my_strcatm(&save_path, "/");
    my_strcatm(&save_path, STATS_FILE);
    list = read_file(save_path);
    if (list == NULL) {
        my_puterror("get_stats: can't read the file.\n", 0);
        write_stats(game, save_path);
        my_puterror("get_stats: stats file created.\n", 0);
    } else {
        set_file_stats(game, list);
        free(list);
    }
    if (check_stats(game) == 84)
        set_base_stats(game);
    free(save_path);
    return 0;
}
