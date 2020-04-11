/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** tower_locations.c
*/

#include "game.h"
#include "game_object.h"
#include "map.h"
#include "shop.h"

tower_location *create_location(int x, int y)
{
    sfVector2f pos = {(float) x * SIZE_TILE, (float) y * SIZE_TILE};
    tower_location *loc = malloc(sizeof(*loc));

    CHECK_NULL(loc);
    loc->pos = pos;
    loc->tower = NULL;
    return loc;
}

tower_location *get_location(map_t *map, sfVector2i mouse_pos)
{
    sfIntRect tmp = {0, 0, SIZE_TILE, SIZE_TILE};
    int i = 0;

    for (i = 0; map->t_locations[i] != NULL; i++) {
        tmp.left = (int) map->t_locations[i]->pos.x;
        tmp.top = (int) map->t_locations[i]->pos.y;
        if (sfIntRect_contains(&tmp, mouse_pos.x, mouse_pos.y)) {
            return map->t_locations[i];
        }
    }
    return NULL;
}

void active_location(shop_t *shop, map_t *map, game_sys_t *sys)
{
    tower_location *loc = get_location(map, sys->mouse_pos);

    if (!loc)
        return;
    if (loc->tower) {
            shop->is_displayed = false;
            return;
    } else if (!loc->tower && shop->is_displayed) {
        if ((int) map->selected_location.x == (int) loc->pos.x &&
            (int) map->selected_location.y == (int) loc->pos.y) {
            shop->is_displayed = false;
            return;
        }
    }
    shop->is_displayed = true;
    map->selected_location.x = loc->pos.x;
    map->selected_location.y = loc->pos.y;
}

tower_location **find_locations(char **map, char c)
{
    int nb_locations = count_char(map, T_LOC);
    tower_location **locations = NULL;
    int i = 0, x = 0, y = 0;

    if (!nb_locations)
        return NULL;
    locations = malloc(sizeof(tower_location *) * (nb_locations + 1));
    CHECK_NULL(locations);
    for (y = 0; map[y] != NULL; y++) {
        for (x = 0; x < X_BLCK; x++) {
            if (map[y][x] == c)
                locations[i++] = create_location(x, y);
        }
    }
    locations[i] = NULL;
    return locations;
}

void locations_destroy(tower_location *loc)
{
    free(loc);
}
