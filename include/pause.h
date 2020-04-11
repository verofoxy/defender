/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** pause.h
*/

#include "system.h"
#include "image.h"
#include "res.h"
#include "list.h"
#include "my.h"
#include "window.h"

#ifndef MUL_MY_DEFENDER_2019_PAUSE_H
#define MUL_MY_DEFENDER_2019_PAUSE_H

void pause_scene(game_sys_t *sys, sfClock *clock, int actual_scene, bool *r);

typedef struct pause {
    list_t *btns;
    image_t *background;
} pause_t;

btn_t *create_continue_btn(void);
btn_t *create_restart_btn(void);
btn_t *create_quit_btn(void);
void create_btn_menu_pause(pause_t *pause);
void check_paused_pressed(list_t *btns, game_sys_t *sys, int current, bool *r);

#endif
