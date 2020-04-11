/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** shop_btns.c
*/

#include "game.h"
#include "game_object.h"
#include "scene.h"

btn_t *create_canon_btn(void)
{
    image_t *btn_tower_canon_img_idle = create_image(CANON_BTN, NULL);
    image_t *btn_tower_canon_img_dis = create_image(CANON_BTN_DIS, NULL);
    image_t *btn_tower_canon_img_hov = create_image(CANON_BTN_HOV, NULL);
    list_t *btn_states_canon = NULL;
    btn_t *btn_tower_canon = NULL;

    list_push(&btn_states_canon, btn_tower_canon_img_idle, "idle");
    list_push(&btn_states_canon, btn_tower_canon_img_dis, "disabled");
    list_push(&btn_states_canon, btn_tower_canon_img_hov, "hover");
    btn_tower_canon = create_button(btn_states_canon,
    (sfIntRect) {170, 750, 179, 250}, buy_canon);
    return btn_tower_canon;
}

btn_t *create_archer_btn(void)
{
    image_t *btn_tower_archer_img_idle = create_image(ARCHER_BTN, NULL);
    image_t *btn_tower_archer_img_dis = create_image(ARCHER_BTN_DIS, NULL);
    image_t *btn_tower_archer_img_hov = create_image(ARCHER_BTN_HOV, NULL);
    list_t *btn_states_archer = NULL;
    btn_t *btn_tower_archer = NULL;

    list_push(&btn_states_archer, btn_tower_archer_img_idle, "idle");
    list_push(&btn_states_archer, btn_tower_archer_img_dis, "disabled");
    list_push(&btn_states_archer, btn_tower_archer_img_hov, "hover");
    btn_tower_archer = create_button(btn_states_archer,
    (sfIntRect) {370, 750, 179, 250}, buy_archer);
    return btn_tower_archer;
}

btn_t *create_slow_btn(void)
{
    image_t *btn_tower_slow_img_idle = create_image(SLOWT_BTN, NULL);
    image_t *btn_tower_slow_img_dis = create_image(SLOWT_BTN_DIS, NULL);
    image_t *btn_tower_slow_img_hov = create_image(SLOWT_BTN_HOV, NULL);
    list_t *btn_states_slow = NULL;
    btn_t *btn_tower_slow = NULL;

    list_push(&btn_states_slow, btn_tower_slow_img_idle, "idle");
    list_push(&btn_states_slow, btn_tower_slow_img_dis, "disabled");
    list_push(&btn_states_slow, btn_tower_slow_img_hov, "hover");
    btn_tower_slow = create_button(btn_states_slow,
    (sfIntRect) {570, 750, 179, 250}, buy_slow_tower);
    return btn_tower_slow;
}

btn_t *create_booster_btn(void)
{
    image_t *btn_tower_booster_img_idle = create_image(BOOSTER_BTN, NULL);
    image_t *btn_tower_booster_img_dis = create_image(BOOSTER_BTN_DIS, NULL);
    image_t *btn_tower_booster_img_hov = create_image(BOOSTER_BTN_HOV, NULL);
    list_t *btn_states_booster = NULL;
    btn_t *btn_tower_booster = NULL;

    list_push(&btn_states_booster, btn_tower_booster_img_idle, "idle");
    list_push(&btn_states_booster, btn_tower_booster_img_dis, "disabled");
    list_push(&btn_states_booster, btn_tower_booster_img_hov, "hover");
    btn_tower_booster = create_button(btn_states_booster,
    (sfIntRect) {770, 750, 179, 250}, buy_booster);
    return btn_tower_booster;
}