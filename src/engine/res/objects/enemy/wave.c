/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** wave.c
*/

#include "game.h"
#include "game_object.h"
#include "wave.h"
#include "animation.h"
#include "level.h"

void draw_enemy_wave(list_t *enemies, game_sys_t *sys)
{
    while (enemies) {
        draw_object(enemies->element, sys);
        enemies = enemies->next;
    }
}

void reset_enemy_wave_focus(list_t *enemies)
{
    while (enemies) {
        ((game_object *) enemies->element)->has_been_focused = false;
        ((game_object *) enemies->element)->is_focused = false;
        enemies = enemies->next;
    }
}

void add_noise(sfVector2f *spawn)
{
    int i = rand() % 2;

    if (i == 0) {
        spawn->y -= (float) (rand() % 10);
        spawn->x += (float) (rand() % 10);
    } else {
        spawn->y += (float) (rand() % 10);
        spawn->x += (float) (rand() % 10);
    }
}

game_object *get_enemy_from_dataset(wave_generator *gen)
{
    game_object *obj = NULL;
    char en_selected = gen->dataset[rand() % 100];
    sfVector2f spawn = gen->spawner_pos;

    add_noise(&spawn);
    if (en_selected == 'S')
        obj = create_shrimp1_object(spawn);
    if (en_selected == 'T')
        obj = create_shrimp2_object(spawn);
    if (en_selected == 'F')
        obj = create_fly1_object(spawn);
    if (en_selected == 'G')
        obj = create_fly2_object(spawn);
    if (en_selected == 'M')
        obj = create_shrimp2_object(spawn);
    return obj;
}

bool has_survived(list_t *enemies)
{
    if (!enemies)
        return true;
    return false;
}