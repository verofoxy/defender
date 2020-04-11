/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** enemy..c
*/

#include <pathfiling.h>
#include "game.h"
#include "game_object.h"
#include "pause.h"
#include "level.h"

void apply_enemy_attck(level_t *lvl, tower_location *end_loc, sfIntRect en_tile,
game_object *en)
{
    if (sfIntRect_contains(&en_tile, (int) end_loc->pos.x,
    (int) end_loc->pos.y)) {
        lvl->life -= en->entity->stat->attck_point;
        if (lvl->life < 0)
            lvl->life = 0;
        list_element_destroy(&lvl->gen->enemies, en, object_destroy);
    }
}

void check_enemies_reached_endpoint(level_t *lvl)
{
    int i = 0;
    tower_location **end_loc = find_locations(lvl->map->str_map, END_EN);
    list_t *tmp = lvl->gen->enemies;
    sfVector2i pos_enemy;
    sfIntRect en_tile = {.width = SIZE_TILE, .height = SIZE_TILE};

    while (tmp) {
        pos_enemy = enemy_in_which_tile(tmp->element);
        en_tile.left = pos_enemy.x * SIZE_TILE - 1;
        en_tile.top = pos_enemy.y * SIZE_TILE - 1;
        apply_enemy_attck(lvl, end_loc[i], en_tile, tmp->element);
        tmp = tmp->next;
    }
    for (i = 0; end_loc[i]; i++)
        locations_destroy(end_loc[i]);
    free(end_loc);
}

void change_delay_wave(wave_generator *gen)
{
    gen->delta_time = ((float)(rand() % 4001) / (float) 1000) + 1.5;
    gen->started = true;
}

