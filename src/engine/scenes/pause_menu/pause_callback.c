/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** pause_callback.c
*/

#include "game.h"
#include "scene.h"
#include "system.h"
#include "sound.h"

void pressed_quit(list_t *btns, game_sys_t *sys)
{
    if (btn_is_clicked(list_get_from_tag(btns, "quit_btn"),
    sys->mouse_pos)) {
        ((btn_t *) list_get_from_tag(btns, "quit_btn"))->callback(sys,
        MENU_SCENE);
        ((btn_t *) list_get_from_tag(btns, "quit_btn"))->enabled = true;
        play_sound(list_get_from_tag(sys->osts, "btn_click"));
        return;
    }
}

void check_paused_pressed(list_t *btns, game_sys_t *sys, int current, bool *r)
{
    if (btn_is_clicked(list_get_from_tag(btns, "continue_btn"),
    sys->mouse_pos)) {
        ((btn_t *) list_get_from_tag(btns, "continue_btn"))->callback
        (sys, current);
        ((btn_t *) list_get_from_tag(btns, "continue_btn"))->enabled = true;
        play_sound(list_get_from_tag(sys->osts, "btn_click"));
        return;
    }
    if (btn_is_clicked(list_get_from_tag(btns, "restart_btn"),
    sys->mouse_pos)) {
        *r = true;
        ((btn_t *) list_get_from_tag(btns, "restart_btn"))->callback(sys,
        current);
        ((btn_t *) list_get_from_tag(btns, "restart_btn"))->enabled = true;
        play_sound(list_get_from_tag(sys->osts, "btn_click"));
        return;
    }
    pressed_quit(btns, sys);
}
