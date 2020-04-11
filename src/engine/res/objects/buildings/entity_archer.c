/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** entity_archer.c
*/

#include "game.h"
#include "game_object.h"
#include "animation.h"

entity_t *create_archer(sfVector2f pos)
{
    entity_t *ent = malloc(sizeof(*ent));

    CHECK_NULL(ent);
    pos.y -= (float) SLOW_TOWER1_FRAMES[0].height - SIZE_TILE;
    pos.x -= (float) SLOW_TOWER1_FRAMES[0].width / 2 - (float) SIZE_TILE / 2;
    ent->spritesheet = create_image(ARCHER1_PATH, NULL);
    sfSprite_setTextureRect(ent->spritesheet->sprite, ARCHER1_FRAMES[0]);
    sfSprite_setPosition(ent->spritesheet->sprite, pos);
    ent->stat = create_stat(1, 10, 5, 0.8f);
    ent->on_focus = NULL;
    return ent;
}

game_object *create_archer_object(sfVector2f pos)
{
    animation_t *idle = create_animation(1, ARCHER1_FRAMES, 0.1f, true);
    animation_t *hit = create_animation
    (NB_FRAMES_ARCHER1, ARCHER1_FRAMES, 0.8f, false);
    entity_t *archer_ent = create_archer(pos);

    hitbox *box = create_hitbox(130,
    sfSprite_getPosition(archer_ent->spritesheet->sprite),
    sfSprite_getTextureRect(archer_ent->spritesheet->sprite),
    archer);
    game_object *archer_obj = create_object(archer, archer_ent, box);

    CHECK_NULL(archer_obj);
    add_animation(archer_obj, idle, "idle");
    add_animation(archer_obj, hit, "hit");
    return archer_obj;
}
