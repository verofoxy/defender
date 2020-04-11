/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** level.c
*/

#include <pathfiling.h>
#include "game.h"
#include "game_object.h"
#include "pause.h"
#include "level.h"

void level_event(level_t *lvl, sfClock *clock, game_sys_t *sys)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(sys->window, &event)) {
        if (event.type == sfEvtClosed) {
            exit_game(sys);
            break;
        }
        if (event.type == sfEvtMouseButtonPressed) {
            check_shop_btns_pressed(&lvl->towers, lvl->shop, lvl->map, sys);
            active_location(lvl->shop, lvl->map, sys);
        }
        if (event.type == sfEvtKeyPressed) {
            if (event.key.code == sfKeyEscape)
                pause_scene(sys, clock, LEVEL1_SCENE, &lvl->restart);
        }
    }
}

level_t *create_level(char const *filepath_map, int start_coins, int nb_wave)
{
    level_t *lvl = malloc(sizeof(*lvl));
    sfVector2f starting_point;
    CHECK_NULL(lvl);
    lvl->score = 0;
    lvl->map = load_map(filepath_map);
    lvl->shop = create_shop(start_coins);
    starting_point = where_is_the_char(lvl->map->str_map, 48);
    starting_point.x *= SIZE_TILE;
    starting_point.y *= SIZE_TILE;
    lvl->gen = create_generator(starting_point);
    lvl->restart = false;
    lvl->towers = NULL;
    lvl->nb_wave_remaining = nb_wave;
    lvl->num_wave = nb_wave;
    lvl->life = 20;
    lvl->life_lbl = create_label(GROBOLD_PATH, 34, m_itos(lvl->life), sfWhite);
    sfText_setPosition(lvl->life_lbl->txt, (sfVector2f) {360, 40});
    lvl->life_img = create_image(LIFE_IMG, NULL);
    sfSprite_setPosition(lvl->life_img->sprite, (sfVector2f) {300, 40});
    return lvl;
}

void draw_level(level_t *lvl, game_sys_t *sys)
{
    transform_to_image(lvl->map, sys->window);
    draw_enemy_wave(lvl->gen->enemies, sys);
    draw_towers(lvl->towers, sys);
    draw_shop(sys, lvl->shop);
    sfRenderWindow_drawSprite(sys->window, lvl->life_img->sprite, NULL);
    change_text(lvl->life_lbl, m_itos(lvl->life));
    draw_lbl(lvl->life_lbl, sys);
}

void destroy_level(level_t *lvl)
{
    destroy_shop(lvl->shop);
    destroy_generator(lvl->gen);
    label_destroy(lvl->life_lbl);
    list_destroy(&lvl->towers, object_destroy);
    image_destroy(lvl->life_img);
    free(lvl);
}