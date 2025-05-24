/*
** EPITECH PROJECT, 2025
** main
** File description:
** create_head
*/

#include "../include/struct.h"
#include "../include/wolf.h"

// creates the head that serves to display HP
obj_t *create_head_obj(void)
{
    obj_t *head = malloc(sizeof(obj_t));
    char *filepath = "assets/objects/heads.png";

    if (!head)
        return NULL;
    head->texture = sfTexture_createFromFile(filepath, NULL);
    if (!head->texture) {
        free(head);
        return NULL;
    }
    head->sprite = sfSprite_create();
    sfSprite_setTexture(head->sprite, head->texture, sfTrue);
    head->rect = (sfIntRect){0, 0, 76, 102};
    sfSprite_setTextureRect(head->sprite, head->rect);
    head->e_pos = (sfVector2f){10, 10};
    sfSprite_setPosition(head->sprite, head->e_pos);
    return head;
}
