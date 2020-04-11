/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** struct_victory.c
*/

#include "game.h"
#include "scene.h"
#include "victory.h"

victory_t *create_victory(void)
{
    victory_t *victory = malloc(sizeof(*(victory)));

    victory->btns = NULL;
    victory->cadre = create_image(FRAME_VICTORY, NULL);
    create_victory_btn(victory);
    sfSprite_setPosition(victory->cadre->sprite, (sfVector2f) { 300.0, 100.0});
    return victory;
}

void destroy_victory(victory_t *victory)
{
    image_destroy(victory->cadre);
    free(victory);
}
