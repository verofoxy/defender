/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** main_menu.c
*/

#include "game.h"
#include "scene.h"
#include "pause.h"

pause_t *create_pause(void)
{
    pause_t *pause = malloc(sizeof(*(pause)));
    pause->btns = NULL;
    pause->background = create_image(BACKGROUND_IMG, NULL);
    create_btn_menu_pause(pause);
    sfSprite_setPosition(pause->background->sprite, (sfVector2f) { 670, 120});
    return pause;
}

void destroy_pause(pause_t *pause)
{
    image_destroy(pause->background);
    free(pause);
}

void set_status_pause(list_t *btns, game_sys_t *sys)
{
    int index = 0;

    while (index != 3) {
        set_state_btn(list_get_from_index(btns, index), sys->mouse_pos);
        index++;
    }
}

void pause_event(game_sys_t *sys, pause_t *pause, int actual_scene, bool *r)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(sys->window, &event)) {
        if (event.type == sfEvtClosed) {
            exit_game(sys);
            break;
        }
        if (event.type == sfEvtMouseButtonPressed)
            check_paused_pressed(pause->btns, sys, actual_scene, r);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            change_scene(sys, actual_scene);
    }
}

void pause_scene(game_sys_t *sys, sfClock *clock, int actual_scene, bool *r)
{
    pause_t *pause = create_pause();
    int index = 0;
    list_t *btns = pause->btns;

    change_scene(sys, PAUSE_SCENE);

    while (is_open_window(sys->window) && sys->actual_scene == PAUSE_SCENE) {
        sys->mouse_pos = sfMouse_getPositionRenderWindow(sys->window);
        set_status_pause(pause->btns, sys);
        pause_event(sys, pause, actual_scene, r);
        sfRenderWindow_drawSprite(sys->window, pause->background->sprite, NULL);
        for (index = 0; index < 3; index++)
            draw_btn(list_get_from_index(btns, index), sys);
        sfRenderWindow_display(sys->window);
    }
    destroy_pause(pause);
    sfClock_restart(clock);
}
