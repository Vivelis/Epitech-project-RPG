/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** my_rpg
*/

#include "proj.h"
#include "manage_file.h"

const char *music_path = "assets/music/music.ogg";

void create_rpg_window(game_t *game, int do_fullscreen)
{
    sfVideoMode mode = {1920, 1080, 32};
    game->is_fullscreen = do_fullscreen;

    if (do_fullscreen == 1)
        game->game = sfRenderWindow_create(mode, "my_rpg", sfFullscreen, NULL);
    else
        game->game = sfRenderWindow_create(mode, "my_rpg", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(game->game, game->framerate);
    sfRenderWindow_setVerticalSyncEnabled(game->game, sfTrue);
    sfRenderWindow_setMouseCursorVisible(game->game, sfFalse);
    if (does_file_exist(music_path) == false)
        return;
    if (game->is_loaded == false) {
        game->music = sfMusic_createFromFile(music_path);
        sfMusic_setLoop(game->music, sfTrue);
        sfMusic_play(game->music);
        game->clock = sfClock_create();
        create_sprite("assets/sprites/cursor.png", &game->cursor, &game->cursor_texture, NULL);
        game->status = main_menu;
    }
    game->is_loaded = true;
}

void do_while_open(game_t *game)
{
    game->map = new_map("map/base_map");
    if (check_error_map(&game->map) == 84) {
        my_putstr("Base map could not load\n");
        return;
    }
    get_map_spr(&game->map);
    while (sfRenderWindow_isOpen(game->game)) {
        game->time = sfClock_getElapsedTime(game->clock);
        game->delta_time = game->time.microseconds;
        sfRenderWindow_clear(game->game, sfBlack);
        sfClock_restart(game->clock);
        manage_event(game);
        load_scene(game, &game->map);
        if (game->cursor_is_visible == true)
            sfRenderWindow_drawSprite(game->game, game->cursor, NULL);
        sfRenderWindow_display(game->game);
    }
    sfSprite_destroy(game->cursor);
    sfTexture_destroy(game->cursor_texture);
}

void load_scene(game_t *game, map_t *map)
{
    switch (game->status) {
        case main_menu:
            do_main_menu(game);
            break;
        case settings:
            do_settings(game);
            break;
        case pause_menu:
            pause_menu_fun(game);
            break;
        case rpg:
            do_rpg(game, map);
            break;
        case status_menu:
            do_status_menu(game);
            break;
        case game_over:
            game_over_menu(game);
            break;
        //case win:
        //    win_menu(game);
        //    break;
        default:
            break;
    }
}

static int set_scene_isloaded(game_t *game)
{
    if (game == NULL)
        return 84;
    game->menu.is_loaded = false;
    game->status_menu.is_loaded = false;
    game->settings.is_loaded = false;
    game->pause.is_loaded = false;
    game->is_loaded = false;
    return 0;
}

int check_folders(void)
{
    if (!does_file_exist("meta_data"))
        return 84;
    if (!does_file_exist("map"))
        return 84;
    if (!does_file_exist("assets"))
        return 84;
    return 0;
}

int my_rpg()
{
    game_t *game = NULL;

    if (check_folders() == 84)
        return 84;
    game = get_config();
    get_save(game, "p1");
    game->is_loaded = false;
    create_rpg_window(game, 1);
    game->cursor_is_visible = true;
    game->msg.is_init = 0;
    game->sound = sfSound_create();
    game->sound_click = sfSoundBuffer_createFromFile("assets/music/click.ogg");
    set_scene_isloaded(game);
    do_while_open(game);
    destroy_inventory(game);
    sfMusic_stop(game->music);
    sfMusic_destroy(game->music);
    sfRenderWindow_destroy(game->game);
    free(game);
    return (1);
}
