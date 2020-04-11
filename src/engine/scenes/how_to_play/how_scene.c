/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** how_scene.c
*/

#include "game.h"
#include "game_object.h"
#include "window.h"
#include "main_menu.h"
#include "map.h"
#include "sound.h"

btn_t *create_how_back_btn(void)
{
    sfIntRect place = {1215, 105, 80, 87};
    image_t *btn_exit_img_idle = create_image(BACK_DIS, NULL);
    image_t *btn_exit_img_dis = create_image(BACK_BTN, NULL);
    image_t *btn_exit_img_hov = create_image(BACK_HOV, NULL);
    list_t *btn_states_exit = NULL;
    btn_t *btn_exit = NULL;

    list_push(&btn_states_exit, btn_exit_img_idle, "idle");
    list_push(&btn_states_exit, btn_exit_img_dis, "disabled");
    list_push(&btn_states_exit, btn_exit_img_hov, "hover");
    btn_exit = create_button(btn_states_exit, place, change_scene);
    return btn_exit;
}

void how_scene(game_sys_t *sys)
{
    sfRectangleShape *shadow =  sfRectangleShape_create();
    main_menu_t *main_menu = create_main_menu();
    image_t *board = create_image(HOW_BOARD, NULL);
    setup_shadow(shadow);
    map_t *map = load_map("./map_level1.txt");
    sfSprite_setPosition(board->sprite, (sfVector2f) {600, 100});
    btn_t *exit_btn = create_how_back_btn();

    while (is_open_window(sys->window) && sys->actual_scene == HOW_SCENE) {
        set_state_btn(exit_btn, sys->mouse_pos);
        sys->mouse_pos = sfMouse_getPositionRenderWindow(sys->window);
        credits_event(sys, exit_btn);
        transform_to_image(map, sys->window);
        draw_main_menu(sys, main_menu);
        sfRenderWindow_drawRectangleShape(sys->window, shadow, NULL);
        sfRenderWindow_drawSprite(sys->window, board->sprite, NULL);
        draw_btn(exit_btn, sys);
        sfRenderWindow_display(sys->window);
    }
    destroy_sub_scene(main_menu, board, shadow, exit_btn);
}