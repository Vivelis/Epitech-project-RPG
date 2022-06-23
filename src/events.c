/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** events
*/

#include <string.h>
#include "../include/proj.h"

void event_main_menu(game_t *game, sfEvent event)
{
    if (event.type == sfEvtMouseMoved && game->status == main_menu) {
        increase_start(game);
        //increase_load(game);
        increase_settings(game);
        increase_exit(game);
    }
    if (event.type == sfEvtMouseButtonPressed && event.mouseButton.button == sfMouseLeft && game->status == main_menu) {
        detect_if_button_pressed_menu(game, game->menu.start_button.sprite, 1);
        detect_if_button_pressed_menu(game, game->menu.settings_button.sprite, 2);
        detect_if_button_pressed_menu(game, game->menu.exit_button.sprite, 3);
    }
}

void event_settings(game_t *game, sfEvent event)
{
    if (event.type == sfEvtMouseButtonPressed && event.mouseButton.button == sfMouseLeft && game->status == settings &&  game->settings.is_loaded == true) {
        detect_if_button_pressed_settings(game, game->settings.sound.sprite, 1);
        detect_if_button_pressed_settings(game, game->settings.music.sprite, 2);
        detect_if_button_pressed_settings(game, game->settings.change_framerate.sprite, 3);
        detect_if_button_pressed_settings(game, game->settings.fullscreen_button.sprite, 4);
    }
}

void event_keypressed(game_t *game, sfEvent event)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape && game->status == pause_menu && game->pause.is_paused == true)
        game->status = rpg;
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape && game->status == settings && game->pause.is_paused == false)
        game->status = main_menu;
    else if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape && game->status == settings && game->pause.is_paused == true) {
        game->status = rpg;
        game->pause.is_paused = false;
    }
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape && game->status == pause_menu)
        game->status = rpg;
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape && game->status == rpg && game->pause.is_paused == false)
        game->status = pause_menu;
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyA && game->status == rpg)
        game->status = status_menu;
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape && game->status == status_menu && game->status_menu.is_loaded == false)
        game->status = rpg;
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyA && game->status == status_menu && game->status_menu.is_loaded == true)
        game->status = rpg;
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyF4)
        game->status = quit;
}

void event_pause_menu(game_t *game, sfEvent event)
{
    if (event.type == sfEvtMouseMoved && game->status == pause_menu) {
        increase_resume(game);
        increase_save(game);
        increase_settings_pause(game);
        increase_exit_pause(game);
    }
    if (event.type == sfEvtMouseButtonPressed && event.mouseButton.button == sfMouseLeft && game->status == pause_menu) {
        detect_if_button_pressed_pause(game, game->pause.resume_button.sprite, 1);
        detect_if_button_pressed_pause(game, game->pause.save_button.sprite, 2);
        detect_if_button_pressed_pause(game, game->pause.settings_button.sprite, 3);
        detect_if_button_pressed_pause(game, game->pause.exit_button.sprite, 4);
    }
}

void manage_event(game_t *game)
{
    sfEvent event;
    
    memset(&event, 0, sizeof(sfEvent));
    while (sfRenderWindow_pollEvent(game->game, &event) && game->is_loaded == true) {
        if (event.type == sfEvtClosed || game->status == quit)
            sfRenderWindow_close(game->game);
        if (event.type == sfEvtKeyReleased && event.key.code == sfKeyF11) {
            sfRenderWindow_destroy(game->game);
            create_window_fullscreen(game);
        }
        event_main_menu(game, event);
        event_game_over_menu(game, event);
        event_pause_menu(game, event);
        event_keypressed(game, event);
        event_settings(game, event);
        move_cursor(game);
    }
}