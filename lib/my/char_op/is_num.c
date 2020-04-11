/*
** EPITECH PROJECT, 2019
** myPrintf
** File description:
** is_num.c
*/

#include <stdbool.h>
#define NUM_BEGINNING   48
#define NUM_ENDING      57

bool is_num(char c)
{
    return (c >= NUM_BEGINNING && c <= NUM_ENDING)
    ? true
    : false;
}