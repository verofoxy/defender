/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** system.h
*/

#ifndef MUL_MY_DEFENDER_2019_SYSTEM_H
#define MUL_MY_DEFENDER_2019_SYSTEM_H

#include <SFML/Graphics.h>
#include "list.h"

typedef struct game_system {
    sfRenderWindow *window;
    int actual_scene;
    list_t *osts;
    list_t *settings;
    sfVector2i mouse_pos;
} game_sys_t;

game_sys_t *system_create(void);
void change_scene(game_sys_t *sys, int id);
void exit_game(game_sys_t *sys);
int system_destroy(game_sys_t *sys);

#endif