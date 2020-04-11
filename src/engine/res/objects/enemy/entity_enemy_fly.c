/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** entity_enemy_fly.c
*/

#include "game.h"
#include "game_object.h"
#include "animation.h"

entity_t *create_fly1(sfVector2f pos)
{
    entity_t *ent = malloc(sizeof(*ent));
    sfVector2f pos_lbl;

    CHECK_NULL(ent);
    ent->spritesheet = create_image(FLY1_PATH, NULL);
    sfSprite_setPosition(ent->spritesheet->sprite, pos);
    sfSprite_setTextureRect(ent->spritesheet->sprite, FLY1_FRAMES[0]);
    ent->stat = create_stat(1, 10, 1, 0);
    ent->is_up = false;
    ent->curr_time_top_offset = 0;
    set_stat_speed(ent->stat, 100);
    pos_lbl.x = pos.x + 20;
    pos_lbl.y = pos.y - 40;
    sfText_setPosition(ent->stat->life_lbl->txt, pos_lbl);
    return ent;
}

game_object *create_fly1_object(sfVector2f pos)
{
    animation_t *idle = create_animation(1, FLY1_FRAMES, 0.1f, true);
    animation_t *walk = create_animation
    (NB_FRAMES_FLY1, FLY1_FRAMES, 1.0f, true);
    entity_t *ent = create_fly1(pos);
    hitbox *box = create_hitbox(40,
    sfSprite_getPosition(ent->spritesheet->sprite),
    sfSprite_getTextureRect(ent->spritesheet->sprite),
    fly);
    game_object *obj = create_object(fly, ent, box);

    CHECK_NULL(obj);
    obj->hitbox->is_displayed = false;
    add_animation(obj, walk, "walk");
    add_animation(obj, idle, "idle");
    add_move(obj, move_right, "right");
    add_move(obj, move_left, "left");
    add_move(obj, move_top, "top");
    add_move(obj, move_bottom, "down");
    return obj;
}

entity_t *create_fly2(sfVector2f pos)
{
    entity_t *ent = malloc(sizeof(*ent));
    sfVector2f pos_lbl;

    CHECK_NULL(ent);
    ent->spritesheet = create_image(FLY2_PATH, NULL);
    sfSprite_setPosition(ent->spritesheet->sprite, pos);
    sfSprite_setTextureRect(ent->spritesheet->sprite, FLY2_FRAMES[0]);
    ent->stat = create_stat(2, 12, 4, 0);
    ent->is_up = false;
    ent->curr_time_top_offset = 0;
    pos_lbl.x = pos.x + 20;
    pos_lbl.y = pos.y - 40;
    sfText_setPosition(ent->stat->life_lbl->txt, pos_lbl);
    set_stat_speed(ent->stat, 140);
    return ent;
}

game_object *create_fly2_object(sfVector2f pos)
{
    animation_t *idle = create_animation(1, FLY2_FRAMES, 0.1f, true);
    animation_t *walk = create_animation(
    NB_FRAMES_FLY2, FLY2_FRAMES, 1.0f, true);
    entity_t *ent = create_fly2(pos);
    hitbox *box = create_hitbox(40,
    sfSprite_getPosition(ent->spritesheet->sprite),
    sfSprite_getTextureRect(ent->spritesheet->sprite),
    fly);
    game_object *obj = create_object(fly, ent, box);

    CHECK_NULL(obj);
    obj->hitbox->is_displayed = false;
    add_animation(obj, walk, "walk");
    add_animation(obj, idle, "idle");
    add_move(obj, move_right, "right");
    add_move(obj, move_left, "left");
    add_move(obj, move_top, "top");
    add_move(obj, move_bottom, "down");
    return obj;
}