/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** btn_gameover_menu.c
*/

#include "scene.h"
#include "gameover.h"

btn_t *create_replay_btn(void)
{
    image_t *btn_replay_img_idle = create_image(REPLAY_BTN, NULL);
    image_t *btn_replay_img_dis = create_image(REPLAY_DIS, NULL);
    image_t *btn_replay_img_hov = create_image(REPLAY_HOV, NULL);
    list_t *btn_states_replay = NULL;
    btn_t *btn_replay = NULL;

    list_push(&btn_states_replay, btn_replay_img_idle, "idle");
    list_push(&btn_states_replay, btn_replay_img_dis, "disabled");
    list_push(&btn_states_replay, btn_replay_img_hov, "hover");
    btn_replay = create_button(btn_states_replay,
    (sfIntRect) {500, 600, 300, 155}, &change_scene);
    return btn_replay;
}

btn_t *create_ext_btn(void)
{
    sfIntRect place = {1000, 600, 300, 155};
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

void create_gameover_btn(gameover_t *gameover)
{
    btn_t *replay_btn = create_replay_btn();
    btn_t *exit_btn = create_ext_btn();

    list_push(&gameover->btns, replay_btn, "replay_btn");
    list_push(&gameover->btns, exit_btn, "exit_btn");
}
