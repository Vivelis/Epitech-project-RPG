/*
** EPITECH PROJECT, 2021
** B-MUL-200-TLS-2-1-myrpg-mickael1.peireto
** File description:
** particles_effects.c
*/

#include "proj.h"

static sfCircleShape *create_step(game_t *game)
{
    sfCircleShape *step = NULL;
    sfVector2f pos;
    sfColor color = {150, 120, 100, 170};
    float offset = 10;

    if (game == NULL || game->rpg.player.sprite == NULL)
        return NULL;
    pos = sfSprite_getPosition(game->rpg.player.sprite);
    pos.x = -pos.x + ((int)pos.y % 2 - 1) * offset - 10;
    pos.y = -pos.y + ((int)pos.x % 2 - 1) * offset - 15;
    step = sfCircleShape_create();
    sfCircleShape_setRadius(step, STEP_PARTICLE_RADIUS);
    sfCircleShape_setFillColor(step, color);
    sfCircleShape_setOrigin(step, pos);
    return step;
}

void destroy_step_particles(step_particles_t *particles)
{
    for (int index = 0; index < STEP_PARTICLE_NBR; index++) {
        if (particles->particles[index] != NULL) {
            sfCircleShape_destroy(particles->particles[index]);
            particles->particles[index] = NULL;
        }
    }
}

void generate_step(game_t *game, step_particles_t *particles)
{
    if (particles == NULL)
        return;
    if (particles->is_loaded == false) {
        memset(particles->particles, 0, STEP_PARTICLE_NBR * sizeof(sfCircleShape *));
        particles->is_loaded = true;
    }
    (particles->time_elapsed) += game->delta_time;
    if (particles->time_elapsed > STEP_PARTICLE_DELAY) {
        (particles->index) += 1;
        if (particles->index >= STEP_PARTICLE_NBR)
            particles->index = 0;
        if (particles->particles[particles->index])
            sfCircleShape_destroy(particles->particles[particles->index]);
        particles->particles[particles->index] = create_step(game);
        (particles->time_elapsed) -= STEP_PARTICLE_DELAY;
    }
}

void display_steps(game_t *game, step_particles_t *particles)
{
    for (int index = 0; index < STEP_PARTICLE_NBR; index++) {
        if (particles->particles[index] != NULL) {
            sfRenderWindow_drawCircleShape(game->game, particles->particles[index], NULL);
        }
    }
}
