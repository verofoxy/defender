/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** gameover.c
*/

#include "game.h"
#include "game_object.h"
#include "scene.h"
#include "gameover.h"
#include "main_menu.h"
#include "map.h"
#include "sound.h"

void set_status_gameover(list_t *btns, game_sys_t *sys)
{
    int index = 0;

    while (index != 2) {
        set_state_btn(list_get_from_index(btns, index), sys->mouse_pos);
        index++;
    }
}

void draw_gameover(game_sys_t *sys, gameover_t *gameover)
{
    int index = 0;
    list_t *btns = gameover->btns;

    sfRenderWindow_drawSprite(sys->window, gameover->cadre->sprite,
    NULL);
    while (index != 2) {
        draw_btn(list_get_from_index(btns, index), sys);
        index++;
    }
}

void gameover_scene(game_sys_t *sys)
{
    gameover_t *gameover = create_gameover();
    sfRectangleShape *shadow =  sfRectangleShape_create();
    map_t *map = load_map("./map_level2.txt");
    setup_shadow(shadow);
    play_sound(list_get_from_tag(sys->osts, "game_over"));
    while (is_open_window(sys->window) && sys->actual_scene == GO_SCENE) {
        sys->mouse_pos = sfMouse_getPositionRenderWindow(sys->window);
        set_status_gameover(gameover->btns, sys);
        events_gameover(sys, gameover);
        sfRenderWindow_clear(sys->window, sfBlack);
        transform_to_image(map, sys->window);
        sfRenderWindow_drawRectangleShape(sys->window, shadow, NULL);
        draw_gameover(sys, gameover);
        sfRenderWindow_display(sys->window);
    }
    stop_sound(list_get_from_tag(sys->osts, "game_over"));
    destroy_gameover(gameover);
    sfRectangleShape_destroy(shadow);
}
