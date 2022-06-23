/*
** EPITECH PROJECT, 2021
** B-MUL-200-TLS-2-1-myrpg-mickael1.peireto
** File description:
** player_anim.c
*/

#include "proj.h"
#include "math.h"

static void set_walk_left_anim(game_t *game)
{
    const int anim_nbr = 4;
    int width = game->rpg.player.rect.width;
    int height = game->rpg.player.rect.height;

    game->rpg.player_anim.walk_left.pos_array = malloc(sizeof(sfIntRect) * (anim_nbr + 1));
    game->rpg.player_anim.walk_left.pos_array[0] = (sfIntRect){0, 0, width, height};
    game->rpg.player_anim.walk_left.pos_array[1] = (sfIntRect){width , 0, width, height};
    game->rpg.player_anim.walk_left.pos_array[2] = (sfIntRect){2 * width, 0, width, height};
    game->rpg.player_anim.walk_left.pos_array[3] = (sfIntRect){width, 0, width, height};
    game->rpg.player_anim.walk_left.pos_array[4] = (sfIntRect){0, 0, 0, 0};
    game->rpg.player_anim.walk_left.time_elapsed = 0;
    game->rpg.player_anim.walk_left.frame_time = 100000;
}

static void set_walk_right_anim(game_t *game)
{
    const int anim_nbr = 4;
    int width = game->rpg.player.rect.width;
    int height = game->rpg.player.rect.height;

    game->rpg.player_anim.walk_right.pos_array = malloc(sizeof(sfIntRect) * (anim_nbr + 1));
    game->rpg.player_anim.walk_right.pos_array[0] = (sfIntRect){width, 0, -width, height};
    game->rpg.player_anim.walk_right.pos_array[1] = (sfIntRect){2 * width , 0, -width, height};
    game->rpg.player_anim.walk_right.pos_array[2] = (sfIntRect){3 * width, 0, -width, height};
    game->rpg.player_anim.walk_right.pos_array[3] = (sfIntRect){2 * width, 0, -width, height};
    game->rpg.player_anim.walk_right.pos_array[4] = (sfIntRect){0, 0, 0, 0};
    game->rpg.player_anim.walk_right.time_elapsed = 0;
    game->rpg.player_anim.walk_right.frame_time = 100000;
}

static void set_walk_up_anim(game_t *game)
{
    const int anim_nbr = 4;
    int width = game->rpg.player.rect.width;
    int height = game->rpg.player.rect.height;

    game->rpg.player_anim.walk_up.pos_array = malloc(sizeof(sfIntRect) * (anim_nbr + 1));
    game->rpg.player_anim.walk_up.pos_array[0] = (sfIntRect){0, height, width, height};
    game->rpg.player_anim.walk_up.pos_array[1] = (sfIntRect){width , height, width, height};
    game->rpg.player_anim.walk_up.pos_array[2] = (sfIntRect){2 * width, height, width, height};
    game->rpg.player_anim.walk_up.pos_array[3] = (sfIntRect){width, height, width, height};
    game->rpg.player_anim.walk_up.pos_array[4] = (sfIntRect){0, 0, 0, 0};
    game->rpg.player_anim.walk_up.time_elapsed = 0;
    game->rpg.player_anim.walk_up.frame_time = 100000;
}

static void set_walk_down_anim(game_t *game)
{
    const int anim_nbr = 4;
    int width = game->rpg.player.rect.width;
    int height = game->rpg.player.rect.height;

    game->rpg.player_anim.walk_down.pos_array = malloc(sizeof(sfIntRect) * (anim_nbr + 1));
    game->rpg.player_anim.walk_down.pos_array[0] = (sfIntRect){0, 2 * height, width, height};
    game->rpg.player_anim.walk_down.pos_array[1] = (sfIntRect){width , 2 * height, width, height};
    game->rpg.player_anim.walk_down.pos_array[2] = (sfIntRect){2 * width, 2 * height, width, height};
    game->rpg.player_anim.walk_down.pos_array[3] = (sfIntRect){width, 2 * height, width, height};
    game->rpg.player_anim.walk_down.pos_array[4] = (sfIntRect){0, 0, 0, 0};
    game->rpg.player_anim.walk_down.time_elapsed = 0;
    game->rpg.player_anim.walk_down.frame_time = 100000;
}

void set_player_anim(game_t *game)
{
    set_walk_left_anim(game);
    set_walk_right_anim(game);
    set_walk_up_anim(game);
    set_walk_down_anim(game);
}

void anim_sprite(game_t *game, sprite_t *sprite, anim_t *anim)
{
    if (game == NULL || sprite == NULL || anim == NULL)
        return;

    anim->time_elapsed += game->delta_time ;
    while (anim->time_elapsed > anim->frame_time) {
        (anim->index) += 1;
        if (anim->pos_array[anim->index].height == 0
            && anim->pos_array[anim->index].width == 0) {
            anim->index = 0;
        }
        (anim->time_elapsed) -= anim->frame_time;
    }
    sprite->rect = anim->pos_array[anim->index];
    sfSprite_setTextureRect(game->rpg.player.sprite, game->rpg.player.rect);
}

void set_player_idle_anim(game_t *game)
{
    if (game->rpg.player.sprite == NULL)
        return;
    sfSprite_setTextureRect(game->rpg.player.sprite, (sfIntRect)
    {2 * abs(game->rpg.player.rect.width), 3 * game->rpg.player.rect.height,
    abs(game->rpg.player.rect.width), game->rpg.player.rect.height});
}
