/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** buttons.c
*/

#include "scene.h"
#include "main_menu.h"
#include "window.h"
#include "res.h"

btn_t *create_play_btn(void)
{
    sfIntRect place = {750, 700, 300, 155};
    image_t *btn_play_img_idle = create_image(PLAY_BTN, NULL);
    image_t *btn_play_img_dis = create_image(PLAY_DIS, NULL);
    image_t *btn_play_img_hov = create_image(PLAY_HOV, NULL);
    list_t *btn_states_play = NULL;
    btn_t *btn_play = NULL;

    list_push(&btn_states_play, btn_play_img_idle, "idle");
    list_push(&btn_states_play, btn_play_img_dis, "disabled");
    list_push(&btn_states_play, btn_play_img_hov, "hover");
    btn_play = create_button(btn_states_play, place, change_scene);
    return btn_play;
}

btn_t *create_credit_btn(void)
{
    sfIntRect place =  {350, 550, 300, 155};
    image_t *btn_credit_img_idle = create_image(CREDIT_BTN, NULL);
    image_t *btn_credit_img_dis = create_image(CREDIT_DIS, NULL);
    image_t *btn_credit_img_hov = create_image(CREDIT_HOV, NULL);
    list_t *btn_states_credit = NULL;
    btn_t *btn_credit = NULL;

    list_push(&btn_states_credit, btn_credit_img_idle, "idle");
    list_push(&btn_states_credit, btn_credit_img_dis, "disabled");
    list_push(&btn_states_credit, btn_credit_img_hov, "hover");
    btn_credit = create_button(btn_states_credit, place, change_scene);
    return btn_credit;
}

btn_t *create_exit_btn(void)
{
    sfIntRect place = {1150, 550, 300, 155};
    image_t *btn_exit_img_idle = create_image(EXIT_BTN, NULL);
    image_t *btn_exit_img_dis = create_image(EXIT_DIS, NULL);
    image_t *btn_exit_img_hov = create_image(EXIT_HOV, NULL);
    list_t *btn_states_exit = NULL;
    btn_t *btn_exit = NULL;

    list_push(&btn_states_exit, btn_exit_img_idle, "idle");
    list_push(&btn_states_exit, btn_exit_img_dis, "disabled");
    list_push(&btn_states_exit, btn_exit_img_hov, "hover");
    btn_exit = create_button(btn_states_exit, place, exit_game);
    return btn_exit;
}

btn_t *create_music_btn(void)
{
    sfIntRect place = {1590, 850, 64, 64};
    image_t *btn_music_img_idle = create_image(MUSIC_BTN, NULL);
    image_t *btn_music_img_dis = create_image(MUSIC_DIS, NULL);
    image_t *btn_music_img_hov = create_image(MUSIC_HOV, NULL);
    list_t *btn_states_music = NULL;
    btn_t *btn_music = NULL;

    list_push(&btn_states_music, btn_music_img_idle, "idle");
    list_push(&btn_states_music, btn_music_img_dis, "disabled");
    list_push(&btn_states_music, btn_music_img_hov, "hover");
    btn_music = create_button(btn_states_music, place, change_scene);
    return btn_music;
}

btn_t *create_sound_effect_btn(void)
{
    sfIntRect place = {1690, 850, 64, 64};
    image_t *btn_sound_effect_img_idle = create_image(SOUND_EFFECT_BTN, NULL);
    image_t *btn_sound_effect_img_dis = create_image(SOUND_EFFECT_DIS, NULL);
    image_t *btn_sound_effect_img_hov = create_image(SOUND_EFFECT_HOV, NULL);
    list_t *btn_states_sound_effect = NULL;
    btn_t *btn_sound_effect = NULL;

    list_push(&btn_states_sound_effect, btn_sound_effect_img_idle, "idle");
    list_push(&btn_states_sound_effect, btn_sound_effect_img_dis, "disabled");
    list_push(&btn_states_sound_effect, btn_sound_effect_img_hov, "hover");
    btn_sound_effect = create_button(btn_states_sound_effect,
    place, change_scene);
    return btn_sound_effect;
}
