/*
** EPITECH PROJECT, 2021
** pile-file
** File description:
** c_list.c
*/

#include <unistd.h>
#include <stdlib.h>
#include "c_list.h"
#include "qcs_utility.h"

/* add a new element on the top of the list. */
int put_on_list(c_list_t *list, void *content)
{
    list_element_t *current = NULL;
    list_element_t *new = NULL;

    new = malloc(sizeof(list_element_t));
    if (list == NULL || new == NULL)
        return qcs_puterror("error:put_on: list or new is NULL", -1);
    new->content = content;
    new->next = NULL;
    if (list->first != NULL) {
        current = list->first;
        while (current->next != NULL)
            current = current->next;
        current->next = new;
    } else
        list->first = new;
    list->len = list->len + 1;
    return 0;
}

/* remove the last element of a list and return it's value. */
void *put_out_list(c_list_t *list)
{
    list_element_t *element = NULL;
    void *content = NULL;

    if (!list) {
        qcs_puterror("error:put_out: list is NULL", -1);
        return NULL;
    }
    if (list->first != NULL) {
        element = list->first;
        content = element->content;
        list->first = element->next;
        free(element);
        list->len = list->len - 1;
    }
    return content;
}

/* allocate memory for a list and return a pointer to it. */
c_list_t *init_list(void)
{
    c_list_t *list = malloc(sizeof(c_list_t));

    if (list == NULL) {
        qcs_puterror("error:list: can't init list", -1);
        return NULL;
    }
    list->first = NULL;
    list->len = 0;
    return list;
}

/* free alocated space for a list. */
void free_list(c_list_t *list)
{
    list_element_t *last = list->first;

    while (list->first != NULL) {
        list->first = last->next;
        free(last);
        last = list->first;
    }
    free(list);
}
