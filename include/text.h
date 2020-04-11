/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** text.h
*/

#ifndef MUL_MY_DEFENDER_2019_TEXT_H
#define MUL_MY_DEFENDER_2019_TEXT_H

typedef struct {
    char *mall;
    sfText *txt;
    sfFont *font;
} label_t;

label_t *create_label(char const *fontpath, unsigned int size, char *txt,
sfColor color);
void draw_lbl(label_t *lbl, game_sys_t *sys);
void change_text(label_t *lbl, char *new_txt);
void label_destroy(label_t *lbl);
#endif