/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** hitbox.c
*/

#include "game.h"
#include "res.h"
#include "game_object.h"

void hitbox_tower(hitbox *box, sfVector2f pos, sfIntRect area, float radius)
{
    sfVector2f true_pos = {pos.x + area.width / 2, pos.y + area.height};

    true_pos.x -= radius;
    true_pos.y -= radius + SIZE_TILE / 2;
    box->is_displayed = true;
    sfCircleShape_setRadius(box->rendering, radius);
    sfCircleShape_setPosition(box->rendering, true_pos);
    sfCircleShape_setFillColor(box->rendering,
    sfColor_fromRGBA(18, 130, 179, 100));
    sfCircleShape_setOutlineThickness(box->rendering, 4);
    sfCircleShape_setOutlineColor(box->rendering,
    sfColor_fromRGB(18, 130, 179));
}

void hitbox_monster(hitbox *box, sfVector2f pos, sfIntRect area, float radius)
{
    sfVector2f true_pos = {pos.x + (float) area.width / 2,
    pos.y + (float) area.height / 2};

    true_pos.x -= radius;
    true_pos.y -= radius;
    box->is_displayed = false;
    sfCircleShape_setRadius(box->rendering, radius);
    sfCircleShape_setPosition(box->rendering, true_pos);
    sfCircleShape_setFillColor(box->rendering,
    sfColor_fromRGBA(212, 88, 12, 100));
    sfCircleShape_setOutlineThickness(box->rendering, 4);
    sfCircleShape_setOutlineColor(box->rendering,
    sfColor_fromRGB(255, 8, 12));
}

hitbox *create_hitbox(float radius, sfVector2f pos,
sfIntRect area, obj_type type)
{
    hitbox *box = malloc(sizeof(*box));

    CHECK_NULL(box);
    box->rendering = sfCircleShape_create();
    box->radius = radius;
    if (type == slow_tower || type == canon || type == archer
    || type == booster)
        hitbox_tower(box, pos, area, radius);
    else
        hitbox_monster(box, pos, area, radius);
    return box;
}

void hitbox_destroy(hitbox *box)
{
    sfCircleShape_destroy(box->rendering);
    free(box);
}
