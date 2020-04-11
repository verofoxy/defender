/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** find.c
*/

#include "game_object.h"
#include "map.h"
#include "scene.h"
#include "pathfiling.h"
#include "stdbool.h"

int is_brown(char c)
{
    if (c == 22 || c == 24 || c == 48 || c == 21)
        return 1;
    else
        return 0;
}

sfVector2f where_is_the_char(char **map, char c)
{
    int cols = 0, line = 0;
    sfVector2f here = {(float) line, (float) cols};

    while (map[line] != NULL) {
        cols = 0;
        while (cols != 30) {
            if (map[line][cols] == c) {
                here.y = (float) line;
                here.x = (float) cols;
                return here;
            }
            cols++;
        }
        line++;
    }
    return here;
}

sfVector2i enemy_in_which_tile(game_object *obj)
{
    sfVector2i send = {0, 0};
    sfIntRect curr_tile = {0, 0, SIZE_TILE + 1, SIZE_TILE + 1};
    sfVector2f here =  sfSprite_getPosition (obj->entity->spritesheet->sprite);
    int line = 0, cols = 0;

    while (curr_tile.top < H_WIN) {
        curr_tile.left = 0;
        cols = 0;
        for (;curr_tile.left < W_WIN; curr_tile.left += 64, cols++) {
            if (sfIntRect_contains(&curr_tile, (int) here.x,
            (int) here.y) == true) {
                send.x = cols;
                send.y = line;
                return send;
            }
        }
        curr_tile.top += 64;
        line++;
    }
    return send;
}
