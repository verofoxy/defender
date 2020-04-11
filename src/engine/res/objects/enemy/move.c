/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** move.c
*/

#include "game.h"
#include "game_object.h"

void move_wave(list_t *enemies, sfClock *clock)
{
    while (enemies) {
        move_object(enemies->element, clock);
        enemies = enemies->next;
    }
}

void change_move(game_object *obj, char *move)
{
    obj->curr_move = move;
}

void move_enemy(game_object *enemy, sfClock *clock)
{
    if (!enemy->curr_move)
        return;
    ((void (*)()) list_get_from_tag(enemy->moves, enemy->curr_move))
    (enemy, clock);
}

void add_move(game_object *obj, void (*ptr)(), char *tag)
{
    list_push(&obj->moves, ptr, tag);
}