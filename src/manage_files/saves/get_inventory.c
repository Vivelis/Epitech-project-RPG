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

/**
 * @brief init item attributes to 0 or NULL.
 * 
 * @param item adress of the item to init
 */
void init_item(item_t *item)
{
    item->name = NULL;
    item->durability = 0;
    item->health = 0;
    item->shield = 0;
    item->damages = 0;
    item->texture_path = NULL;
    item->texture = NULL;
    item->sprite = NULL;
}

static void set_base_inventory(game_t *game)
{
    if (game != NULL) {
        for (int index = 0; index < INVENTORY_SIZE; index++) {
            init_item(&game->inventory[index]);
        }
    }
}

bool is_end(const char *str, unsigned int index_to_check)
{
    for (unsigned int index = 0; index <= index_to_check; index++) {
        if (str[index] == '\0')
            return true;
    }
    return false;
}

static char *remove_backline(char *str)
{
    if (str == NULL)
        return NULL;
    for (int index = 0; str[index] != '\0'; index++) {
        if (str[index] == '\n')
            str[index] = '\0';
    }
    return str;
}

// @brief verify the existence of a file
// @param path the path of the file
// @return 1 if the file exists
int does_file_exist(const char *path)
{
    FILE *fd = NULL;

    if (path == NULL)
        return 0;
    fd = open_file(path, "r");
    if (fd == NULL)
        return 0;
    fclose(fd);
    return 1;
}

static int set_item_stat(item_t *item, char *stat_value)
{
    int index = 0;

    if (my_strncmp(stat_value, "name", 4) == 0
    && is_end(stat_value, 5) == false)
        item->name = remove_backline(my_strdup(&stat_value[5]));
    if (my_strncmp(stat_value, "durability", 10) == 0
    && is_end(stat_value, 11) == false)
        item->durability = my_strtol(&stat_value[11], &index);
    if (my_strncmp(stat_value, "health", 6) == 0
    && is_end(stat_value, 6) == false)
        item->health = my_strtol(&stat_value[7], &index);
    if (my_strncmp(stat_value, "shield", 6) == 0
    && is_end(stat_value, 6) == false)
        item->shield = my_strtol(&stat_value[7], &index);
    if (my_strncmp(stat_value, "damages", 7) == 0
    && is_end(stat_value, 7) == false)
        item->damages = my_strtol(&stat_value[8], &index);
    if (my_strncmp(stat_value, "texture_path", 12) == 0
    && is_end(stat_value, 12) == false) {
        item->texture_path =remove_backline(my_strdup(&stat_value[13]));
        if (does_file_exist(item->texture_path) == true)
            create_sprite(item->texture_path, &item->sprite, &item->texture, NULL);
    }
    return 0;
}

static int set_line_inventory(game_t *game, char * line)
{
    int s_index = 0;
    int item_index = 0;

    if (line == NULL)
        return 84;
    if (is_number(line[0]) == 'y') {
        item_index = my_strtol(line, &s_index);
        if (item_index >= INVENTORY_SIZE)
            return 84;
        s_index += 1;
        if (is_end(line, s_index) == true)
            return 84;
        if (set_item_stat(&game->inventory[item_index], &line[s_index]) == 84)
            init_item(&game->inventory[item_index]);
    }
    return 0;
}

static int check_inventory(game_t *game)
{
    if (game == NULL)
        return my_puterror("check_inventory: game is NULL.\n", 84);
    return 0;
}

static int set_file_inventory(game_t *game, c_list_t *buffer)
{
    list_element_t *curr_line = NULL;

    if (buffer == NULL || buffer->first == NULL) {
        return my_puterror("set_file_inventory: buffer or buffer->first is NULL.\
        \n", 84);
    }
    curr_line = buffer->first;
    while (curr_line != NULL) {
        set_line_inventory(game, (char *)curr_line->content);
        curr_line = curr_line->next;
    }
    return 0;
}

static void write_item_stats(game_t *game, int item_index, char *save_path)
{
    write_item_name(game, item_index, save_path);
    write_item_damages(game, item_index, save_path);
    write_item_health(game, item_index, save_path);
    write_item_shield(game, item_index, save_path);
    write_item_durability(game, item_index, save_path);
    write_item_texture_path(game, item_index, save_path);
}

void write_inventory(game_t *game, char *save_path)
{
    char *path = my_strdup(save_path);
    FILE *fd = NULL;

    my_strcatm(&path, INVENTORY_FILE);
    fd = fopen(path, "w");
    if (fd != NULL)
        fclose(fd);
    for (int index = 0; index < INVENTORY_SIZE; index++) {
        write_item_stats(game, index, path);
    }
    free(path);
}

int get_inventory(game_t *game, char *save)
{
    c_list_t *list = NULL;
    char *save_path = my_strdup(SAVE_PATH);

    if (game == NULL)
        return 84;
    set_base_inventory(game);
    my_strcatm(&save_path, save);
    my_strcatm(&save_path, "/");
    my_strcatm(&save_path, INVENTORY_FILE);
    list = read_file(save_path);
    if (list == NULL) {
        my_puterror("get_inventory: can't read the file.\n", 0);
        write_inventory(game, save_path);
        my_puterror("get_inventory: inventory file created.\n", 0);
    } else {
        set_file_inventory(game, list);
        free_list(list);
    }
    if (check_inventory(game) == 84) {
        set_base_inventory(game);
    }
    free(save_path);
    return 0;
}

int destroy_inventory(game_t *game)
{
    if (game == NULL)
        return 84;
    for (unsigned int index = 0; index < INVENTORY_SIZE; index++) {
        if (game->inventory[index].name != NULL)
            free(game->inventory[index].name);
        if (game->inventory[index].texture_path != NULL)
            free(game->inventory[index].texture_path);
        if (game->inventory[index].texture != NULL)
            sfTexture_destroy(game->inventory[index].texture);
        if (game->inventory[index].sprite != NULL)
            sfSprite_destroy(game->inventory[index].sprite);
    }
    return 0;
}

static void set_stats(game_t *game, int item_index, item_t *stats)
{
    item_t *item = NULL;

    if (game == NULL || item_index < 0 || item_index >= INVENTORY_SIZE)
        return;
    item = &game->inventory[item_index];
    item->name = stats->name;
    item->health = stats->health;
    item->damages = stats->damages;
    item->durability = stats->damages;
    item->shield = stats->shield;
    item->texture_path = stats->texture_path;
    item->texture = stats->texture;
    item->sprite = stats->sprite;
}

/**
 * @brief add item to the inventory (all item should have a name).
 * @param game main game structure with inventory set
 * @param item the item to add with at least a name
 * @return 1 if the item is added, else return 0
 */
int add_item(game_t *game, item_t *item)
{
    if (game == NULL)
        return 0;
    for (int index = 0; index < INVENTORY_SIZE; index++) {
        if (game->inventory[index].name != NULL) {
            set_stats(game, index, item);
            return 1;
        }
    }
    return 0;
}

/**
 * @brief set initial values to the item given in parameter and 
 * crate the sprite coresponding to the texture_path.
 * @param item adres of the item to initialise
 * @param texture_path path to the texture to create
 * @return 84 on error, else 0
 */
int create_item(item_t *item, char *texture_path)
{
    if (item == NULL)
        return 84;
    init_item(item);
    item->texture_path = texture_path;
    return create_sprite(item->texture_path, &item->sprite, &item->texture, NULL);
}
