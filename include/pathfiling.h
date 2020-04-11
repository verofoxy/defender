/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** pathfiling.h
*/


#ifndef MUL_MY_DEFENDER_2019_PATHFILING_H
#define MUL_MY_DEFENDER_2019_PATHFILING_H

#include "system.h"
#include "image.h"
#include "res.h"
#include "list.h"
#include "my.h"
#include "game_object.h"
#include "map.h"
#include "window.h"

void which_zone(map_t *map, game_object *obj, sfClock *clock);
sfVector2f where_is_the_char(char **map, char c);
sfVector2i where_is_brown(char **map, int line, int cols, sfClock *clock);
int is_brown (char c);
int zone_valid(map_t *map, game_object *obj, sfVector2i s_point, sfClock *clock);
int zone_invalid(game_object *obj);
void apply_findpath(map_t *map, list_t *enemies, sfClock *clock);
sfVector2i enemy_in_which_tile(game_object *obj);
#endif
