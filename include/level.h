/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** level.h
*/

#ifndef MUL_MY_DEFENDER_2019_LEVEL_H
#define MUL_MY_DEFENDER_2019_LEVEL_H

#include "wave.h"
#include "list.h"
#include "map.h"

typedef struct level {
    int life;
    label_t *life_lbl;
    image_t *life_img;
    wave_generator *gen;
    list_t *towers;
    map_t *map;
    shop_t *shop;
    int num_wave;
    int nb_wave_remaining;
    int score;
    bool restart;
} level_t;

level_t *create_level(char const *filepath_map, int start_coins, int nb_wave);
void destroy_level(level_t *lvl);
void draw_level(level_t *lvl, game_sys_t *sys);
void level_event(level_t *lvl, sfClock *clock, game_sys_t *sys);
void apply_enemy_attck(level_t *lvl, tower_location *end_loc, sfIntRect en_tile,
game_object *en);
void check_enemies_reached_endpoint(level_t *lvl);
void tower_attack(level_t *lvl, game_object *tower,
game_sys_t *sys, sfClock *clock);
void handle_tower_attacks(level_t *lvl, list_t *towers, game_sys_t *sys,
sfClock *clock);
#endif