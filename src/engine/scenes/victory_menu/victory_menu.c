/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** victory_menu.c
*/

#include "game_object.h"
#include "scene.h"
#include "victory.h"
#include "map.h"
#include "sound.h"

void set_status_victory(list_t *btns, game_sys_t *sys)
{
    int index = 0;

    while (index != 1) {
        set_state_btn(list_get_from_index(btns, index), sys->mouse_pos);
        index++;
    }
}

void draw_victory(game_sys_t *sys, victory_t *victory)
{
    int index = 0;
    list_t *btns = victory->btns;

    sfRenderWindow_drawSprite(sys->window, victory->cadre->sprite, NULL);
    while (index != 1) {
        draw_btn(list_get_from_index(btns, index), sys);
        index++;
    }
}

void victory_scene(game_sys_t *sys)
{
    victory_t *victory = create_victory();
    map_t *map = load_map("./map_level2.txt");

    play_sound(list_get_from_tag(sys->osts, "victory"));
    while (is_open_window(sys->window) && sys->actual_scene == VICTORY_SCENE) {
        sys->mouse_pos = sfMouse_getPositionRenderWindow(sys->window);
        set_status_victory(victory->btns, sys);
        events_victory(sys, victory);
        sfRenderWindow_clear(sys->window, sfBlack);
        transform_to_image(map, sys->window);
        draw_victory(sys, victory);
        sfRenderWindow_display(sys->window);
    }
    destroy_victory(victory);
    stop_sound(list_get_from_tag(sys->osts, "victory"));
}
