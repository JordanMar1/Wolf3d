/*
** EPITECH PROJECT, 2025
** G-ING-210-LIL-2-1-wolf3d-fabien.skotarek
** File description:
** music
*/

#include "../include/struct.h"
#include "../include/wolf.h"

// able or disables the music in the menu
void toggle_music(wd_t *window)
{
    if (window == NULL || window->music == NULL)
        return;
    if (window->music_muted == 1) {
        sfMusic_setVolume(window->music, 100);
        window->music_muted = 0;
        return;
    }
    sfMusic_setVolume(window->music, 0);
    window->music_muted = 1;
}
