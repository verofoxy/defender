/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** game_object.h
*/

#ifndef MUL_MY_DEFENDER_2019_GAME_OBJECT_H
#define MUL_MY_DEFENDER_2019_GAME_OBJECT_H

#include <SFML/Graphics/Types.h>
#include <stdbool.h>
#include "game.h"
#include "image.h"
#include "list.h"
#include "text.h"

typedef struct hitbox {
    bool is_displayed;
    sfCircleShape *rendering;
    float radius;
} hitbox;

typedef enum {
    shrimp,
    fly,
    monster,
    slow_tower,
    canon,
    archer,
    booster
} obj_type;

typedef struct {
    int level;
    int health_point;
    int attck_point;
    float attack_speed;
    float move_speed;
    float curr_waiting;
    float slowing;
    label_t *life_lbl;
} stat_t;

typedef struct game_object {
    hitbox *hitbox;
    list_t *animations;
    list_t *sounds;
    list_t *moves;
    char *curr_sound;
    char *curr_anim;
    char *curr_move;
    obj_type type_obj;
    bool is_focused;
    bool has_been_focused;
    struct entity *entity;
} game_object;

typedef struct entity {
    image_t *spritesheet;
    stat_t *stat;
    game_object *on_focus;
    bool is_up;
    float curr_time_top_offset;
} entity_t;

game_object *create_object(obj_type type, entity_t *object, hitbox *box);
void object_destroy(game_object *obj);
void draw_object(game_object *obj, game_sys_t *sys);
void move_object(game_object *obj, sfClock *clock);

entity_t *create_slow_tower(sfVector2f pos);
entity_t *create_canon(sfVector2f pos);
entity_t *create_archer(sfVector2f pos);
void entity_destroy(entity_t *ent);

entity_t *create_fly1(sfVector2f pos);
entity_t *create_fly2(sfVector2f pos);
entity_t *create_shrimp1(sfVector2f pos);
entity_t *create_shrimp2(sfVector2f pos);

game_object *create_fly1_object(sfVector2f pos);
game_object *create_fly2_object(sfVector2f pos);
game_object *create_shrimp1_object(sfVector2f pos);
game_object *create_shrimp2_object(sfVector2f pos);

game_object *create_canon_object(sfVector2f pos);
game_object *create_slow_tower_object(sfVector2f pos);
game_object *create_archer_object(sfVector2f pos);
game_object *create_booster_object(sfVector2f pos);

stat_t *create_stat(int, int health_point, int attck_point, float attck_speed);
void destroy_stat(stat_t *stat);
void set_stat_speed(stat_t *stat, float move_speed);

hitbox *create_hitbox(float radius, sfVector2f pos, sfIntRect area, obj_type type);
void hitbox_destroy(hitbox *box);

void move_left(game_object *obj, sfClock *clock);
void move_right(game_object *obj, sfClock *clock);
void move_top(game_object *obj, sfClock *clock);
void move_bottom(game_object *obj, sfClock *clock);

void change_move(game_object *obj, char *move);
void move_enemy(game_object *enemy, sfClock *clock);
void add_move(game_object *obj, void (*ptr)(), char *tag);

bool is_in_range(game_object *en, game_object *tower);
void apply_slow_tower_effect(list_t *enemies, game_object *tower);
void attack_enemy(game_object *tower);
void focus_new_enemy(list_t *enemies, game_object *tower);
void check_death(list_t **enemies, int *coins, game_object *tower);
void reset_enemy_wave_focus(list_t *enemies);

void draw_towers(list_t *towers, game_sys_t *sys);
void animate_buildings(list_t *towers, sfClock *clock);

#include "shop.h"
#include "map.h"

void buy_slow_tower(list_t **towers, shop_t *shop, map_t *map);
void buy_canon(list_t **towers, shop_t *shop, map_t *map);
void buy_archer(list_t **towers, shop_t *shop, map_t *map);
void buy_booster(list_t **towers, shop_t *shop, map_t *map);
void active_location(shop_t *shop, map_t *map, game_sys_t *sys);
void check_shop_btns_pressed(list_t **towers, shop_t *shop, map_t *map,
game_sys_t *sys);
tower_location *get_location(map_t *map, sfVector2i mouse_pos);
#endif