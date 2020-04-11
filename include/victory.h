/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** victory.h
*/

#ifndef MUL_MY_DEFENDER_2019_VICTORY_H
#define MUL_MY_DEFENDER_2019_VICTORY_H

typedef struct victory{
    list_t *btns;
    image_t *cadre;
} victory_t;

victory_t *create_victory(void);
void destroy_victory(victory_t *victory);
btn_t *create_close_btn(void);
void create_victory_btn(victory_t *victory);
void set_status_victory(list_t *btns, game_sys_t *sys);
void draw_victory(game_sys_t *sys, victory_t*victory);
void victory_scene(game_sys_t *sys);
void callback_victory(game_sys_t *sys, victory_t *victory, sfEvent event);
void  events_victory(game_sys_t *sys, victory_t* victory);
#endif
