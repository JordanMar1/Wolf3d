/*
** EPITECH PROJECT, 2025
** G-ING-200-LIL-2-1-myworld-jordan.marescaux
** File description:
** create_window
*/

#include "../../../include/struct.h"
#include <stdlib.h>

sfVideoMode manage_game_vm(int vm)
{
    sfVideoMode video_mode;

    if (vm == 0) {
        video_mode = sfVideoMode_getDesktopMode();
        video_mode.bitsPerPixel = 32;
    } else {
        video_mode = sfVideoMode_getDesktopMode();
        video_mode.height /= 2;
        video_mode.width /= 2;
        video_mode.bitsPerPixel = 32;
    }
    return video_mode;
}

sfMusic *manage_game_music(sfMusic *music)
{
        music = sfMusic_createFromFile("assets/music/running_from_evil.ogg");
        sfMusic_setLoop(music, sfTrue);
        sfMusic_play(music);
        return music;
}

sfRenderWindow *manage_game_wdw(sfRenderWindow *window, sfVideoMode video_mode)
{
    window = sfRenderWindow_create(video_mode, "wolf3d", sfFullscreen,
        NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    return window;
}

wd_t *create_window(int vm)
{
    wd_t *window = malloc(sizeof(wd_t));

    window->vm = manage_game_vm(vm);
    window->window = manage_game_wdw(window->window, window->vm);
    window->text = sfTexture_createFromFile("assets/objects/wall.jpg",
        NULL);
    window->sprite = sfSprite_create();
    window->music_muted = 0;
    return window;
}
