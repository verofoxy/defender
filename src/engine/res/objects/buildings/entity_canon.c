/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** entity_canon.c
*/

#include "game.h"
#include "game_object.h"
#include "animation.h"

entity_t *create_canon(sfVector2f pos)
{
    entity_t *ent = malloc(sizeof(*ent));

    CHECK_NULL(ent);
    pos.y -= (float) CANON1_FRAMES[0].height - SIZE_TILE;
    pos.x -= (float) CANON1_FRAMES[0].width / 2 - (float) SIZE_TILE / 2;
    ent->spritesheet = create_image(CANON1_PATH, NULL);
    sfSprite_setTextureRect(ent->spritesheet->sprite, CANON1_FRAMES[0]);
    sfSprite_setPosition(ent->spritesheet->sprite, pos);
    ent->stat = create_stat(1, 10, 3, 1.7f);
    ent->on_focus = NULL;
    return ent;
}

game_object *create_canon_object(sfVector2f pos)
{
    animation_t *idle = create_animation(1, CANON1_FRAMES, 0.1f, true);
    animation_t *hit = create_animation
    (NB_FRAMES_CANON1, CANON1_FRAMES, 0.2f, false);
    entity_t *canon_ent = create_canon(pos);
    hitbox *box = create_hitbox(180,
    sfSprite_getPosition(canon_ent->spritesheet->sprite),
    sfSprite_getTextureRect(canon_ent->spritesheet->sprite),
    canon);
    game_object *canon_obj = create_object(canon, canon_ent, box);

    CHECK_NULL(canon_obj);
    add_animation(canon_obj, idle, "idle");
    add_animation(canon_obj, hit, "hit");
    return canon_obj;
}
