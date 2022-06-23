# QCS
The non official Queue, Chained-List and Stack library.

## Index
* [Documentation](#documentation)
* [Stack](#stack)
* [Queue](#queue)
* [Chained List](#chained-list)
* [Info](#info)

## Documentation :
[documentation](https://openclassrooms.com/fr/courses/19980-apprenez-a-programmer-en-c/19868-les-piles-et-les-files)

## Stack :
```c
// my_stack.c
```
```c
/* add a new element on the top of the stack. */
void put_on_stack(my_stack_t *stack, char *content)
```
```c
/* remove the last element of a stack and return it's value. */
void *put_out_stack(my_stack_t *stack)
```
```c
/* allocate memory for a stack and return a pointer to it. */
my_stack_t *init_stack(void)
```
```c
/* free alocated space for a stack. */
void free_stack(my_stack_t *stack)
```

## Queue :
```c
// my_queue.c
```
```c
/* add a new element on the top of the queue. */
int put_on_queue(my_queue_t *queue, void *content)
```
```c
/* remove the first element of a queue and return it's value. */
void *put_out_queue(my_queue_t *queue)
```
```c
/* allocate memory for a queue and return a pointer to it. */
my_queue_t *init_queue(void)
```
```c
/* free alocated space for a queue. */
void free_queue(my_queue_t *queue)
```

## Chained List :
```c
// c_list.c
```
```c
/* add a new element on the top of the list. */
int put_on_list(c_list_t *list, void *content)
```
```c
/* remove the last element of a list and return it's value. */
void *put_out_list(c_list_t *list)
```
```c
/* allocate memory for a list and return a pointer to it. */
c_list_t *init_list(void)
```
```c
/* free alocated space for a list. */
void free_list(c_list_t *list)
```

-----

```c
// c_list_index.c
```
```c
/* allocate memory for an element and return it */
static list_element_t *allocate_elem(void *content)
```
```c
/* add a new element at the given index to the list. */
int insert_listi(c_list_t *list, unsigned int index, void *content)
```
```c
/* remove the element at the given index of the list. */
int delete_listi(c_list_t *list, unsigned int index)
```
```c
/* return the element at the given index of the list */
void *get_listi(c_list_t *list, unsigned int index)
```

## Info
Do not use functions in qcs_utility, they are only used for the library.
