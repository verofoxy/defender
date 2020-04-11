/*
** EPITECH PROJECT, 2019
** Runner
** File description:
** image.c
*/

#include <stdlib.h>
#include "game.h"
#include "game_object.h"
#include "image.h"
#include "map.h"

image_t *create_image(char const *filepath, sfIntRect *area)
{
    image_t *n_img = malloc(sizeof(*n_img));
    sfTexture *txt = sfTexture_createFromFile(filepath, area);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, txt, sfTrue);
    n_img->sprite = sprite;
    n_img->txt = txt;
    return n_img;
}

void set_image(image_t *img, char const *filepath, sfIntRect *area)
{
    sfTexture_destroy(img->txt);
    img->txt = sfTexture_createFromFile(filepath, area);
    sfSprite_setTexture(img->sprite, img->txt, sfTrue);
}

void image_destroy(image_t *img)
{
    sfSprite_destroy(img->sprite);
    sfTexture_destroy(img->txt);
    free(img);
}

void transform_to_image(map_t *map, sfRenderWindow *window)
{
    int line = 0, col = 0;
    float x = 0.0, y = 0.0;
    char **str_map = map->str_map;
    image_t *tmp = NULL;

    for (line = 0; str_map[line] != NULL; line++) {
        for (col = 0, x = 0.0; x < W_WIN; x += 64, col++) {
            tmp = get_tile(map, str_map[line][col]);
            if (!tmp)
                continue;
            sfSprite_setPosition(tmp->sprite, (sfVector2f) {x, y});
            sfRenderWindow_drawSprite(window, tmp->sprite, NULL);
        }
        y += SIZE_TILE;
    }
}