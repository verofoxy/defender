/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** shop_callback.c
*/

#include "game.h"
#include "game_object.h"
#include "shop.h"
#include "map.h"

void buy_slow_tower(list_t **towers, shop_t *shop, map_t *map)
{
    if (!shop->is_displayed)
        return;
    sfVector2i loc_pos = {(int) map->selected_location.x,
    (int) map->selected_location.y};
    game_object *tower = create_slow_tower_object(map->selected_location);

    list_push(towers, tower, NULL);
    shop->is_displayed = false;
    shop->nbr_coins -= 600;
    get_location(map, loc_pos)->tower = tower;
}

void buy_canon(list_t **towers, shop_t *shop, map_t *map)
{
    if (!shop->is_displayed)
        return;
    sfVector2i loc_pos = {(int) map->selected_location.x,
    (int) map->selected_location.y};
    game_object *tower = create_canon_object(map->selected_location);

    list_push(towers, tower, NULL);
    shop->is_displayed = false;
    shop->nbr_coins -= 600;
    get_location(map, loc_pos)->tower = tower;
}

void buy_archer(list_t **towers, shop_t *shop, map_t *map)
{
    if (!shop->is_displayed)
        return;
    sfVector2i loc_pos = {(int) map->selected_location.x,
    (int) map->selected_location.y};
    game_object *tower = create_archer_object(map->selected_location);

    list_push(towers, tower, NULL);
    shop->is_displayed = false;
    shop->nbr_coins -= 600;
    get_location(map, loc_pos)->tower = tower;
}

void buy_booster(list_t **towers, shop_t *shop, map_t *map)
{
    if (!shop->is_displayed)
        return;
    sfVector2i loc_pos = {(int) map->selected_location.x,
    (int) map->selected_location.y};
    game_object *tower = create_booster_object(map->selected_location);

    list_push(towers, tower, NULL);
    shop->nbr_coins -= 1000;
    shop->is_displayed = false;
    get_location(map, loc_pos)->tower = tower;
}

void check_shop_btns_pressed(list_t **towers, shop_t *shop, map_t *map,
game_sys_t *sys)
{
    list_t *tmp = shop->btns;
    btn_t *btn_tmp = NULL;

    if (!shop->is_displayed)
        return;
    while (tmp) {
        btn_tmp = tmp->element;
        if (btn_is_clicked(btn_tmp, sys->mouse_pos)) {
            btn_tmp->callback(towers, shop, map);
            btn_tmp->enabled = true;
            break;
        }
        tmp = tmp->next;
    }
}
