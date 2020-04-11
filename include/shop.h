/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** shop.h
*/

#ifndef MUL_MY_DEFENDER_2019_SHOP_H
#define MUL_MY_DEFENDER_2019_SHOP_H

#include "my.h"
#include "game.h"
#include "window.h"
#include "map.h"
#include "text.h"

typedef struct shop {
    list_t *btns;
    image_t *coins_img;
    image_t *background;
    int nbr_coins;
    label_t *coins_txt;
    bool is_displayed;
} shop_t;

shop_t *create_shop(int coins);
void set_status_shop(list_t *btns, int coins, game_sys_t *sys);
void destroy_shop(shop_t *shop);
void draw_shop(game_sys_t *sys, shop_t *shop);
void have_enough_coins(btn_t *btn, int coins, char const *tower_name);

btn_t *create_slow_btn(void);
btn_t *create_archer_btn(void);
btn_t *create_canon_btn(void);
btn_t *create_booster_btn(void);
#endif
