/*
** EPITECH PROJECT, 2021
** B-MUL-200-TLS-2-1-mydefender-maceo.jalbert
** File description:
** deplacement.c.c
*/

#include "rpg.h"

int move_to(sfSprite *self, const sfVector2f destination, const float speed,
const sfUint64 delta_time)
{
    sfVector2f direction = {0, 0};
    float x_move = 0;
    float y_move = 0;

    if (self == NULL)
        return my_puterror("./my_sokoban: self is NULL.\n", 84);
    x_move = destination.x - sfSprite_getPosition(self).x;
    y_move = destination.y - sfSprite_getPosition(self).y;
    if (get_norme(x_move, y_move) < 1)
        return 0;
    direction = normalize(x_move, y_move);
    direction = multiply_vector(direction, speed * delta_time / 1000000);
    sfSprite_move(self, direction);
    return 0;
}

int move_to_sp(sfSprite *self, const sfSprite *target, const float speed,
const sfUint64 delta_time)
{
    sfVector2f destination = {0, 0};

    if (self == NULL || target == NULL)
        my_puterror("./my_sokoban: self or destination is NULL.\n", 84);
    destination = sfSprite_getPosition(target);
    return move_to(self, destination, speed, delta_time);
}

float get_distance_sp(sfSprite *sprite1, sfSprite *sprite2)
{
    sfVector2f coord1 = sfSprite_getPosition(sprite1);
    sfVector2f coord2 = sfSprite_getPosition(sprite2);
    float distance = 0;

    distance = get_norme(coord1.x - coord2.x, coord1.y - coord2.y);
    return distance;
}

float get_distance(sfVector2f *vector1, sfVector2f *vector2)
{
    float distance = 0;

    distance = get_norme(vector1->x - vector2->x, vector1->y - vector2->y);
    return distance;
}