/*
** EPITECH PROJECT, 2019
** Runner
** File description:
** push_in.c
*/

#include <stdlib.h>
#include "list.h"

void list_push(list_t **head, void *element, char const *tag)
{
    list_t *n_element = malloc(sizeof(*n_element));

    n_element->element = element;
    n_element->next = *head;
    n_element->tag = tag;
    *head = n_element;
}