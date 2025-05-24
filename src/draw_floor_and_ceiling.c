/*
** EPITECH PROJECT, 2025
** G-ING-210-LIL-2-1-wolf3d-fabien.skotarek
** File description:
** draw_floor_and_ceiling
*/

#include "../include/struct.h"

// displays the floor and the ceiling
void draw_floor_plus_ceiling(sfRenderWindow* window)
{
    sfRectangleShape* rect = sfRectangleShape_create();
    sfVector2f size = (sfVector2f){sfRenderWindow_getSize(window).x,
        sfRenderWindow_getSize(window).y};

    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setFillColor(rect, sfColor_fromRGB(135, 206, 235));
    sfRectangleShape_setPosition(rect, (sfVector2f){0, 0});
    sfRenderWindow_drawRectangleShape(window, rect, NULL);
    sfRectangleShape_setFillColor(rect, sfColor_fromRGB(160, 82, 45));
    sfRectangleShape_setPosition(rect, (sfVector2f){0, 535});
    sfRenderWindow_drawRectangleShape(window, rect, NULL);
    sfRectangleShape_destroy(rect);
}
