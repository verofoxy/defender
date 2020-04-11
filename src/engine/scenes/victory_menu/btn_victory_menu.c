/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** btn_victory_menu.c
*/

#include "scene.h"
#include "victory.h"

btn_t *create_close_btn(void)
{
    sfIntRect place = {770, 600, 300, 155};
    image_t *btn_exit_img_idle = create_image(EXIT_BTN, NULL);
    image_t *btn_exit_img_dis = create_image(EXIT_DIS, NULL);
    image_t *btn_exit_img_hov = create_image(EXIT_HOV, NULL);
    list_t *btn_states_exit = NULL;
    btn_t *btn_exit = NULL;

    list_push(&btn_states_exit, btn_exit_img_idle, "idle");
    list_push(&btn_states_exit, btn_exit_img_dis, "disabled");
    list_push(&btn_states_exit, btn_exit_img_hov, "hover");
    btn_exit = create_button(btn_states_exit, place, &change_scene);
    return btn_exit;
}

void create_victory_btn(victory_t *victory)
{
    btn_t *close_btn = create_close_btn();

    list_push(&victory->btns, close_btn, "close_btn");
}