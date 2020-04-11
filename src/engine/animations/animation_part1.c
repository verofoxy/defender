/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** animation_part1.c
*/

#include <stdlib.h>
#include "game_object.h"
#include "animation.h"
#include "my.h"

void change_animation(game_object *obj, char *tag_anim, char
*switch_after)
{
    animation_t *n_curr;
    if (tag_anim == NULL ||
        list_get_from_tag(obj->animations, tag_anim) == NULL)
        return;
    if (m_strcmp(tag_anim, obj->curr_anim) == 0)
        return;
    obj->curr_anim = tag_anim;
    n_curr = list_get_from_tag(obj->animations, tag_anim);
    n_curr->curr_time = 0;
    n_curr->curr_frame = 0;
    n_curr->finished = 0;
    n_curr->switch_to = switch_after;
}

void add_animation(game_object *obj, animation_t *n_anim, char *tag)
{
    if (n_anim == NULL || obj == NULL)
        return;
    list_push(&obj->animations, n_anim, tag);
    if (obj->curr_anim == NULL)
        obj->curr_anim = tag;
}
