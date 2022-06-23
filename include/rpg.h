/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** rpg
*/

#include "proj.h"

#ifndef RPG_H_
    #define RPG_H_
    #define CONFIG_FILE ("meta_data/config.txt")
    #define INVENTORY_FILE ("inventory.save")
    #define STATS_FILE ("stats.save")
    #define SAVE_PATH ("meta_data/saves/")
    #define MAX_LIFE (100)
    #define INVENTORY_SIZE (20)
    #define ENEMY_NBR (5)
    #define PLAYER_SPRITE_FILE ("assets/sprites/hero.png")
    #define STEP_PARTICLE_NBR (30)
    #define STEP_PARTICLE_DELAY (100000)
    #define STEP_PARTICLE_RADIUS (5)
    #define BLOOD_PARTICLE_NBR (10)
    #define BLOOD_PARTICLE_DELAY (100000)
    #define BLOOD_PARTICLE_LIFE_TIME (50000)
    #define BLOOD_PARTICLE_MAX_DELAY (700000)
    #define BLOOD_PARTICLE_RADIUS (4)

enum game_status_s {
    main_menu,
    rpg,
    pause_menu,
    game_over,
    win,
    settings,
    status_menu,
    quit,
};

typedef struct s_step_particles {
    sfCircleShape *particles[STEP_PARTICLE_NBR];
    sfInt64 time_elapsed;
    bool is_loaded;
    int index;
} step_particles_t;

typedef struct s_blood {
    sfCircleShape *circle;
    sfInt64 time_elapsed;
    bool is_loaded;
    sfVector2f direction;
} blood_t;

typedef struct s_blood_particles {
    blood_t particles[BLOOD_PARTICLE_NBR];
    sfInt64 time_elapsed;
    sfInt64 call_time_elapsed;
    bool is_loaded;
    int index;
} blood_particles_t;

typedef struct s_sprite {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    sfVector2f pos;
    bool is_loaded;
} sprite_t;

typedef struct s_text {
    sfVector2f pos;
    sfColor color;
    sfFont *font;
    sfText *text;
    int is_loaded;
} text_t;

typedef struct s_background {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
} background_t;

typedef struct s_button {
    sfSprite *sprite;
    sfTexture *texture;
    bool is_scaled;
    sfVector2f pos;
} button_t;

typedef struct s_main_menu {
    background_t back;
    button_t start_button;
    button_t load_game;
    button_t settings_button;
    button_t exit_button;
    bool is_loaded;
} main_menu_t;

typedef struct s_pause_menu {
    background_t back;
    bool is_loaded;
    bool is_paused;
    button_t resume_button;
    button_t save_button;
    button_t settings_button;
    button_t exit_button;
} pause_menu_t;

typedef struct s_settings {
    background_t back;
    text_t framerate_text;
    button_t framerate;
    text_t fullscreen_text;
    button_t fullscreen_button;
    button_t back_button;
    text_t sound_text;
    button_t sound;
    text_t music_text;
    button_t music;
    sprite_t music_checked;
    sprite_t fullscreen_checked;
    button_t change_framerate;
    sprite_t sound_checked;
    sprite_t fullscreen_button_checked;
    bool is_loaded;
    bool music_is_checked;
    bool fullscreen_is_checked;
    bool sound_is_checked;
} settings_t;

typedef struct s_stats {
    int hp;
    int xp;
    int lvl;
    int gold;
    int dmg;
    int shield;
} stats_t;

// set all to zero at the begining
// set durability to 1 for consumable
typedef struct s_item {
    char *name;
    int damages;
    int health;
    int shield;
    int durability;
    char *texture_path;
    sfTexture *texture;
    sfSprite *sprite;
} item_t;

typedef struct s_status_menu {
    sprite_t menu;
    sprite_t profile;
    sprite_t item_slot;
    text_t text[6];
    int max_x;
    int max_y;
    bool is_loaded;
} status_menu_t;

typedef struct s_camera_handler{
    sfView *camera;
} camera_handler_t;

typedef struct s_enemy {
    sprite_t sprite;
    sfVector2f saved_pos;
    sfCircleShape *circle;
    bool is_loaded;
    int nb_enemy;
    bool need_to_move;
    bool is_damaged;
    bool is_alive;
    int life;
} enemy_t;

typedef struct s_game_over {
    sfSprite *sprite;
    sfTexture *texture;
    sfText *text;
    sfFont *font;
    bool is_loaded;
} game_over_t;

typedef struct s_anim {
    sfIntRect* pos_array;
    int index;
    sfInt64 frame_time;
    float time_elapsed;
} anim_t;

typedef struct s_player_anim {
    anim_t idle;
    anim_t walk_left;
    anim_t walk_right;
    anim_t walk_up;
    anim_t walk_down;
    anim_t attack;
} player_anim_t;

typedef struct s_rpg {
    enemy_t enemy[ENEMY_NBR];
    background_t back;
    button_t inv;
    button_t pause;
    sprite_t player;
    player_anim_t player_anim;
    step_particles_t steps;
    blood_particles_t blood;
    bool is_damaged;
    sfText *heal;  
    sfText *stamina;
    sfFont *font;
    sfVector2f player_pos;
    sfVector2f saved_pos_player;
    sfVector2f col_co;
    camera_handler_t camera;
    bool camera_is_loaded;
    bool is_loaded;
    bool heal_is_loaded;
    int last_direction;
    int i;
    sfClock *as;
    sfClock *player_as;
    bool is_clock_loaded;
} rpg_t;

typedef struct map_s{
    char *whole_file;
    char **whole_array;
    char *char_list;
    char **path_list;
    char **map;
    char **special;
    char *walkable;
    char *not_walkable;
    int line_lenght;
    int number_of_line;
    sfSprite **spr;
    sfTexture **tex;
    sfVector2f scale;
} map_t;

typedef struct msg_s{
    char *msg;
    sfVector2f pos;
    sfColor color;
    sfFont *font;
    sfText *text;
    int is_displayed;
    int is_init;
    int is_with_text;
} msg_t;

typedef struct s_quest {
    int init;
    int mush_found;
    int slayed;
} quest_t;

typedef struct s_game {
    sfRenderWindow *game;
    sfClock *clock;
    sfTime time;
    float delta_time;
    bool cursor_is_visible;
    bool is_loaded;
    bool is_fullscreen;
    bool is_sound_mute;
    int framerate;
    sfMusic *music;
    sfSound *sound;
    sfSoundBuffer *sound_click;
    sfSprite *cursor;
    sfTexture *cursor_texture;
    enum game_status_s status;
    stats_t stats;
    item_t inventory[INVENTORY_SIZE];
    main_menu_t menu;
    settings_t settings;
    pause_menu_t pause;
    status_menu_t status_menu;
    quest_t quest;
    rpg_t rpg;
    map_t map;
    msg_t msg;
    game_over_t game_over;
} game_t;

#endif
