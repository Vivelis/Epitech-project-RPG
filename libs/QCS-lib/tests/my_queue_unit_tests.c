/*
** EPITECH PROJECT, 2021
** pile-file
** File description:
** my_queue_unit_tests.c
*/

#include <criterion/criterion.h>
#include "my_queue.h"

Test(my_queue, initialise)
{
    my_queue_t *queue = NULL;

    queue = init_queue();
    cr_assert_neq(queue, NULL);
    free_queue(queue);
}
