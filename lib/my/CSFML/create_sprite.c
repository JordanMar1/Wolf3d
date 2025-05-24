/*
** EPITECH PROJECT, 2025
** CSFML
** File description:
** create_sprite
*/

#include "../../../include/struct.h"
#include <stdlib.h>

struct obj *create_ennemy(sfRenderWindow *window, int y)
{
    struct obj *object = malloc(sizeof(struct obj));

    object->texture = sfTexture_createFromFile("image", NULL);
    if (!object->texture) {
        free(object);
        return NULL;
    }
    object->e_pos.y = (float)y;
    object->e_pos.x = (float)100;
    object->rect.left = 0;
    object->rect.top = 0;
    object->rect.width = 100;
    object->rect.height = 150;
    object->sprite = sfSprite_create();
    if (!object->sprite) {
        sfTexture_destroy(object->texture);
        free(object);
        return NULL;
    }
    return object;
}
