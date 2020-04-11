/*
** EPITECH PROJECT, 2019
** myPrintf
** File description:
** is_alpha.c
*/

#include <stdbool.h>
#define MAJ_BEGINNING   65
#define MAJ_ENDING      90
#define MIN_BEGINNING   97
#define MIN_ENDING      122

bool is_alpha(char c)
{
    return ((c >= MAJ_BEGINNING && c <= MAJ_ENDING) ||
    (c >= MIN_BEGINNING && c <= MIN_ENDING))
    ? true
    : false;
}