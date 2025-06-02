/*
** EPITECH PROJECT, 2025
** G-ING-210-LIL-2-1-wolf3d-fabien.skotarek
** File description:
** settings
*/

#include "../include/struct.h"
#include "../include/wolf.h"

// displays the button for the settings
static void display_settings_menu(sfRenderWindow *window, settings_t *set)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawText(window, set->title, NULL);
    sfRenderWindow_drawText(window, set->audio, NULL);
    sfRenderWindow_drawText(window, set->video, NULL);
    sfRenderWindow_drawText(window, set->volume, NULL);
    sfRenderWindow_display(window);
}

// frees the texts of the settings
void destroy_settings_texts(settings_t *set)
{
    sfText_destroy(set->title);
    sfText_destroy(set->audio);
    sfText_destroy(set->video);
    sfText_destroy(set->volume);
    sfFont_destroy(set->font);
    free(set);
}

// changes the resolution of the screen
void change_resolution(sfRenderWindow **window_ptr)
{
    static int state = 0;
    sfVideoMode mode;
    sfRenderWindow *window = *window_ptr;
    sfVector2i pos;

    pos = sfRenderWindow_getPosition(window);
    set_video_mode(&mode, state);
    state = (state + 1) % 3;
    sfRenderWindow_close(window);
    *window_ptr = sfRenderWindow_create(mode, "wolf3d", sfDefaultStyle, NULL);
    sfRenderWindow_setPosition(*window_ptr, pos);
}

static int process_volume_click(settings_t *set, wd_t *wd, sfEvent *event)
{
    sfFloatRect volume_bounds;
    sfRenderWindow *window = *set->window_ptr;
    sfVector2i mouse;

    volume_bounds = sfText_getGlobalBounds(set->volume);
    mouse = sfMouse_getPositionRenderWindow(window);
    if (sfFloatRect_contains(&volume_bounds, mouse.x, mouse.y)) {
        toggle_sound(wd);
        return 0;
    }
}

//looks the mouse click events
static int process_click(settings_t *set, wd_t *wd, sfEvent *event)
{
    sfRenderWindow *window = *set->window_ptr;
    sfVector2i mouse;
    sfFloatRect audio_bounds;
    sfFloatRect video_bounds;

    if (event->type != sfEvtMouseButtonPressed ||
        event->mouseButton.button != sfMouseLeft)
        return 0;
    mouse = sfMouse_getPositionRenderWindow(window);
    audio_bounds = sfText_getGlobalBounds(set->audio);
    video_bounds = sfText_getGlobalBounds(set->video);
    if (sfFloatRect_contains(&audio_bounds, mouse.x, mouse.y)) {
        toggle_music(wd);
        return 0;
    }
    if (sfFloatRect_contains(&video_bounds, mouse.x, mouse.y)) {
        change_resolution(set->window_ptr);
        return 0;
    }
    return process_volume_click(set, wd, event);
}

//handles the events in the settings
static int handle_settings_events(settings_t *set, wd_t *wd)
{
    sfRenderWindow *window = *set->window_ptr;
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
            return 1;
        }
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            return 1;
        if (process_click(set, wd, &event))
            return 1;
    }
    return 0;
}

//opens the settings window
void launch_settings_menu(sfRenderWindow **window_ptr, wd_t *wd)
{
    settings_t *set;

    set = create_struct_settings(window_ptr);
    if (!set) {
        destroy_settings_texts(set);
        return;
    }
    while (sfRenderWindow_isOpen(*window_ptr)) {
        if (handle_settings_events(set, wd) == 1)
            break;
        display_settings_menu(*window_ptr, set);
    }
    destroy_settings_texts(set);
}
