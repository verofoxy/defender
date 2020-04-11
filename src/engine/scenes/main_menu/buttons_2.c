/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** buttons_2.c
*/

#include "scene.h"
#include "main_menu.h"
#include "window.h"
#include "res.h"

btn_t *create_help_btn(void)
{
    sfIntRect place = {160, 130, 64, 64};
    image_t *btn_help_img_idle = create_image(HELP_BTN, NULL);
    image_t *btn_help_img_dis = create_image(HELP_DIS, NULL);
    image_t *btn_help_img_hov = create_image(HELP_HOV, NULL);
    list_t *btn_states_help = NULL;
    btn_t *btn_help = NULL;

    list_push(&btn_states_help, btn_help_img_idle, "idle");
    list_push(&btn_states_help, btn_help_img_dis, "disabled");
    list_push(&btn_states_help, btn_help_img_hov, "hover");
    btn_help = create_button(btn_states_help, place, change_scene);
    return btn_help;
}

void create_btn_main_menu(main_menu_t *main_menu)
{
    btn_t *play_btn = create_play_btn();
    btn_t *credit_btn = create_credit_btn();
    btn_t *exit_btn = create_exit_btn();
    btn_t *music_btn = create_music_btn();
    btn_t *sound_effect_btn = create_sound_effect_btn();
    btn_t *help_btn = create_help_btn();

    list_push(&main_menu->btns, play_btn, "play_btn");
    list_push(&main_menu->btns, credit_btn, "credit_btn");
    list_push(&main_menu->btns, exit_btn, "exit_btn");
    list_push(&main_menu->btns, music_btn, "music_btn");
    list_push(&main_menu->btns, sound_effect_btn, "sound_effect_btn");
    list_push(&main_menu->btns, help_btn, "help_btn");
}