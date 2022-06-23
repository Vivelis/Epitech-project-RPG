/*
** EPITECH PROJECT, 2021
** pile-file
** File description:
** my_stack_unit_tests.c
*/

#include <criterion/criterion.h>
#include "my_stack.h"

Test(my_stack, initialise)
{
    my_stack_t *stack = NULL;

    stack = init_stack();
    put_on_stack(stack, "cc");
    cr_assert_neq(stack, NULL);
    free_stack(stack);
}
