/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** animation.h
*/

#ifndef MUL_MY_DEFENDER_2019_ANIMATION_H
#define MUL_MY_DEFENDER_2019_ANIMATION_H

#include <SFML/Graphics.h>
#include "game.h"
#include "game_object.h"
typedef struct animation
{
    int loop;
    int finished;
    int nb_frames;
    float curr_frame;
    float time_anim;
    float curr_time;
    char *switch_to;
    const sfIntRect *frames;
} animation_t;

animation_t *create_animation(int nb_frames, const sfIntRect *frames, float
total_time, int loop);
void change_frame(animation_t *anim, sfTime time_past);
void set_animation_duration(animation_t *anim, float n_time);
void animation_destroy(animation_t *anim);
void play_animation(game_object *obj, sfClock *clock);
void add_animation(game_object *obj, animation_t *n_anim, char *tag);
void change_animation(game_object *obj, char *tag_anim, char
*switch_after);
#endif