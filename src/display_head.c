/*
** EPITECH PROJECT, 2025
** main
** File description:
** display_head
*/

#include "../include/struct.h"

// creates the head that gives the number of HP
void display_head(obj_t *head, sfRenderWindow *window, int pv,
    sfVector2u win_size)
{
    int index;

    if (pv > 80)
        index = 0;
    if (pv > 60 && pv <= 80)
        index = 1;
    if (pv > 40 && pv <= 60)
        index = 2;
    if (pv > 20 && pv <= 40)
        index = 3;
    if (pv > 0 && pv <= 20)
        index = 4;
    head->rect.left = index * head->rect.width;
    sfSprite_setTextureRect(head->sprite, head->rect);
    head->e_pos.x = win_size.x - head->rect.width - 10;
    head->e_pos.y = 10;
    sfSprite_setPosition(head->sprite, head->e_pos);
    sfRenderWindow_drawSprite(window, head->sprite, NULL);
}
