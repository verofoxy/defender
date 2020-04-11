/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** gameover_callback.c
*/

#include "game.h"
#include "game_object.h"
#include "scene.h"
#include "gameover.h"
#include "map.h"

void callback_gameover(game_sys_t *sys, gameover_t *gameover, sfEvent event)
{
    if (btn_is_clicked(list_get_from_tag(gameover->btns, "replay_btn"),
    (sfVector2i) {event.mouseButton.x, event.mouseButton.y})) {
        ((btn_t *) list_get_from_tag(gameover->btns,
        "replay_btn"))->callback(sys, LEVEL1_SCENE);
        ((btn_t *) list_get_from_tag(gameover->btns,
        "replay_btn"))->enabled = true;
    }
    if (btn_is_clicked(list_get_from_tag(gameover->btns, "exit_btn"),
    (sfVector2i) {event.mouseButton.x, event.mouseButton.y})) {
        ((btn_t *) list_get_from_tag(gameover->btns,
        "exit_btn"))->callback(sys, MENU_SCENE);
        ((btn_t *) list_get_from_tag(gameover->btns,
        "exit_btn"))->enabled = true;
    }
}

void  events_gameover(game_sys_t *sys, gameover_t *gameover)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(sys->window, &event)) {
        if (event.type == sfEvtClosed) {
            exit_game(sys);
            break;
        }
        if (event.type == sfEvtMouseButtonPressed) {
            callback_gameover(sys, gameover, event);
        }
    }
}
