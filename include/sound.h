/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** sound.h
*/

#ifndef MUL_MY_DEFENDER_2019_SOUND_H
#define MUL_MY_DEFENDER_2019_SOUND_H

#include "game.h"

typedef struct sound {
    sfSoundBuffer *buffer;
    sfSound *sound;
    bool is_sfx;
} sound_t;

sound_t *create_sound(char const *filepath, float volume, bool loop, bool sfx);
list_t *load_soundtracks(void);
void destroy_sound(sound_t *sound);
void play_sound(sound_t *snd);
void stop_sound(sound_t *snd);

#endif