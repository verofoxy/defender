/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** wave.h
*/

#ifndef MUL_MY_DEFENDER_2019_WAVE_H
#define MUL_MY_DEFENDER_2019_WAVE_H

typedef struct {
    list_t *enemies;
    char dataset[101];
    int level;
    int nb_per_wave;
    float curr_time;
    float total_time;
    float delta_time;
    bool started;
    sfVector2f spawner_pos;
} wave_generator;

wave_generator *create_generator(sfVector2f spawner);
void destroy_generator(wave_generator *gen);
void create_wave(wave_generator *gen, sfClock *clock);
void setup_generator(wave_generator *gen, int level);
void add_noise(sfVector2f *spawn);

game_object *get_enemy_from_dataset(wave_generator *gen);
void move_wave(list_t *enemies, sfClock *clock);
void draw_enemy_wave(list_t *enemies, game_sys_t *sys);
bool has_survived(list_t *enemies);
void change_delay_wave(wave_generator *gen);

#endif