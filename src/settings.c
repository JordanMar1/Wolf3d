/*
** EPITECH PROJECT, 2025
** G-ING-210-LIL-2-1-wolf3d-fabien.skotarek
** File description:
** settings
*/

#include "../include/struct.h"
#include "../include/wolf.h"

// displays the text Reglages in the settings
static void create_title_text(sfText **title, sfFont *font)
{
    *title = sfText_create();
    if (*title == NULL)
        return;
    sfText_setFont(*title, font);
    sfText_setString(*title, "Reglages");
    sfText_setCharacterSize(*title, 48);
    sfText_setPosition(*title, (sfVector2f){100, 80});
    sfText_setColor(*title, sfWhite);
}

// displays the text corresponding to audio parameters
static void create_audio_text(sfText **audio, sfFont *font)
{
    *audio = sfText_create();
    if (*audio == NULL)
        return;
    sfText_setFont(*audio, font);
    sfText_setString(*audio,
        "Son :\n- Volume general\n- Activer/Desactiver la musique");
    sfText_setCharacterSize(*audio, 32);
    sfText_setPosition(*audio, (sfVector2f){100, 180});
    sfText_setColor(*audio, sfWhite);
}

// creates texts that corresponds to video
static void create_video_text(sfText **video, sfFont *font)
{
    *video = sfText_create();
    if (*video == NULL)
        return;
    sfText_setFont(*video, font);
    sfText_setString(*video, "\n- Resolution\n");
    sfText_setCharacterSize(*video, 32);
    sfText_setPosition(*video, (sfVector2f){100, 260});
    sfText_setColor(*video, sfWhite);
}

// creates all texts in settings
static void create_settings_texts(sfText **title, sfText **audio,
    sfText **video, sfFont *font)
{
    create_title_text(title, font);
    create_audio_text(audio, font);
    create_video_text(video, font);
}

// displays the button for the settings
void display_settings_menu(sfRenderWindow *window, sfText *title,
    sfText *audio, sfText *video)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawText(window, title, NULL);
    sfRenderWindow_drawText(window, audio, NULL);
    sfRenderWindow_drawText(window, video, NULL);
    sfRenderWindow_display(window);
}

// frees the texts of the settings
static void destroy_settings_texts(settings_t *set,
    sfFont *font)
{
    sfText_destroy(set->title);
    sfText_destroy(set->audio);
    sfText_destroy(set->video);
    sfFont_destroy(font);
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

//looks the mouse click events
int process_click(settings_t *set, wd_t *wd, sfEvent *event)
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
    return 0;
}

//handles the events in the settings
int handle_settings_events(settings_t *set, wd_t *wd)
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
    sfFont *font = sfFont_createFromFile("./assets/font/Impact.ttf");
    sfText *title = NULL;
    sfText *audio = NULL;
    sfText *video = NULL;
    settings_t *set;

    if (font == NULL)
        return;
    create_settings_texts(&title, &audio, &video, font);
    set = create_struct_settings(window_ptr, title, audio, video);
    if (title == NULL || audio == NULL || video == NULL) {
        destroy_settings_texts(set, font);
        return;
    }
    while (sfRenderWindow_isOpen(*window_ptr)) {
        if (handle_settings_events(set, wd) == 1)
            break;
        display_settings_menu(*window_ptr, title, audio, video);
    }
    destroy_settings_texts(set, font);
}
