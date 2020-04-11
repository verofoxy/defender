/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** entity_slow_tower.c
*/

#include "game.h"
#include "game_object.h"
#include "animation.h"

entity_t *create_slow_tower(sfVector2f pos)
{
    entity_t *ent = malloc(sizeof(*ent));

    CHECK_NULL(ent);
    pos.y -= (float) SLOW_TOWER1_FRAMES[0].height - SIZE_TILE;
    pos.x -= (float) SLOW_TOWER1_FRAMES[0].width / 2 - (float) SIZE_TILE / 2;
    ent->spritesheet = create_image(SLOW_TOWER1_PATH, NULL);
    sfSprite_setTextureRect(ent->spritesheet->sprite, SLOW_TOWER1_FRAMES[0]);
    sfSprite_setPosition(ent->spritesheet->sprite, pos);
    ent->stat = create_stat(1, 10, 1, 0.5f);
    ent->on_focus = NULL;
    return ent;
}

game_object *create_slow_tower_object(sfVector2f pos)
{
    animation_t *idle = create_animation(1, SLOW_TOWER1_FRAMES, 0.1f, true);
    animation_t *hit = create_animation
    (NB_FRAMES_SLOW_TOWER1, SLOW_TOWER1_FRAMES, 0.7f, false);
    entity_t *tower_ent = create_slow_tower(pos);
    hitbox *box = create_hitbox(160,
    sfSprite_getPosition(tower_ent->spritesheet->sprite),
    sfSprite_getTextureRect(tower_ent->spritesheet->sprite),
    slow_tower);
    game_object *tower_obj = create_object(slow_tower, tower_ent, box);

    CHECK_NULL(tower_obj);
    add_animation(tower_obj, idle, "idle");
    add_animation(tower_obj, hit, "hit");
    return tower_obj;
}

void apply_slow_tower_effect(list_t *enemies, game_object *tower)
{
    while (enemies) {
        if (is_in_range(enemies->element, tower)) {
            ((game_object *) enemies->element)->has_been_focused = true;
            ((game_object *) enemies->element)->is_focused = true;
            ((game_object *) enemies->element)->entity->stat->slowing =
            ((game_object *) enemies->element)->entity->stat->slowing < 1 ?
            ((game_object *) enemies->element)->entity->stat->slowing :
            ((game_object *) enemies->element)->entity->stat->slowing -
            tower->entity->stat->attack_speed;
            change_animation(tower, "hit", "idle");
        } else {
            ((game_object *) enemies->element)->entity->stat->slowing = 1;
            if (!((game_object *) enemies->element)->has_been_focused)
                ((game_object *) enemies->element)->is_focused = false;
        }
        enemies = enemies->next;
    }
}