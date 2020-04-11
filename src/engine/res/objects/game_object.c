/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** game_object.c
*/

#include "game.h"
#include "image.h"
#include "game_object.h"
#include "animation.h"

game_object *create_object(obj_type type, entity_t *object, hitbox *box)
{
    game_object *obj = malloc(sizeof(*obj));

    CHECK_NULL(obj);
    obj->type_obj = type;
    obj->animations = NULL;
    obj->sounds = NULL;
    obj->moves = NULL;
    obj->curr_anim = NULL;
    obj->is_focused = false;
    obj->curr_sound = NULL;
    obj->curr_move = NULL;
    obj->has_been_focused = false;
    obj->hitbox = box;
    obj->entity = object;
    return obj;
}

void move_object(game_object *obj, sfClock *clock)
{
    play_animation(obj, clock);
    move_enemy(obj, clock);
}

void draw_object(game_object *obj, game_sys_t *sys)
{
    if (!obj)
        return;
    if (obj->type_obj == shrimp || obj->type_obj == fly)
    sfRenderWindow_drawText(sys->window,
    obj->entity->stat->life_lbl->txt, NULL);
    if (obj->is_focused || obj->hitbox->is_displayed)
    sfRenderWindow_drawCircleShape(sys->window, obj->hitbox->rendering, NULL);
    sfRenderWindow_drawSprite(
    sys->window,
    obj->entity->spritesheet->sprite,
    NULL);
}

void object_destroy(game_object *obj)
{
    list_destroy(&obj->animations, animation_destroy);
    entity_destroy(obj->entity);
    hitbox_destroy(obj->hitbox);
    free(obj);
}
