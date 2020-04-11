/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** scene1.c
*/

#include "game.h"
#include "game_object.h"
#include "window.h"
#include "system.h"
#include "image.h"
#include "map.h"
#include "wave.h"
#include "pathfiling.h"
#include "shop.h"
#include "pause.h"
#include "level.h"
#include "sound.h"

void check_victory(level_t *lvl)
{
    int nbr_emy = lvl->nb_wave_remaining;

    if (lvl->gen->started == false)
        return;
    if (nbr_emy > 0 && has_survived(lvl->gen->enemies)) {
        lvl->gen->curr_time = 0;
        lvl->nb_wave_remaining--;
    }
}

void apply_actions(level_t *lvl, game_sys_t *sys, sfClock *clock)
{
    apply_findpath(lvl->map, lvl->gen->enemies, clock);
    create_wave(lvl->gen, clock);
    reset_enemy_wave_focus(lvl->gen->enemies);
    move_wave(lvl->gen->enemies, clock);
    handle_tower_attacks(lvl, lvl->towers, sys, clock);
    animate_buildings(lvl->towers, clock);
    check_enemies_reached_endpoint(lvl);
    check_victory(lvl);
}

void stop_level(level_t *lvl, sfClock *clock, game_sys_t *sys)
{
    sfClock_destroy(clock);
    destroy_level(lvl);
    stop_sound(list_get_from_tag(sys->osts, "fight"));
}

void check_survived(level_t *lvl, game_sys_t *sys)
{
    if (lvl->nb_wave_remaining > 0 && lvl->life <= 0)
        change_scene(sys, GO_SCENE);
    if (lvl->nb_wave_remaining == 0 && lvl->life > 0)
        change_scene(sys, VICTORY_SCENE);
}

void scene1(game_sys_t *sys)
{
    sfClock *clock = sfClock_create();
    level_t *lvl = create_level("./map_level2.txt", 1200, 1);
    play_sound(list_get_from_tag(sys->osts, "fight"));
    setup_generator(lvl->gen, 2);
    while (is_open_window(sys->window) && sys->actual_scene == LEVEL1_SCENE) {
        sys->mouse_pos = sfMouse_getPositionRenderWindow(sys->window);
        if (lvl->shop->is_displayed)
            set_status_shop(lvl->shop->btns, lvl->shop->nbr_coins, sys);
        level_event(lvl, clock, sys);
        if (lvl->restart)
            return;
        sfRenderWindow_clear(sys->window, sfBlack);
        check_survived(lvl, sys);
        draw_level(lvl, sys);
        sfRenderWindow_display(sys->window);
        apply_actions(lvl, sys, clock);
        sfClock_restart(clock);
    }
    stop_level(lvl, clock, sys);
}
