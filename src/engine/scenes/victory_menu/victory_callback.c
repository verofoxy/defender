/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** victory_callback.c
*/

#include "scene.h"
#include "victory.h"

void callback_victory(game_sys_t *sys, victory_t *victory, sfEvent event)
{
    if (btn_is_clicked(list_get_from_tag(victory->btns, "close_btn"),
    (sfVector2i) {event.mouseButton.x, event.mouseButton.y})) {
        ((btn_t *) list_get_from_tag(victory->btns,
        "close_btn"))->callback(sys, MENU_SCENE);
        ((btn_t *) list_get_from_tag(victory->btns,
        "close_btn"))->enabled = true;
    }
}

void  events_victory(game_sys_t *sys, victory_t *victory)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(sys->window, &event)) {
        if (event.type == sfEvtClosed) {
            exit_game(sys);
            break;
        }
        if (event.type == sfEvtMouseButtonPressed) {
            callback_victory(sys, victory, event);
        }
    }
}
