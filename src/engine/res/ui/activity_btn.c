/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** activity_btn.c
*/

#include <stdlib.h>
#include "game.h"
#include "res.h"
#include "image.h"
#include "my.h"

bool btn_is_clicked(btn_t *btn, sfVector2i click_pos)
{
    if (!btn->enabled)
        return false;
    if (sfIntRect_contains(&btn->ctrl_area, (int) click_pos.x,
    (int) click_pos.y)) {
        btn->enabled = false;
        return true;
    }
    btn->state = "idle";
    return false;
}

void set_state_btn(btn_t *btn, sfVector2i mouse_pos)
{
    if (!btn->enabled) {
        btn->state = "disabled";
        return;
    }
    if (sfIntRect_contains(&btn->ctrl_area, mouse_pos.x, mouse_pos.y))
        btn->state = "hover";
    else
        btn->state = "idle";
}

int check_coins_part1(btn_t *btn, int coins, char const *tower_name)
{
    if (m_strcmp(tower_name, "archer_btn") == 0 && coins < 400)
        btn->enabled = false;
    else if (m_strcmp(tower_name, "archer_btn") == 0) {
        btn->enabled = true;
        return EXEC_SUCCESS;
    }
    if (m_strcmp(tower_name, "canon_btn") == 0 && coins < 800)
        btn->enabled = false;
    else if (m_strcmp(tower_name, "canon_btn") == 0) {
        btn->enabled = true;
        return EXIT_SUCCESS;
    }
    return EXEC_FAIL;
}

void have_enough_coins(btn_t *btn, int coins, char const *tower_name)
{
    CHECK_GOOD(check_coins_part1(btn, coins, tower_name));
    if (m_strcmp(tower_name, "slow_btn") == 0 && coins < 400)
        btn->enabled = false;
    else if (m_strcmp(tower_name, "slow_btn") == 0) {
        btn->enabled = true;
        return;
    }
    if (m_strcmp(tower_name, "booster_btn") == 0 && coins < 1000)
        btn->enabled = false;
    else if (m_strcmp(tower_name, "booster_btn") == 0) {
        btn->enabled = true;
        return;
    }
}