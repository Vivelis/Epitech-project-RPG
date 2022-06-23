/*
** EPITECH PROJECT, 2021
** B-MUL-200-TLS-2-1-mydefender-maceo.jalbert
** File description:
** math.c
*/

#include <math.h>
#include "rpg.h"

float get_norme(const float x, const float y)
{
    float result = 0;

    if (x == 0 && y == 0)
        return 0;
    result = sqrt(x * x + y * y);
    return result;
}

sfVector2f normalize(const float x, const float y)
{
    sfVector2f result = {0, 0};
    float norme = 0;

    norme = get_norme(x, y);
    result.x = x / norme;
    result.y = y / norme;
    return result;
}

/* Don't forget to free after usage. */
sfVector2f *normalize_m(const float x, const float y)
{
    sfVector2f *result = NULL;
    float norme = 0;

    result = malloc(sizeof(sfVector2f));
    if (result == NULL) {
        my_puterror("./mysokoban: can't alloc sfVector2f.\n", 84);
        return NULL;
    }
    norme = get_norme(x, y);
    result->x = x / norme;
    result->y = y /norme;
    return result;
}

sfVector2f multiply_vector(const sfVector2f vector, const float multiplier)
{
    sfVector2f result = {0, 0};

    result.x =  vector.x * multiplier;
    result.y = vector.y * multiplier;
    return result;
}

int multiply_vector_p(sfVector2f *vector, const float multiplier)
{
    if (vector == NULL) {
        return my_puterror("./my_sokoban: vector is NULL", 84);
    }
    vector->x =  vector->x * multiplier;
    vector->y = vector->y * multiplier;
    return 0;
}
