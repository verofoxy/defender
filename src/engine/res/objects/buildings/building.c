/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** building.c
*/

#include "game.h"
#include "game_object.h"
#include "animation.h"
#include "my.h"
#include "level.h"

void attack_enemy(game_object *tower)
{
    game_object *en = tower->entity->on_focus;

    if (!en)
        return;
    en->entity->stat->health_point = en->entity->stat->health_point -
    tower->entity->stat->attck_point;
    change_text(en->entity->stat->life_lbl,
    en->entity->stat->health_point >= 0 ?
    m_itos(en->entity->stat->health_point) :
    0);
    change_animation(tower, "hit", "idle");
}

void focus_new_enemy(list_t *enemies, game_object *tower)
{
    if (tower->entity->on_focus) {
        if (is_in_range(tower->entity->on_focus, tower)) {
            tower->entity->on_focus->has_been_focused = true;
            tower->entity->on_focus->is_focused = true;
            return;
        } else {
            if (!tower->entity->on_focus->has_been_focused)
                tower->entity->on_focus->is_focused = false;
            tower->entity->on_focus = NULL;
        }
    }
    while (enemies) {
        if (is_in_range(enemies->element, tower)) {
            tower->entity->on_focus = enemies->element;
            tower->entity->on_focus->has_been_focused = true;
            tower->entity->on_focus->is_focused = true;
            break;
        } else {
            if (!((game_object *) enemies->element)->has_been_focused)
                ((game_object *) enemies->element)->is_focused = false;
        }
        enemies = enemies->next;
    }
}

void check_death(list_t **enemies, int *coins, game_object *tower)
{
    if (tower->entity->on_focus == NULL) {
        return;
    }
    if (tower->entity->on_focus->entity->stat->health_point > 0)
        return;
    if (tower->entity->on_focus->type_obj == monster)
        *coins += 300;
    else
        *coins += 100;
    list_element_destroy(enemies, tower->entity->on_focus, object_destroy);
    tower->entity->on_focus = NULL;
}

void draw_towers(list_t *towers, game_sys_t *sys)
{
    while (towers) {
        draw_object(towers->element, sys);
        towers = towers->next;
    }
}

void handle_tower_attacks(level_t *level, list_t *towers, game_sys_t *sys,
sfClock *clock)
{
    while (towers) {
        tower_attack(level, towers->element, sys, clock);
        towers = towers->next;
    }
}