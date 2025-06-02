/*
** EPITECH PROJECT, 2025
** G-ING-210-LIL-2-1-wolf3d-fabien.skotarek
** File description:
** music
*/

#include "../include/struct.h"
#include "../include/wolf.h"

void toggle_sound(wd_t *window)
{
    if (window == NULL)
        return;
    if (window->sound_muted == 1) {
        window->sound_muted = 0;
        return;
    }
    window->sound_muted = 1;
}

// able or disables the music in the menu
void toggle_music(wd_t *window)
{
    if (window == NULL)
        return;
    if (window->music_muted == 1) {
        window->music_muted = 0;
        return;
    }
    window->music_muted = 1;
}

void play_music(wd_t *window, data_t *data)
{
    if (window->music_muted == 0 && data->map->music &&
        sfMusic_getStatus(data->map->music) != sfPlaying) {
            sfMusic_setLoop(data->map->music, sfTrue);
            sfMusic_play(data->map->music);
    }
}
