/*
** EPITECH PROJECT, 2021
** B-MUL-200-TLS-2-1-myrpg-mickael1.peireto
** File description:
** manag_file.h
*/

#ifndef _MANAGE_FILE_
    #define _MANAGE_FILE_
    #include <stdio.h>
    #include "c_list.h"
    #include "rpg.h"

/****** FUNCTIONS ******/

/*** open_file.c ***/
/**
 * @brief open a file with mode parameter and return fd
 * 
 * @param pathname path to the file
 * @param mode 
 * @return NULL on error, else file descriptor 
 */
FILE *open_file(const char *pathname, const char *mode);

/*** write_in_file.c ***/
/**
 * @brief append buffer to the file at path. (create it if don't exist).
 * 
 * @param path path to the file
 * @param buffer string to append
 * @return 84 on error, else return 0
 */
int writestr_file(const char *path, const char *buffer);
int writeint_file(const char *path, int nbr);
int writechar_file(const char *path, char character);

/*** read_file.c ***/
/**
 * @brief read the file given in path and return a chained list of it's lines.
 * 
 * @param path path to the file
 * @return NULL on error, else chained list of file's lines
 */
c_list_t *read_file(char *path);
char *read_line(FILE *fd);

/****** config/config.c ******/
/**
 * @brief get config if file exist else set it.
 * 
 * @return game_t* game structure filled
 */
game_t *get_config(void);

/***** saves/write_item.c *****/
int write_item_name(game_t *game, unsigned int item_index, char *save_path);
int write_item_health(game_t *game, unsigned int item_index, char *save_path);
int write_item_damages(game_t *game, unsigned int item_index, char *save_path);
int write_item_shield(game_t *game, unsigned int item_index, char *save_path);
int write_item_durability(game_t *game, unsigned int item_index, char *save_path);
int write_item_texture_path(game_t *game, unsigned int item_index, char *save_path);

/***** saves/get_inventory.c *****/
int does_file_exist(const char *path);
bool is_end(const char *str, unsigned int index_to_check);
void write_inventory(game_t *game, char *save_path);
int destroy_inventory(game_t *game);
int get_inventory(game_t *game, char *save);

/***** saves/get_stats.c *****/
int get_stats(game_t *game, char *save);
void write_stats(game_t *game, char *save_path);

/***** saves/save_game.c ****/
void save_game(game_t *game, char *save_name);
void get_save(game_t *game, char *save_name);
#endif