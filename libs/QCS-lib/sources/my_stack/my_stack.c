/*
** EPITECH PROJECT, 2021
** my_stack
** File description:
** stack exemple
*/

#include <unistd.h>
#include <stdlib.h>
#include "my_stack.h"
#include "qcs_utility.h"

/* add a new element on the top of the stack. */
void put_on_stack(my_stack_t *stack, void *content)
{
    stack_element_t *new = malloc(sizeof(*new));

    if (stack == NULL || new == NULL) {
        qcs_puterror("error:put_on: stack or new is NULL", -1);
    }
    new->content = content;
    new->next = stack->first;
    stack->first = new;
}

/* remove the last element of a stack and return it's value. */
void *put_out_stack(my_stack_t *stack)
{
    stack_element_t *element = NULL;
    void *content = NULL;

    if (!stack) {
        qcs_puterror("error:put_out: stack is NULL", -1);
        return NULL;
    }
    if (stack->first != NULL) {
        element = stack->first;
        content = element->content;
        stack->first = element->next;
        free(element);
    }
    return content;
}

/* allocate memory for a stack and return a pointer to it. */
my_stack_t *init_stack(void)
{
    my_stack_t *stack = malloc(sizeof(*stack));
    stack_element_t *element = malloc(sizeof(*element));

    if (stack == NULL || element == NULL) {
        qcs_puterror("error:init_stack: can't init stack", -1);
        return NULL;
    }
    element->content = NULL;
    element->next = NULL;
    stack->first = element;
    return stack;
}

/* free alocated space for a stack. */
void free_stack(my_stack_t *stack)
{
    stack_element_t *last = stack->first;

    while (stack->first != NULL) {
        stack->first = last->next;
        free(last);
        last = stack->first;
    }
    free(stack);
}
