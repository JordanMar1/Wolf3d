/*
** EPITECH PROJECT, 2025
** main
** File description:
** disp_ammo
*/

#include "../include/struct.h"
#include "../include/wolf.h"

static void display_content(sfText *text, sfRenderWindow *window,
    sfVector2f pos)
{
    sfText_setPosition(text, pos);
    sfRenderWindow_drawText(window, text, NULL);
}

// frees the elements that displays ammo
static void free_elements(sfFont *font, sfText *text)
{
    if (font)
        sfFont_destroy(font);
    if (text)
        sfText_destroy(text);
}

// displays the number of ammo
void display_ammo(sfRenderWindow *window, int nb_ammo,
    sfVector2u win_size)
{
    sfFont *font = sfFont_createFromFile("assets/font/Impact.ttf");
    char buffer[16];
    sfVector2f pos;
    sfText *text;
    sfFloatRect bounds;

    if (font && nb_ammo >= 0) {
        snprintf(buffer, sizeof(buffer), "%d", nb_ammo);
        text = sfText_create();
        sfText_setFont(text, font);
        sfText_setString(text, buffer);
        sfText_setCharacterSize(text, 24);
        sfText_setFillColor(text, sfWhite);
        bounds = sfText_getLocalBounds(text);
        pos.x = win_size.x - bounds.width - 10;
        pos.y = win_size.y - bounds.height - 10;
        display_content(text, window, pos);
        free_elements(font, text);
    }
}
