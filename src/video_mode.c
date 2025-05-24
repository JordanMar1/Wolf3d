/*
** EPITECH PROJECT, 2025
** G-ING-210-LIL-2-1-wolf3d-fabien.skotarek
** File description:
** video_mode
*/

#include "../include/struct.h"
#include "../include/wolf.h"

// changes the videomode from the settings (resolution)
void set_video_mode(sfVideoMode *mode, int state)
{
    if (state == 0) {
        mode->width = 1280;
        mode->height = 720;
        mode->bitsPerPixel = 32;
        return;
    }
    if (state == 1) {
        mode->width = 1920;
        mode->height = 1080;
        mode->bitsPerPixel = 32;
        return;
    }
    mode->width = 800;
    mode->height = 600;
    mode->bitsPerPixel = 32;
}
