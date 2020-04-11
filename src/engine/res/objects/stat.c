/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** stat.c
*/

#include "game.h"
#include "game_object.h"
#include "text.h"
#include "my.h"

stat_t *create_stat(int lev, int health_point, int attck_point, float atk_speed)
{
    stat_t *stat = malloc(sizeof(*stat));

    CHECK_NULL(stat);
    stat->level = lev;
    stat->attack_speed = atk_speed;
    stat->attck_point = attck_point;
    stat->health_point = health_point;
    stat->move_speed = 0;
    stat->slowing = 1;
    stat->curr_waiting = 0;
    stat->life_lbl = create_label("./assets/fonts/GROBOLD.ttf",
    23, m_itos(stat->health_point), sfRed);
    return stat;
}

void set_stat_speed(stat_t *stat, float move_speed)
{
    stat->move_speed = move_speed;
}

void destroy_stat(stat_t *stat)
{
    label_destroy(stat->life_lbl);
    free(stat);
}