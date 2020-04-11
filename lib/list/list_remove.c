/*
** EPITECH PROJECT, 2019
** Runner
** File description:
** list_remove.c
*/

#include <stdlib.h>
#include "list.h"
#include "../my/my.h"

void list_remove_from_index(list_t **list, int index, void (*element_destroy)())
{
    int i = 0;
    list_t *prev = NULL, *curr = *list, *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        if (i == index) {
            (*element_destroy)(curr->element);
            if (prev == NULL)
                *list = next;
            else
                prev->next = next;
        }
        prev = curr;
        curr = next;
        i += 1;
    }
}
void list_remove_from_tag(list_t **list, char const *tag, void
(*element_destroy)())
{
    list_t *prev = NULL, *curr = *list, *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        if (m_strcmp(tag, curr->tag) == 0) {
            (*element_destroy)(curr->element);
            if (prev == NULL)
                *list = next;
            else {
                prev->next = next;
            }
        }
        prev = curr;
        curr = next;
    }
}