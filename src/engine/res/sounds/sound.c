/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** sound.c
*/

#include "game.h"
#include "sound.h"

sound_t *create_sound(char const *filepath, float volume, bool loop, bool sfx)
{
    sound_t *snd = malloc(sizeof(*snd));

    CHECK_NULL(snd);
    snd->buffer = sfSoundBuffer_createFromFile(filepath);
    snd->sound = sfSound_create();
    snd->is_sfx = sfx;
    sfSound_setBuffer(snd->sound,  snd->buffer);
    sfSound_setLoop(snd->sound, loop);
    sfSound_setVolume(snd->sound, volume);
    return snd;
}

void destroy_sound(sound_t *snd)
{
    sfSound_destroy(snd->sound);
    sfSoundBuffer_destroy(snd->buffer);
    free(snd);
}

void play_sound(sound_t *snd)
{
    sfSound_play(snd->sound);
}

void stop_sound(sound_t *snd)
{
    sfSound_stop(snd->sound);
}

list_t *load_soundtracks(void)
{
    int i = 0;
    const char *sounds[] = {MAIN_THEME, FIGHT_THEME, CLICK_BTN_SFX,
    VICTORY_THEME, GAMEOVER_THEME, CANON_SFX, BOOST_SFX, FREEZE_SFX, NULL};
    const char *tags[] = {"main", "fight", "btn_click", "victory",
    "game_over", "canon", "boost", "freeze"};
    const float volumes[] = {60, 60, 40, 60, 60, 60, 80, 100};
    const bool loops[] = {true, true, false, true, true, false, false, false};
    const bool is_sfxs[] = {false, false, true,
    false, false, true, true, true};
    list_t *osts = NULL;
    sound_t *tmp = NULL;

    for (i = 0; sounds[i]; i++) {
        tmp = create_sound(sounds[i], volumes[i], loops[i], is_sfxs[i]);
        list_push(&osts, tmp, tags[i]);
    }
    return osts;
}
