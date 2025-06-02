/*
** EPITECH PROJECT, 2025
** ING
** File description:
** free_window
*/

#include "../include/struct.h"
#include "../include/wolf.h"

// frees a structure window
void free_window(wd_t *window)
{
    sfRenderWindow_close(window->window);
    sfTexture_destroy(window->text);
    sfSprite_destroy(window->sprite);
    sfTexture_destroy(window->head->texture);
    sfSprite_destroy(window->head->sprite);
    free(window->head);
    free(window);
}
