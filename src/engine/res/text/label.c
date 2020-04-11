/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** label.c
*/

#include "game.h"
#include "text.h"

label_t *create_label(char const *fontpath, unsigned int size, char *txt,
sfColor color)
{
    label_t *lbl = malloc(sizeof(*lbl));

    CHECK_NULL(lbl);
    lbl->txt = sfText_create();
    lbl->mall = txt;
    lbl->font = sfFont_createFromFile(fontpath);
    if (!lbl->font)
        return NULL;
    sfText_setString(lbl->txt, txt);
    sfText_setFont(lbl->txt, lbl->font);
    sfText_setColor(lbl->txt, color);
    sfText_setCharacterSize(lbl->txt, size);
    return lbl;
}

void draw_lbl(label_t *lbl, game_sys_t *sys)
{
    sfRenderWindow_drawText(sys->window, lbl->txt, NULL);
}

void change_text(label_t *lbl, char *new_txt)
{
    if (!new_txt)
        return;
    free(lbl->mall);
    sfText_setString(lbl->txt, new_txt);
    lbl->mall = new_txt;
}

void label_destroy(label_t *lbl)
{
    free(lbl->mall);
    sfText_destroy(lbl->txt);
    sfFont_destroy(lbl->font);
    free(lbl);
}