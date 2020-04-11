/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** scene.c
*/

#include "game.h"
#include "my.h"

scene_t get_scene(int id)
{
    int i = 0;

    for (i = 0; ALL_SCENES[i].id != -1; i++) {
        if (id == ALL_SCENES[i].id)
            break;
    }
    return ALL_SCENES[i];
}
