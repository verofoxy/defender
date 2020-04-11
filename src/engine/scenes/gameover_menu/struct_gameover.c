/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** struct_gameover.c
*/

#include "game.h"
#include "game_object.h"
#include "scene.h"
#include "gameover.h"
#include "map.h"

gameover_t *create_gameover(void)
{
    gameover_t *gameover = malloc(sizeof(*(gameover)));

    gameover->btns = NULL;
    gameover->cadre = create_image("./assets/images/notice/gameover.png",
    NULL);
    create_gameover_btn(gameover);
    sfSprite_setPosition(gameover->cadre->sprite,
    (sfVector2f) { 300.0, 100.0});
    return gameover;
}

void destroy_gameover(gameover_t *gameover)
{
    image_destroy(gameover->cadre);
    free(gameover);
}
