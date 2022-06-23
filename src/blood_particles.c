/*
** EPITECH PROJECT, 2021
** B-MUL-200-TLS-2-1-myrpg-mickael1.peireto
** File description:
** blood_particles.c
*/

#include "proj.h"

static void create_blood(game_t *game, blood_t *blood)
{
    sfVector2f pos;
    sfColor color = sfRed;
    float offset = 25;

    if (game == NULL || game->rpg.player.sprite == NULL)
        return;
    if (blood == NULL)
        return;
    srand((int)time(NULL));
    memset(blood, 0, sizeof(blood_t));
    blood->time_elapsed = 0;
    pos = sfSprite_getPosition(game->rpg.player.sprite);
    pos.x = -pos.x - offset;
    pos.y = -pos.y - offset;
    blood->direction = pos;
    blood->circle = sfCircleShape_create();
    blood->direction = (sfVector2f){rand() % 5 - 2, rand()% 5 - 2};
    sfCircleShape_setRadius(blood->circle, BLOOD_PARTICLE_RADIUS);
    sfCircleShape_setFillColor(blood->circle, color);
    sfCircleShape_setOrigin(blood->circle, pos);
    blood->is_loaded = true;
}

static void destroy_blood(blood_t *blood)
{
    if (blood == NULL)
        return;
    if (blood->circle == NULL) {
        blood->is_loaded = false;
        return;
    }
    sfCircleShape_destroy(blood->circle);
    blood->circle = NULL;
    blood->is_loaded = false;
}

void destroy_blood_particles(blood_particles_t *particles)
{
    for (int index = 0; index < BLOOD_PARTICLE_NBR; index++) {
        destroy_blood(&particles->particles[index]);
    }
}

static void update_blood(game_t *game, blood_t *blood)
{
    blood->time_elapsed += game->delta_time;
    if (blood->time_elapsed > BLOOD_PARTICLE_DELAY) {
        destroy_blood(blood);
        return;
    }
    sfCircleShape_move(blood->circle, blood->direction);
}

static void update_blood_particles(game_t *game, blood_particles_t *particles)
{
    for (int index = 0; index < BLOOD_PARTICLE_NBR; index++) {
        if (particles->particles[index].is_loaded)
            update_blood(game, &particles->particles[index]);
    }
}

void generate_blood(game_t *game, blood_particles_t *particles)
{
    if (particles == NULL)
        return;
    if (particles->is_loaded == false) {
        memset(particles->particles, 0, BLOOD_PARTICLE_NBR * sizeof(blood_t));
        particles->call_time_elapsed = BLOOD_PARTICLE_MAX_DELAY;
        particles->is_loaded = true;
    }
    update_blood_particles(game, particles);
    (particles->time_elapsed) += game->delta_time;
    (particles->call_time_elapsed) += game->delta_time;
    if (particles->call_time_elapsed < BLOOD_PARTICLE_MAX_DELAY && particles->time_elapsed > BLOOD_PARTICLE_DELAY) {
        (particles->index) += 1;
        if (particles->index >= BLOOD_PARTICLE_NBR)
            particles->index = 0;
        if (particles->particles[particles->index].is_loaded)
            destroy_blood(&particles->particles[particles->index]);
        create_blood(game, &particles->particles[particles->index]);
        (particles->time_elapsed) -= BLOOD_PARTICLE_DELAY;
    }
}

void display_blood(game_t *game, blood_particles_t *particles)
{
    for (int index = 0; index < BLOOD_PARTICLE_NBR; index++) {
        if (particles->particles[index].circle != NULL && particles->particles[index].is_loaded == true) {
            sfRenderWindow_drawCircleShape(game->game, particles->particles[index].circle, NULL);
        }
    }
}
