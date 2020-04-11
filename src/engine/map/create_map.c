/*
** EPITECH PROJECT, 2020
** tgyhujk
** File description:
** fghjklm
*/

#include "my.h"
#include "game.h"
#include "game_object.h"
#include "image.h"
#include "map.h"

int count_line(char *buffer)
{
    int i = 0, j = 0;

    for (i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n')
            j++;
    }
    return j;
}

int count_cols(char *buffer)
{
    int i = 0;

    for (i = 0; buffer[i] != '\n'; i++);
    return (i);
}

char **create_table_chartwo(char *buffer, int size_line, int size_colonne)
{
    int i = 0, j = 0, n = 0;
    char **double_str = NULL;
    char *tmp = NULL;

    double_str = malloc(sizeof(char *) * (size_line + 1));
    for (i = 0; i != size_line; i++) {
        tmp = malloc(sizeof(char) * size_colonne + 1);
        m_memset(tmp, 0, size_colonne + 1);
        for (n = 0; buffer[j] != '\n'; n++) {
            tmp[n] = (char) get_index_tiles(buffer[j]);
            j++;
        }
        double_str[i] = tmp;
        j++;
    }
    double_str[i] = NULL;
    return (double_str);
}

char **open_read_file(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    int size_line = 0, size_cols = 0;
    char buffer[MAP_CHUNK + 1];

    m_memset(buffer, 0, MAP_CHUNK + 1);
    read(fd, buffer, MAP_CHUNK + 1);
    size_line = count_line(buffer);
    size_cols = count_cols(buffer);
    return create_table_chartwo(buffer, size_line, size_cols);
}

map_t *load_map(char const *filepath)
{
    map_t *map = malloc(sizeof(map_t));

    if (map == NULL)
        return NULL;
    map->tiles = cut_tilemap();
    map->str_map = open_read_file(filepath);
    map->t_locations = find_locations(map->str_map, T_LOC);
    map->selected_location = (sfVector2f) {(float) -1, (float) -1};
    if (!map->t_locations)
        return map;
    return map;
}