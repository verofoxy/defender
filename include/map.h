/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** map.h
*/

#ifndef MUL_MY_DEFENDER_2019_MAP_H
#define MUL_MY_DEFENDER_2019_MAP_H

#include <unistd.h>
#include <fcntl.h>
#include "image.h"

#define MAP_CHUNK   1024
#define X_BLCK      30
#define Y_BLCK      17
#define T_LOC       5

typedef struct map {
    char **str_map;
    list_t *tiles;
    struct tower_location **t_locations;
    sfVector2f selected_location;
} map_t;

typedef struct tower_location {
  sfVector2f pos;
  game_object *tower;
} tower_location;

int count_line(char *buffer);
int count_cols(char *buffer);
int count_char(char **map, char c);
map_t *load_map(char const *filepath);
char **create_table_chartwo(char *buffer, int size_line, int size_colonne);
int count_line(char *buffer);
void transform_to_image(map_t *map, sfRenderWindow *window);
image_t *get_tile(map_t *map, int index);
tower_location **find_locations(char **str_map, char c);
void locations_destroy(tower_location *loc);
int get_index_tiles(char c);

#endif
