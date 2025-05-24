/*
** EPITECH PROJECT, 2025
** G-ING-210-LIL-2-1-wolf3d-fabien.skotarek
** File description:
** create_settings
*/

#include "../include/struct.h"

// creates the structure settings
settings_t *create_struct_settings(sfRenderWindow **window_ptr,
    sfText *title, sfText *audio, sfText *video)
{
    settings_t *set = malloc(sizeof(settings_t));

    set->window_ptr = window_ptr;
    set->audio = audio;
    set->video = video;
    set->title = title;
    return set;
}
