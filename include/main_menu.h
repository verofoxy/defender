/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** main_menu.h
*/

#ifndef MUL_MY_DEFENDER_2019_MAIN_MENU_H
#define MUL_MY_DEFENDER_2019_MAIN_MENU_H


typedef struct main_menu{
    list_t *btns;
    image_t *title;
    image_t *cadre;
} main_menu_t;

btn_t *create_play_btn(void);
btn_t *create_credit_btn(void);
btn_t *create_exit_btn(void);
btn_t *create_music_btn(void);
btn_t *create_sound_effect_btn(void);
btn_t *create_help_btn(void);
btn_t *create_back_btn(void);
void create_btn_main_menu(main_menu_t *main_menu);
main_menu_t *create_main_menu(void);
void destroy_main_menu(main_menu_t *main_menu);
void set_status_main_menu(list_t *btns, game_sys_t *sys);
void draw_main_menu(game_sys_t *sys, main_menu_t *main_menu);
void manage_events (game_sys_t *sys, main_menu_t *main_menu);
void main_menu_scene(game_sys_t *sys);
void setup_shadow(sfRectangleShape *shadow);
void credits_event(game_sys_t *sys, btn_t *exit_btn);
void destroy_sub_scene(main_menu_t *main_menu, image_t *board,
sfRectangleShape *shadow, btn_t *exit_btn);


#endif
