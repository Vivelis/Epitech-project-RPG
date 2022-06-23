/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-mickael1.peireto
** File description:
** destroy_things
*/

#include "../include/proj.h"

void destroy_sprite(sfSprite **sprite, sfTexture **texture)
{
    sfSprite_destroy(*sprite);
    sfTexture_destroy(*texture);
    *sprite = NULL;
    *texture = NULL;
}