/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** tilemap_cutter.c
*/

#include "game.h"
#include "game_object.h"
#include "image.h"
#include "map.h"

list_t *cut_tilemap(void)
{
    sfIntRect tmp_rect = {0, 0, SIZE_TILE, SIZE_TILE};
    list_t *tiles = NULL;
    int x = 0, y = 0;
    image_t *tmp = NULL;

    for (y = 0; y < HEIGHT_TILEMAP; y += SIZE_TILE) {
        for (x = 0; x < WIDTH_TILEMAP; x += SIZE_TILE) {
            tmp_rect.left = x;
            tmp_rect.top = y;
            tmp = create_image(TILEMAP_PATH, &tmp_rect);
            CHECK_NULL(tmp);
            list_push(&tiles, tmp, NULL);
        }
    }
    return list_reverse(tiles);
}

image_t *get_tile(map_t *map, int index)
{
    return list_get_from_index(map->tiles, index);
}

int count_char(char **map, char c)
{
    int count = 0;
    int x = 0, y = 0;

    for (y = 0; map[y] != NULL; y++) {
        for (x = 0; x < X_BLCK; x++) {
            count += (map[y][x] == c) ? 1 : 0;
        }
    }
    return count;
}

int get_index_tiles(char c)
{
    int i = 0;
    char const *indexes = "0123456789abcdefghijklmnopqrstuvwxyz"
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (i = 0; indexes[i] != '\0'; i++) {
        if (indexes[i] == c)
            return i;
    }
    return -1;
}
