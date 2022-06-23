/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-mickael1.peireto
** File description:
** manage_status_menu
*/

#include "../include/proj.h"

void destroy_status_menu(game_t *game)
{
    destroy_sprite(&game->status_menu.menu.sprite, &game->status_menu.menu.texture);
    destroy_sprite(&game->status_menu.item_slot.sprite, &game->status_menu.item_slot.texture);
    destroy_status_menu_texts(game);
}

static void draw_item_slots(game_t *game)
{
    sfVector2f pos = {game->status_menu.menu.pos.x + 70, game->status_menu.menu.pos.y + 320};
    float offset = 135;

    if (game->status_menu.item_slot.sprite == NULL)
        return;
    for (int cnt = 0; cnt < INVENTORY_SIZE; cnt++) {
        sfSprite_setPosition(game->status_menu.item_slot.sprite, pos);
        sfRenderWindow_drawSprite(game->game, game->status_menu.item_slot.sprite, NULL);
        if (game->inventory[cnt].sprite != NULL) {
            sfSprite_setPosition(game->inventory[cnt].sprite, pos);
            sfSprite_setScale(game->inventory[cnt].sprite, (sfVector2f){2, 2});
            sfRenderWindow_drawSprite(game->game, game->inventory[cnt].sprite, NULL);
        }
        if (pos.x + offset < game->status_menu.max_x - 50)
            pos.x += offset;
        else {
            pos.y += offset;
            pos.x = game->status_menu.menu.pos.x + 70;
        }
    }
}

static void create_status_menu(game_t *game)
{
    game->status_menu.max_x = game->status_menu.menu.pos.x + 1200;
    create_sprite("assets/sprites/status_menu.png", &game->status_menu.menu.sprite , &game->status_menu.menu.texture, &game->status_menu.menu.pos);
    if (game->status_menu.menu.sprite != NULL)
        sfSprite_setScale(game->status_menu.menu.sprite, (sfVector2f){2, 2});
    create_sprite("assets/item_slot.png", &game->status_menu.item_slot.sprite, &game->status_menu.item_slot.texture, &game->status_menu.menu.pos);
    if (game->status_menu.item_slot.sprite != NULL) {
        sfSprite_setScale(game->status_menu.item_slot.sprite, (sfVector2f){1.3f, 1.3f});
    }
    create_status_menu_text(game);
}

static void render_status_menu(game_t *game)
{
    display_map(game->game, &game->map);
    sfRenderWindow_drawSprite(game->game, game->status_menu.menu.sprite, NULL);
    draw_item_slots(game);
    draw_status_menu_text(game);
}

void do_status_menu (game_t *game)
{
    sfVector2f pos = sfSprite_getPosition(game->rpg.player.sprite);

    game->status_menu.menu.pos = (sfVector2f) {pos.x - 600, pos.y - 400};
    
    if (game->cursor_is_visible == false)
        game->cursor_is_visible = true;
    if (game->status_menu.is_loaded == false) {
        create_status_menu(game);
        game->status_menu.is_loaded = true;
    }
    set_status_menu_text(game);
    sfView_setCenter(game->rpg.camera.camera, pos);
    sfView_setSize(game->rpg.camera.camera, (sfVector2f){1920, 1080});
    sfView_zoom(game->rpg.camera.camera, 1);
    sfRenderWindow_setView(game->game, game->rpg.camera.camera);
    render_status_menu(game);
}
