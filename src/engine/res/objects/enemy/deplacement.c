/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** deplacement.c
*/

#include "game.h"
#include "game_object.h"

void move_left(game_object *obj, sfClock *clock)
{
    float pasted_time = sfTime_asSeconds(sfClock_getElapsedTime(clock));
    sfVector2f offset = {-1 * obj->entity->stat->move_speed *
    obj->entity->stat->slowing * pasted_time, 0};
    sfSprite_move(obj->entity->spritesheet->sprite, offset);
    sfCircleShape_move(obj->hitbox->rendering, offset);
    sfText_move(obj->entity->stat->life_lbl->txt, offset);
}

void move_right(game_object *obj, sfClock *clock)
{
    float pasted_time = sfTime_asSeconds(sfClock_getElapsedTime(clock));
    sfVector2f offset = {1 * obj->entity->stat->move_speed *
    obj->entity->stat->slowing * pasted_time, 0};
    sfSprite_move(obj->entity->spritesheet->sprite, offset);
    sfCircleShape_move(obj->hitbox->rendering, offset);
    sfText_move(obj->entity->stat->life_lbl->txt, offset);
}

void move_top(game_object *obj, sfClock *clock)
{
    float pasted_time = sfTime_asSeconds(sfClock_getElapsedTime(clock));
    sfVector2f offset = {0, -1 * obj->entity->stat->move_speed *
    obj->entity->stat->slowing * pasted_time};
    sfSprite_move(obj->entity->spritesheet->sprite, offset);
    sfCircleShape_move(obj->hitbox->rendering, offset);
    sfText_move(obj->entity->stat->life_lbl->txt, offset);
}

void move_bottom(game_object *obj, sfClock *clock)
{
    float pasted_time = sfTime_asSeconds(sfClock_getElapsedTime(clock));
    sfVector2f offset = {0, 1 * obj->entity->stat->move_speed *
    obj->entity->stat->slowing * pasted_time};
    sfSprite_move(obj->entity->spritesheet->sprite, offset);
    sfCircleShape_move(obj->hitbox->rendering, offset);
    sfText_move(obj->entity->stat->life_lbl->txt, offset);
}
