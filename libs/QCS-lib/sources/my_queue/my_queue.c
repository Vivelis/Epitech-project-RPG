/*
** EPITECH PROJECT, 2021
** my_queue
** File description:
** queue exemple
*/

#include <unistd.h>
#include <stdlib.h>
#include "my_queue.h"
#include "qcs_utility.h"

/* add a new element on the top of the queue. */
int put_on_queue(my_queue_t *queue, void *content)
{
    queue_element_t *current = NULL;
    queue_element_t *new = NULL;

    new = malloc(sizeof(queue_element_t));
    if (queue == NULL || new == NULL)
        return qcs_puterror("error:put_on: queue or new is NULL", -1);
    new->content = content;
    new->next = NULL;
    if (queue->first != NULL) {
        current = queue->first;
        while (current->next != NULL)
            current = current->next;
        current->next = new;
    } else
        queue->first = new;
    return 0;
}

/* remove the first element of a queue and return it's value. */
void *put_out_queue(my_queue_t *queue)
{
    queue_element_t *element = NULL;
    void *content = NULL;

    if (!queue) {
        qcs_puterror("error:put_out: queue is NULL", -1);
        return NULL;
    }
    if (queue->first != NULL) {
        element = queue->first;
        content = element->content;
        queue->first = element->next;
        free(element);
    }
    return content;
}

/* allocate memory for a queue and return a pointer to it. */
my_queue_t *init_queue(void)
{
    my_queue_t *queue = malloc(sizeof(my_queue_t));

    if (queue == NULL) {
        qcs_puterror("error:queue: can't init queue", -1);
        return NULL;
    }
    queue->first = NULL;
    return queue;
}

/* free alocated space for a queue. */
void free_queue(my_queue_t *queue)
{
    queue_element_t *last = queue->first;

    while (queue->first != NULL) {
        queue->first = last->next;
        free(last);
        last = queue->first;
    }
    free(queue);
}
