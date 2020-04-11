/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** main_menu.c
*/

#include "game_object.h"
#include "map.h"
#include "game.h"
#include "scene.h"
#include "main_menu.h"
#include "window.h"
#include "res.h"
#include "my.h"
#include "sound.h"

main_menu_t *create_main_menu(void)
{
    main_menu_t *main_menu = malloc(sizeof(*(main_menu)));

    CHECK_NULL(main_menu);
    main_menu->btns = NULL;
    main_menu->title = create_image(MAIN_MENU_IMG, NULL);
    main_menu->cadre = create_image(TITLE_IMG, NULL);
    create_btn_main_menu(main_menu);
    sfSprite_setPosition(main_menu->title->sprite, (sfVector2f) {450, 200});
    sfSprite_setPosition(main_menu->cadre->sprite, (sfVector2f) {15, -15});
    return main_menu;
}

void destroy_main_menu(main_menu_t *main_menu)
{
    image_destroy(main_menu->title);
    image_destroy(main_menu->cadre);
    free(main_menu);
}

void set_status_main_menu(list_t *btns, game_sys_t *sys)
{
    int index = 0;

    while (index != 6) {
        set_state_btn(list_get_from_index(btns, index), sys->mouse_pos);
        index++;
    }
}

void draw_main_menu(game_sys_t *sys, main_menu_t *main_menu)
{
    int index = 0;
    list_t *btns = main_menu->btns;
    sfRenderWindow_drawSprite(sys->window, main_menu->title->sprite, NULL);
    sfRenderWindow_drawSprite(sys->window, main_menu->cadre->sprite, NULL);
    while (index != 6) {
        draw_btn(list_get_from_index(btns, index), sys);
        index++;
    }
}

void main_menu_scene(game_sys_t *sys)
{
    sfClock *clock = sfClock_create();
    main_menu_t *main_menu = create_main_menu();
    map_t *map = load_map("./map_level1.txt");
    play_sound(list_get_from_tag(sys->osts, "main"));

    while (is_open_window(sys->window) && sys->actual_scene == MENU_SCENE) {
        sys->mouse_pos = sfMouse_getPositionRenderWindow(sys->window);
        set_status_main_menu(main_menu->btns, sys);
        manage_events(sys, main_menu);
        sfRenderWindow_clear(sys->window, sfBlack);
        transform_to_image(map, sys->window);
        draw_main_menu(sys, main_menu);
        sfRenderWindow_display(sys->window);
        sfClock_restart(clock);
    }
    sfClock_destroy(clock);
    if (sys->actual_scene == LEVEL1_SCENE)
        stop_sound(list_get_from_tag(sys->osts, "main"));
    destroy_main_menu(main_menu);
}
