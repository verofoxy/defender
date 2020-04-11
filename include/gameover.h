/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** gameover.h
*/

#ifndef MUL_MY_DEFENDER_2019_GAMEOVER_H
#define MUL_MY_DEFENDER_2019_GAMEOVER_H

typedef struct gameover{
    list_t *btns;
    image_t *cadre;
} gameover_t;

void set_status_gameover(list_t *btns, game_sys_t *sys);
void draw_gameover(game_sys_t *sys, gameover_t*gameover);
void gameover_scene(game_sys_t *sys);
btn_t *create_replay_btn(void);
btn_t *create_ext_btn(void);
void create_gameover_btn(gameover_t *gameover);
gameover_t *create_gameover(void);
void destroy_gameover(gameover_t *gameover);
void callback_gameover(game_sys_t *sys, gameover_t *gameover, sfEvent event);
void  events_gameover(game_sys_t *sys, gameover_t* gameover);

#endif
