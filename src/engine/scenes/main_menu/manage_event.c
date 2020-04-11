/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** mange_event.c
*/

#include "game.h"
#include "scene.h"
#include "main_menu.h"
#include "window.h"
#include "my.h"
#include "sound.h"

int check_exit_btn(game_sys_t *sys, main_menu_t *main_menu)
{
    if (btn_is_clicked(list_get_from_tag(main_menu->btns, "exit_btn"),
    sys->mouse_pos)) {
        ((btn_t *) list_get_from_tag(main_menu->btns,
        "exit_btn"))->callback(sys, EXIT_SCENE);
        ((btn_t *) list_get_from_tag(main_menu->btns,
        "exit_btn"))->enabled = true;
        play_sound(list_get_from_tag(sys->osts, "btn_click"));
        return EXEC_SUCCESS;
    }
    return EXEC_FAIL;
}

int main_btns(game_sys_t *sys, main_menu_t *main_menu)
{
    if (btn_is_clicked(list_get_from_tag(main_menu->btns, "play_btn"),
    sys->mouse_pos)) {
        ((btn_t *) list_get_from_tag(main_menu->btns,
        "play_btn"))->callback(sys, LEVEL1_SCENE);
        ((btn_t *) list_get_from_tag(main_menu->btns,
        "play_btn"))->enabled = true;
        play_sound(list_get_from_tag(sys->osts, "btn_click"));
        return EXEC_SUCCESS;
    }
    if (btn_is_clicked(list_get_from_tag(main_menu->btns, "credit_btn"),
    sys->mouse_pos)) {
        ((btn_t *) list_get_from_tag(main_menu->btns,
        "credit_btn"))->callback(sys, CREDITS_SCENE);
        ((btn_t *) list_get_from_tag(main_menu->btns,
        "credit_btn"))->enabled = true;
        play_sound(list_get_from_tag(sys->osts, "btn_click"));
        return EXEC_SUCCESS;
    }
    return check_exit_btn(sys, main_menu);
}

int settings_btn(game_sys_t *sys, main_menu_t *main_menu)
{
    if (btn_is_clicked(list_get_from_tag(main_menu->btns, "music_btn"),
    sys->mouse_pos)) {
        ((btn_t *) list_get_from_tag(main_menu->btns,
        "music_btn"))->callback(sys, LEVEL1_SCENE);
        ((btn_t *) list_get_from_tag(main_menu->btns,
        "music_btn"))->enabled = true;
        play_sound(list_get_from_tag(sys->osts, "btn_click"));
        return EXEC_SUCCESS;
    }
    if (btn_is_clicked(list_get_from_tag(main_menu->btns,
    "sound_effect_btn"), sys->mouse_pos)) {
        ((btn_t *) list_get_from_tag(main_menu->btns,
        "sound_effect_btn"))->callback(sys, LEVEL1_SCENE);
        ((btn_t *) list_get_from_tag(main_menu->btns,
        "sound_effect_btn"))->enabled = true;
        play_sound(list_get_from_tag(sys->osts, "btn_click"));
        return EXEC_SUCCESS;
    }
    return EXEC_FAIL;
}

int help_check(game_sys_t *sys, main_menu_t *main_menu)
{
    if (btn_is_clicked(list_get_from_tag(main_menu->btns, "help_btn"),
    sys->mouse_pos)) {
        ((btn_t *) list_get_from_tag(main_menu->btns,
        "help_btn"))->callback(sys, HOW_SCENE);
        ((btn_t *) list_get_from_tag(main_menu->btns,
        "help_btn"))->enabled = true;
        play_sound(list_get_from_tag(sys->osts, "btn_click"));
        return EXEC_SUCCESS;
    }
    return EXEC_FAIL;
}

void manage_events(game_sys_t *sys, main_menu_t *main_menu)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(sys->window, &event)) {
        if (event.type == sfEvtClosed) {
            exit_game(sys);
            break;
        }
        if (event.type == sfEvtMouseButtonPressed) {
            CHECK_GOOD(main_btns(sys, main_menu))
            CHECK_GOOD(settings_btn(sys, main_menu))
            CHECK_GOOD(help_check(sys, main_menu));
        }
    }
}
