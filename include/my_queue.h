/*
** EPITECH PROJECT, 2021
** h_queue
** File description:
** header for queue
*/

#ifndef _MY_QUEUE_H_
    #define _MY_QUEUE_H_

typedef struct my_element_s queue_element_t;
struct my_element_s {
    void *content;
    queue_element_t *next;
};
typedef struct my_queue_s {
    queue_element_t *first;
}my_queue_t;

// my_queue.c
int put_on_queue(my_queue_t *queue, void *content);
void *put_out_queue(my_queue_t *queue);
my_queue_t *init_queue(void);
void free_queue(my_queue_t *queue);
#endif
