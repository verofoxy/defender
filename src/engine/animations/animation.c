/*
** EPITECH PROJECT, 2019
** Runner
** File description:
** animations.c
*/

#include <stdlib.h>
#include "game_object.h"
#include "animation.h"
#include "my.h"

animation_t *create_animation(int nb_frames, const sfIntRect *frames, float
total_time, int loop)
{
    animation_t *anim = malloc(sizeof(*anim));

    anim->frames = frames;
    anim->nb_frames  = nb_frames;
    anim->curr_frame = 0;
    anim->curr_time = 0;
    anim->finished = 0;
    anim->switch_to = NULL;
    anim->loop = loop;
    anim->time_anim = total_time;
    return anim;
}

void play_animation(game_object *obj, sfClock *clock)
{
    animation_t *curr = list_get_from_tag(obj->animations, obj->curr_anim);
    sfTime time_past = sfClock_getElapsedTime(clock);
    if (curr->finished && curr->switch_to != NULL)
        change_animation(obj, curr->switch_to, NULL);
    change_frame(curr, time_past);
    sfSprite_setTextureRect(obj->entity->spritesheet->sprite,
    curr->frames[(int)curr->curr_frame]);
}

void change_frame(animation_t *anim, sfTime time_past)
{
    anim->curr_time += sfTime_asSeconds(time_past);

    anim->curr_frame = (anim->curr_time / anim->time_anim) *
    (float) anim->nb_frames;
    if (anim->curr_frame >= (float) anim->nb_frames)
        anim->curr_frame -= 1;
    if (anim->curr_time >= anim->time_anim) {
        if (anim->loop)
            anim->curr_time = 0;
        else {
            anim->curr_time = anim->time_anim;
            anim->finished = 1;
        }
    }
}

void set_animation_duration(animation_t *anim, float n_time)
{
    anim->time_anim = n_time;
}

void animation_destroy(animation_t *anim)
{
    free(anim);
}
