/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** main.cmake
*/

#include "game.h"
#include "system.h"

void setup_rand(void)
{
    srand(W_WIN + (int) WIN_TITLE);
}

int main(int ac, char *av[])
{
    game_sys_t *sys = system_create();
    scene_t status = {EXIT_SCENE, NULL};
    setup_rand();
    while (sys->actual_scene != EXIT_SCENE) {
        status = get_scene(sys->actual_scene);
        if (status.id == EXIT_SCENE)
            break;
        status.callback(sys);
    }
    system_destroy(sys);
    return EXIT_SUCCESS;
}