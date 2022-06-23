/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** proj
*/

#ifndef PROJ_H_
    #define PROJ_H_
    #define TRUE (1)
    #define FALSE (0)
    #define PLAYERWIDTH 40
    #define PLAYERHEIGHT 40
    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Config.h>
    #include <SFML/System/Types.h>
    #include <SFML/System/Vector2.h>
    #include <sys/stat.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <stdio.h>
    #include <stdbool.h>
    #include <stdlib.h>
    #include <time.h>
    #include <string.h>
    #include "rpg.h"
    #include "my.h"

    int create_sprite(char *path, sfSprite **sprite, sfTexture **texture, sfVector2f *basepos);
    void load_scene(game_t *game, map_t *map);
    void do_while_open(game_t *game);
    void create_rpg_window(game_t *game, int do_fullscreen);
    void do_main_menu(game_t *game);
    void manage_event(game_t *game);
    void create_window_fullscreen(game_t *game);
    void move_cursor(game_t *game);
    int my_rpg();
    void destroy_rpg(game_t *game);
    void do_settings(game_t *game);
    void detect_if_button_pressed_menu(game_t *game, sfSprite *sprite, int status);
    void detect_if_button_pressed_settings(game_t *game, sfSprite *sprite, int status);
    void increase_start(game_t *game);
    void increase_settings(game_t *game);
    void increase_exit(game_t *game);
    void increase_load(game_t *game);
    void pause_menu_fun(game_t *game);
    void do_rpg(game_t *game, map_t *map);
    int center_origin_sp(sfSprite *sprite);
    void create_window_fullscreen(game_t *game);
    void move_cursor(game_t *game);
    void detect_if_button_pressed_menu(game_t *game, sfSprite *sprite, int status);
    void detect_if_button_pressed_pause(game_t *game, sfSprite *sprite, int status);
    void increase_resume(game_t *game);
    void increase_save(game_t *game);
    void increase_settings_pause(game_t *game);
    void increase_exit_pause(game_t *game);
    void create_text(char *path, sfText **text, sfFont **font, sfVector2f *pos);
    void do_status_menu(game_t *game);
    void destroy_sprite(sfSprite **sprite, sfTexture **texture);
    void destroy_main_menu(game_t *game);
    void destroy_settings(game_t *game);
    void destroy_pause_menu(game_t *game);
    void manage_player(game_t *game);
    void event_manage_player(game_t *game);
    void destroy_player(game_t *game);
    void manage_camera(game_t *game);
    int char_count(char *str, char c);
    int str_count(char **str);
    char **my_str_split(char *str, char delim);
    char **copy_array_left(char **array, int nb);
    char **my_str_to_word_array(char *str, char delim);
    void get_everything(map_t *map);
    int find_a_char_index(char *path, char char_to_find);
    map_t new_map(char *path);
    void get_map_spr(map_t *map);
    int check_error_map(map_t *map);
    void display_map(sfRenderWindow *Rpg, map_t *map);
    void destroy_status_menu(game_t *game);
    int can_move(game_t *game, int x, int y);
    void player_movement(game_t *game, int status);
    void get_in_front_of_you(game_t *game);
    void set_msg(game_t *game, char *str);
    int init_msg(game_t *game);
    void display_msg(sfRenderWindow *rpg, game_t *game);
    int does_file_exist(const char *path);
    void create_status_menu_text(game_t *game);
    void create_text_fun(text_t *text, char *str, sfVector2f *pos);
    float get_norme(const float x, const float y);
    sfVector2f normalize(const float x, const float y);
    sfVector2f *normalize_m(const float x, const float y);
    sfVector2f multiply_vector(const sfVector2f vector, const float multiplier);
    int multiply_vector_p(sfVector2f *vector, const float multiplier);
    int move_to(sfSprite *self, const sfVector2f destination, const float speed,
    const sfUint64 delta_time);
    int move_to_sp(sfSprite *self, const sfSprite *target, const float speed,
    const sfUint64 delta_time);
    float get_distance_sp(sfSprite *sprite1, sfSprite *sprite2);
    void manage_enemy(game_t *game);
    void manage_damage(game_t *game);
    void create_and_display_heal(game_t *game);
    char *my_itoa(int num);
    void set_status_menu_text(game_t *game);
    void destroy_status_menu_texts(game_t *game);
    void draw_status_menu_text(game_t *game);
    int create_item(item_t *item, char *texture_path);
    int add_item(game_t *game, item_t *item);
    void mushroom_interaction(game_t *game, int y, int x);
    void pnj_quest_interaction(game_t *game);
    void help_interaction(game_t *game);
    void display_player(game_t *game);
    void anim_sprite(game_t *game, sprite_t *sprite, anim_t *anim);
    void set_player_anim(game_t *game);
    void set_player_idle_anim(game_t *game);
    void manage_player_damage(game_t *game);
    void destroy_enemy(game_t *game);
    void reset_camera(game_t *game);
    void game_over_menu(game_t *game);
    void detect_if_button_game_over_pressed(game_t *game, sfSprite *sprite);
    void event_game_over_menu(game_t *game, sfEvent event);
    void destroy_game_over_menu(game_t *game);
    void generate_step(game_t *game, step_particles_t *particles);
    void display_steps(game_t *game, step_particles_t *particles);
    void destroy_step_particles(step_particles_t *particles);
    float get_distance(sfVector2f *vector1, sfVector2f *vector2);
    void generate_blood(game_t *game, blood_particles_t *particles);
    void display_blood(game_t *game, blood_particles_t *particles);
    void destroy_blood_particles(blood_particles_t *particles);
#endif
