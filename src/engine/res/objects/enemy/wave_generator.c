/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** wave_generator.c
*/

#include "game.h"
#include "game_object.h"
#include "animation.h"
#include "wave.h"
#include "my.h"

void create_dataset(wave_generator *gen, int level1, int level2, int level3)
{
    int i = 0;
    int total = 0;
    char en_level1[3] = "SF";
    char en_level2[3] = "TG";
    char en_level3 = 'M';

    for (i = 0; i < level1 && total != 100; i++, total++)
        gen->dataset[total] = en_level1[rand() % 2];
    for (i = 0; i < level2 && total != 100; i++, total++)
        gen->dataset[total] = en_level2[rand() % 2];
    for (i = 0; i < level3 && total != 100; i++, total++)
        gen->dataset[total] = en_level3;
}

void setup_generator(wave_generator *gen, int level)
{
    int level1 = 0, level2 = 0, level3 = 0;

    switch (level) {
        case 1:
            gen->total_time = 15;
            level1 = 100;
            break;
        case 2:
            gen->total_time = 23;
            level1 = 50, level2 = 50;
            break;
        case 3:
            gen->total_time = 30;
            level1 = 30, level2 = 50, level3 = 20;
            break;
        default:
            m_printf("Couldn't create generator\n");
            return;
    }
    create_dataset(gen, level1, level2, level3);
}

wave_generator *create_generator(sfVector2f spawner)
{
    wave_generator *generator = malloc(sizeof(*generator));

    CHECK_NULL(generator);
    generator->curr_time = 0;
    generator->nb_per_wave = 1;
    generator->delta_time = 3;
    generator->spawner_pos = spawner;
    generator->enemies = NULL;
    generator->started = false;
    m_memset(generator->dataset, 0, 101);
    return generator;
}

void create_wave(wave_generator *gen, sfClock *clock)
{
    static int last_mod = 1;
    int nb_en_created = 0;
    game_object *new_enemy = NULL;

    if (gen->curr_time >= gen->total_time)
        return;
    gen->curr_time += sfTime_asSeconds(sfClock_getElapsedTime(clock));
    if ((int) gen->curr_time % (int) round(gen->delta_time) != 0) {
        last_mod = (int) gen->curr_time % (int) roundl(gen->delta_time);
        return;
    }
    if (last_mod == ((int) gen->curr_time % (int) roundl(gen->delta_time)))
        return;
    last_mod = (int) gen->curr_time % (int) roundl(gen->delta_time);
    for (nb_en_created = 0; nb_en_created < gen->nb_per_wave; nb_en_created++) {
        new_enemy = get_enemy_from_dataset(gen);
        list_push(&gen->enemies, new_enemy, NULL);
        change_move(new_enemy, "right");
    }
    change_delay_wave(gen);
}

void destroy_generator(wave_generator *gen)
{
    m_memset(gen->dataset, 0, 101);
    free(gen);
}