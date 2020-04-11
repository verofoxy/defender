/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** pause_btns.c
*/

#include "game.h"
#include "scene.h"
#include "pause.h"
#include "sound.h"

btn_t *create_continue_btn(void)
{
    sfIntRect place = {830, 250, 300, 155};
    image_t *btn_continue_img_idle = create_image(CONTINUE_BTN, NULL);
    image_t *btn_continue_img_dis = create_image(CONTINUE_DIS, NULL);
    image_t *btn_continue_img_hov = create_image(CONTINUE_HOV, NULL);
    list_t *btn_states_continue = NULL;
    btn_t *btn_continue = NULL;

    list_push(&btn_states_continue, btn_continue_img_idle, "idle");
    list_push(&btn_states_continue, btn_continue_img_dis, "disabled");
    list_push(&btn_states_continue, btn_continue_img_hov, "hover");
    btn_continue = create_button(btn_states_continue, place, change_scene);
    return btn_continue;
}

btn_t *create_restart_btn(void)
{
    sfIntRect place = {830, 450, 300, 155};
    image_t *btn_restart_img_idle = create_image(RESTART_BTN, NULL);
    image_t *btn_restart_img_dis = create_image(RESTART_DIS, NULL);
    image_t *btn_restart_img_hov = create_image(RESTART_HOV, NULL);
    list_t *btn_states_restart = NULL;
    btn_t *btn_restart = NULL;

    list_push(&btn_states_restart, btn_restart_img_idle, "idle");
    list_push(&btn_states_restart, btn_restart_img_dis, "disabled");
    list_push(&btn_states_restart, btn_restart_img_hov, "hover");
    btn_restart = create_button(btn_states_restart,
    place, change_scene);
    return btn_restart;
}

btn_t *create_quit_btn(void)
{
    sfIntRect place = {830, 650, 300, 155};
    image_t *btn_quit_img_idle = create_image(QUIT_BTN, NULL);
    image_t *btn_quit_img_dis = create_image(QUIT_DIS, NULL);
    image_t *btn_quit_img_hov = create_image(QUIT_HOV, NULL);
    list_t *btn_states_quit = NULL;
    btn_t *btn_quit = NULL;

    list_push(&btn_states_quit, btn_quit_img_idle, "idle");
    list_push(&btn_states_quit, btn_quit_img_dis, "disabled");
    list_push(&btn_states_quit, btn_quit_img_hov, "hover");
    btn_quit = create_button(btn_states_quit, place, change_scene);
    return btn_quit;
}

void create_btn_menu_pause(pause_t *pause)
{
    btn_t *continue_btn = create_continue_btn();
    btn_t *restart_btn = create_restart_btn();
    btn_t *quit_btn = create_quit_btn();

    list_push(&pause->btns, continue_btn, "continue_btn");
    list_push(&pause->btns, restart_btn, "restart_btn");
    list_push(&pause->btns, quit_btn, "quit_btn");
}