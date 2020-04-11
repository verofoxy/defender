/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** game_system.c
*/

#include <stdlib.h>
#include "game.h"
#include "window.h"
#include "system.h"
#include "sound.h"

game_sys_t *system_create(void)
{
    game_sys_t *sys = malloc(sizeof(*sys));

    CHECK_NULL(sys)
    sys->actual_scene = MENU_SCENE;
    sys->window = create_window(W_WIN, H_WIN, "MyDefender", DEFAULT_FPS);
    sys->osts = load_soundtracks();
    return sys;
}

void exit_game(game_sys_t *sys)
{
    close_window(sys->window);
    change_scene(sys, EXIT_SCENE);
}

void change_scene(game_sys_t *sys, int id)
{
    sys->actual_scene = id;
}

int system_destroy(game_sys_t *sys)
{
    sfRenderWindow_destroy(sys->window);
    list_destroy(&sys->osts, destroy_sound);
    free(sys);
    return EXEC_SUCCESS;
}