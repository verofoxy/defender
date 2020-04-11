/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** btns.c
*/

#include <stdlib.h>
#include "game.h"
#include "res.h"
#include "image.h"
#include "my.h"

btn_t *create_button(list_t *sprite_states, sfIntRect hitbox, void (*callback)
())
{
    btn_t *btn = malloc(sizeof(btn_t));
    list_t *tmp = NULL;

    CHECK_NULL(btn)
    btn->state = "idle";
    btn->state_sprites = sprite_states;
    btn->callback = callback;
    btn->enabled = true;
    btn->ctrl_area = hitbox;
    for (tmp = sprite_states; tmp; tmp = tmp->next)
        sfSprite_setPosition(
        ((image_t *) tmp->element)->sprite,
        (sfVector2f) {(float) hitbox.left, (float) hitbox.top});
    return btn;
}

void draw_btn(btn_t *btn, game_sys_t *sys)
{
    sfRenderWindow_drawSprite(sys->window,
    ((image_t *) list_get_from_tag(btn->state_sprites, btn->state))->sprite,
    NULL);
}

void destroy_btn(btn_t *btn)
{
    image_destroy(list_get_from_tag(btn->state_sprites, "idle"));
    image_destroy(list_get_from_tag(btn->state_sprites, "disabled"));
    image_destroy(list_get_from_tag(btn->state_sprites, "hover"));
    free(btn);
}