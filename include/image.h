/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** image.h
*/

#ifndef MUL_MY_DEFENDER_2019_IMAGE_H
#define MUL_MY_DEFENDER_2019_IMAGE_H

#include <SFML/Graphics.h>

typedef struct image {
    sfTexture *txt;
    sfSprite *sprite;
} image_t;

image_t *create_image(char const *filepath, sfIntRect *area);
void set_image(image_t *img, char const *filepath, sfIntRect *area);
void image_destroy(image_t *img);

#endif