/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** scene.h
*/

#include "system.h"
#include "image.h"
#include "res.h"

#ifndef MUL_MY_DEFENDER_2019_SCENE_H
#define MUL_MY_DEFENDER_2019_SCENE_H

#define EXIT_SCENE      -1
#define MENU_SCENE      0
#define LEVEL1_SCENE    1
#define CREDITS_SCENE   2
#define HOW_SCENE       3
#define GO_SCENE        4
#define VICTORY_SCENE   5
#define PAUSE_SCENE     6



typedef struct scene {
    int id;
    void (*callback)();
} scene_t;

void scene1(game_sys_t *sys);
scene_t get_scene(int id);
void main_menu_scene(game_sys_t *sys);
void gameover_scene(game_sys_t *sys);
void victory_scene(game_sys_t* sys);
void credit_scene(game_sys_t *sys);
void how_scene(game_sys_t *sys);

static const scene_t ALL_SCENES[] = {
    {MENU_SCENE, &main_menu_scene},
    {CREDITS_SCENE, &credit_scene},
    {GO_SCENE, &gameover_scene},
    {LEVEL1_SCENE, &scene1},
    {VICTORY_SCENE, &victory_scene},
    {HOW_SCENE, &how_scene},
    {EXIT_SCENE, NULL}
};
static const int NB_SCENES = 7;


#endif
