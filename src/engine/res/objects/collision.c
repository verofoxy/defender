/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** collision.c
*/

#include <math.h>
#include "game.h"
#include "game_object.h"
#include "animation.h"
#include "level.h"
#include "sound.h"

double dist(sfVector2f a, sfVector2f b)
{
    return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

bool is_in_range(game_object *en, game_object *tower)
{
    if (!en)
        return false;
    double distance_center = 0;
    sfVector2f range = sfCircleShape_getPosition(tower->hitbox->rendering);
    sfVector2f box = sfCircleShape_getPosition(en->hitbox->rendering);
    sfVector2f centerT = {range.x + tower->hitbox->radius,
    range.y + tower->hitbox->radius};
    sfVector2f centerB = {box.x + en->hitbox->radius,
    box.y + en->hitbox->radius};

    distance_center = dist(centerB, centerT);
    return distance_center < tower->hitbox->radius ||
    ((range.x <= box.x && box.x <= range.x + 2 * tower->hitbox->radius) &&
    (box.y >= range.y && range.y + 2 * tower->hitbox->radius >= box.y));
}

void play_sfx(game_sys_t *sys, game_object *tower)
{
    if (tower->type_obj == slow_tower)
        play_sound(list_get_from_tag(sys->osts, "freeze"));
    if (tower->type_obj == canon)
        play_sound(list_get_from_tag(sys->osts, "canon"));
    if (tower->type_obj == booster)
        play_sound(list_get_from_tag(sys->osts, "boost"));
}

void tower_attack(level_t *lvl, game_object *tower,
game_sys_t *sys, sfClock *clock)
{
    float past_time = sfTime_asSeconds(sfClock_getElapsedTime(clock));

    if (tower->type_obj != slow_tower) {
        focus_new_enemy(lvl->gen->enemies, tower);
        if (tower->entity->stat->curr_waiting <
            1 / tower->entity->stat->attack_speed) {
            tower->entity->stat->curr_waiting += past_time;
            return;
        } else {
            if (!tower->entity->on_focus)
                return;
            tower->entity->stat->curr_waiting = 0;
        }
        attack_enemy(tower);
        check_death(&lvl->gen->enemies, &lvl->shop->nbr_coins, tower);
    } else
        apply_slow_tower_effect(lvl->gen->enemies, tower);
    play_sfx(sys, tower);

}
