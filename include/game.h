/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** game.h
*/

#ifndef MUL_MY_DEFENDER_2019_GAME_H
#define MUL_MY_DEFENDER_2019_GAME_H

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <math.h>
#include "list.h"
#include "scene.h"
#include "res.h"

#define DEFAULT_FPS     60
#define WIN_TITLE       "MyDefender"
#define W_WIN           1920
#define H_WIN           1080

#define EXEC_SUCCESS    0
#define EXEC_FAIL       84
#define CHECK_NULL(x)   if (!x) return NULL;
#define CHECK_ERR(x)    if (!x) return EXEC_FAIL;
#define CHECK_GOOD(x)   if (x == 0) return;

#define TRUE_OPT        (void *) 1

#endif