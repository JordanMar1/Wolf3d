/*
** EPITECH PROJECT, 2025
** G-ING-210-LIL-2-1-wolf3d-fabien.skotarek
** File description:
** create_settings
*/

#include "../include/struct.h"

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
        "Son :\n- Activer/Desactiver la musique");
    sfText_setCharacterSize(*audio, 32);
    sfText_setPosition(*audio, (sfVector2f){100, 190});
    sfText_setColor(*audio, sfWhite);
}

// creates texts that corresponds to video
static void create_video_text(sfText **video, sfFont *font)
{
    *video = sfText_create();
    if (*video == NULL)
        return;
    sfText_setFont(*video, font);
    sfText_setString(*video, "Video:\n- Resolution\n");
    sfText_setCharacterSize(*video, 32);
    sfText_setPosition(*video, (sfVector2f){100, 330});
    sfText_setColor(*video, sfWhite);
}

// displays the text for general volume
static void create_volume_text(sfText **volume, sfFont *font)
{
    *volume = sfText_create();
    if (*volume == NULL)
        return;
    sfText_setFont(*volume, font);
    sfText_setString(*volume, "- Volume general");
    sfText_setCharacterSize(*volume, 32);
    sfText_setPosition(*volume, (sfVector2f){100, 280});
    sfText_setColor(*volume, sfWhite);
}

// creates all texts in settings
static void create_settings_texts(sfText **title, sfText **audio,
    sfText **video, sfFont *font)
{
    create_title_text(title, font);
    create_audio_text(audio, font);
    create_video_text(video, font);
}

settings_t *error_settings(settings_t *set)
{
    destroy_settings_texts(set);
    return NULL;
}

// creates the structure settings
settings_t *create_struct_settings(sfRenderWindow **window_ptr)
{
    settings_t *set = malloc(sizeof(settings_t));

    if (!set)
        return error_settings(set);
    set->window_ptr = window_ptr;
    set->title = NULL;
    set->audio = NULL;
    set->video = NULL;
    set->volume = NULL;
    set->font = sfFont_createFromFile("./assets/font/Impact.ttf");
    if (!set->font)
        return error_settings(set);
    create_settings_texts(&set->title, &set->audio, &set->video, set->font);
    if (!set->title || !set->audio || !set->video)
        return error_settings(set);
    create_volume_text(&set->volume, set->font);
    if (!set->volume)
        return error_settings(set);
    return set;
}
