/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** entity_booster.c
*/

#include "game.h"
#include "game_object.h"
#include "animation.h"

entity_t *create_booster(sfVector2f pos)
{
    entity_t *ent = malloc(sizeof(*ent));

    CHECK_NULL(ent);
    pos.y -= (float) BOOSTER_FRAMES[0].height - SIZE_TILE;
    pos.x -= (float) BOOSTER_FRAMES[0].width / 2 - (float) SIZE_TILE / 2;
    ent->spritesheet = create_image(BOOSTER_PATH, NULL);
    sfSprite_setTextureRect(ent->spritesheet->sprite, BOOSTER_FRAMES[0]);
    sfSprite_setPosition(ent->spritesheet->sprite, pos);
    ent->stat = create_stat(1, 10, 4, 1.0f);
    ent->on_focus = NULL;
    return ent;
}

game_object *create_booster_object(sfVector2f pos)
{
    animation_t *idle = create_animation(1, BOOSTER_FRAMES, 0.4f, true);
    animation_t *hit = create_animation(NB_FRAMES_BOOSTER,
    BOOSTER_FRAMES, 0.2f, false);
    entity_t *booster_ent = create_booster(pos);
    hitbox *box = create_hitbox(200,
    sfSprite_getPosition(booster_ent->spritesheet->sprite),
    sfSprite_getTextureRect(booster_ent->spritesheet->sprite),
    booster);
    game_object *canon_obj = create_object(booster, booster_ent, box);

    CHECK_NULL(canon_obj);
    add_animation(canon_obj, idle, "idle");
    add_animation(canon_obj, hit, "hit");
    return canon_obj;
}
