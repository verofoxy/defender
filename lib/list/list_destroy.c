/*
** EPITECH PROJECT, 2019
** Runner
** File description:
** list_destroy.c
*/

#include <stdlib.h>
#include "list.h"

void list_destroy(list_t **list, void (*element_destroy)())
{
    list_t *tmp;
    while ((*list) != NULL) {
        tmp = (*list)->next;
        (*element_destroy)((*list)->element);
        free(*list);
        *list = tmp;
    }
}

void list_element_destroy(list_t **list, void *ele, void (*element_destroy)())
{
    int i = 0;
    list_t *tmp = *list;

    while (tmp)  {
        if (tmp->element == ele) {
            list_remove_from_index(list, i, element_destroy);
            break;
        }
        i++;
        tmp = tmp->next;
    }
}