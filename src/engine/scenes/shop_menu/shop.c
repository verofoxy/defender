/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** shop.c
*/

#include "game.h"
#include "game_object.h"
#include "scene.h"
#include "shop.h"
#include "text.h"

void create_btn(shop_t *shop)
{
    btn_t *canon_btn = create_canon_btn();
    btn_t *archer_btn = create_archer_btn();
    btn_t *slow_btn = create_slow_btn();
    btn_t *booster_btn = create_booster_btn();

    list_push(&shop->btns, canon_btn, "canon_btn");
    list_push(&shop->btns, archer_btn, "archer_btn");
    list_push(&shop->btns, slow_btn, "slow_btn");
    list_push(&shop->btns, booster_btn, "booster_btn");
}

shop_t *create_shop(int coins)
{
    shop_t *shop = malloc(sizeof(*(shop)));

    shop->btns = NULL;
    shop->coins_img = NULL;
    shop->background = create_image(BACKGROUND_SHOP, NULL);
    shop->coins_img = create_image(COINS_PATH, NULL);
    shop->nbr_coins = coins;
    shop->is_displayed = false;
    shop->coins_txt = create_label(GROBOLD_PATH, 35,
    m_itos(shop->nbr_coins), sfWhite);
    create_btn(shop);
    sfSprite_setPosition(shop->background->sprite,
    (sfVector2f) { 30, 670});
    sfSprite_setPosition(shop->coins_img->sprite,
    (sfVector2f) { 130.0, 50.0});
    sfText_setPosition(shop->coins_txt->txt,
    (sfVector2f) {170.0, 40.0});
    return shop;
}

void destroy_shop(shop_t *shop)
{
    image_destroy(shop->background);
    image_destroy(shop->coins_img);
    free(shop);
}

void set_status_shop(list_t *btns, int coins, game_sys_t *sys)
{
    int index = 0, tmp = 0;
    list_t *tmp_list = NULL;
    while (index != 4) {
        tmp_list = btns;
        for (tmp = 0; tmp < index; tmp++)
            tmp_list = tmp_list->next;
        have_enough_coins(list_get_from_index(btns, index), coins,
        tmp_list->tag);
        index++;
    }
    index = 0;
    while (index != 4) {
        set_state_btn(list_get_from_index(btns, index), sys->mouse_pos);
        index++;
    }
}

void draw_shop(game_sys_t *sys, shop_t *shop)
{
    int index = 0;
    list_t *btns = shop->btns;

    change_text(shop->coins_txt, m_itos(shop->nbr_coins));
    sfRenderWindow_drawSprite(sys->window, shop->coins_img->sprite, NULL);
    sfRenderWindow_drawText(sys->window, shop->coins_txt->txt, NULL);
    if (!shop->is_displayed)
        return;
    sfRenderWindow_drawSprite(sys->window, shop->background->sprite,
    NULL);
    while (index != 4) {
        draw_btn(list_get_from_index(btns, index), sys);
        index++;
    }
}