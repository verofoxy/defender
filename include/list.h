/*
** EPITECH PROJECT, 2019
** Runner
** File description:
** list.h
*/

#ifndef RUNNER_LIST_H
#define RUNNER_LIST_H

typedef struct linked_list
{
    char const *tag;
    void *element;
    struct linked_list *next;
} list_t;

void list_push(list_t **head, void *element, char const *tag);
void list_destroy(list_t **list, void (*)());
void *list_get_from_index(list_t *list, int index);
void *list_get_from_tag(list_t *list, char const *tag);
list_t *list_reverse(list_t *head);
void list_concat(list_t **dest, list_t *src);
void list_remove_from_index(list_t **list, int index, void (*)());
void list_remove_from_tag(list_t **list, char const *tag, void(*)());
int list_get_length(list_t *list);
void list_element_destroy(list_t **list, void *ele, void (*element_destroy)());

#endif
