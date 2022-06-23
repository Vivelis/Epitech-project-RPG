/*
** EPITECH PROJECT, 2021
** pile-file
** File description:
** c_list.h
*/

#ifndef _C_LIST_H_
    #define _C_LIST_H_

typedef struct list_element_s list_element_t;
struct list_element_s {
    void *content;
    list_element_t *next;
};
typedef struct c_list_s {
    list_element_t *first;
    unsigned int len;
}c_list_t;

// c_list.c
int put_on_list(c_list_t *list, void *content);
void *put_out_list(c_list_t *list);
c_list_t *init_list(void);
void free_list(c_list_t *list);

// c_list_index.c
int insert_listi(c_list_t *list, unsigned int index, void *content);
int delete_listi(c_list_t *list, unsigned int index);
void *get_listi(c_list_t *list, unsigned int index);
#endif
