/*
** EPITECH PROJECT, 2021
** pile-file
** File description:
** c_list_index.c
*/

#include <stddef.h>
#include <stdlib.h>
#include "c_list.h"
#include "qcs_utility.h"

/* allocate memory for an element and return it */
static list_element_t *allocate_elem(void *content)
{
    list_element_t *new = NULL;

    new = malloc(sizeof(list_element_t));
    if (new == NULL) {
        qcs_puterror("error:put_on: list or new is NULL", -1);
        return NULL;
    }
    new->content = content;
    new->next = NULL;
    return new;
}

/* switch the next element of last with it's next */
static void switch_elem(list_element_t *last)
{
    list_element_t *next = NULL;

    next = last->next->next;
    free(last->next);
    last->next = next;
}

/* add a new element at the given index to the list. */
int insert_listi(c_list_t *list, unsigned int index, void *content)
{
    list_element_t *current = NULL;

    if (list->first == NULL) {
        list->first = allocate_elem(content);
        list->len = list->len + 1;
        return 0;
    }
    current = list->first;
    for (; index > 0; index--) {
        if (current->next == NULL && index == 1) {
            current->next = allocate_elem(content);
            list->len = list->len + 1;
            return 0;
        } else if (current->next == NULL && index != 1 ) {
            return qcs_puterror("insert_listi: index out of range.\n", 84);
        }
        current = current->next;
    }
    current->content = content;
    return 0;
}

/* remove the element at the given index of the list. */
int delete_listi(c_list_t *list, unsigned int index)
{
    list_element_t *last = NULL;

    if (list->first == NULL)
        return qcs_puterror("delete_listi: can't delete, list empty.\n", 84);
    if (index == 0) {
        free(list->first);
        list->first = NULL;
        list->len = 0;
        return 0;
    }
    last = list->first;
    for (; index > 1; index--) {
        if (last->next == NULL) {
            return qcs_puterror("delete_listi: index out of range.\n", 84);
        }
        last = last->next;
    }
    switch_elem(last);
    list->len = list->len - 1;
    return 0;
}

/* return the element at the given index of the list */
void *get_listi(c_list_t *list, unsigned int index)
{
    list_element_t *current = NULL;

    if (list->first == NULL) {
        qcs_puterror("get_listi: can't access, list is empty.\n", 84);
        return NULL;
    }
    current = list->first;
    for (; index > 0; index--) {
        if (current->next == NULL) {
            qcs_puterror("get_listi: index out of range.\n", 84);
            return NULL;
        }
        current = current->next;
    }
    return current->content;
}
