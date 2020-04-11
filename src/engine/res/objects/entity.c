/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** entity.c
*/

#include "game.h"
#include "game_object.h"
#include "animation.h"

void animate_buildings(list_t *towers, sfClock *clock)
{
    while (towers) {
        play_animation(towers->element, clock);
        towers = towers->next;
    }
}

void entity_destroy(entity_t *ent)
{
    image_destroy(ent->spritesheet);
    destroy_stat(ent->stat);
    free(ent);
}