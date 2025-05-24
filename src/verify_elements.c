/*
** EPITECH PROJECT, 2025
** G-ING-210-LIL-2-1-wolf3d-fabien.skotarek
** File description:
** verify_elements
*/

#include "../include/wolf.h"

// looks music's files
int look_music(void)
{
    int music = 0;

    music = open("assets/music/at_dooms_gate.ogg", O_RDONLY);
    if (music < 0)
        return -1;
    close(music);
    music = open("assets/music/running_from_evil.ogg", O_RDONLY);
    if (music < 0)
        return -1;
    close(music);
    return 0;
}

static int look_menu_p2(void)
{
    int menu = open("assets/menu/wolf3d_menu.png", O_RDONLY);

    if (menu < 0)
        return -1;
    close(menu);
    return 0;
}

//looks all the menu's elements
int look_menu(void)
{
    int menu;

    menu = open("assets/menu/bouton_play.png", O_RDONLY);
    if (menu < 0)
        return -1;
    close(menu);
    menu = open("assets/menu/bouton_quit.png", O_RDONLY);
    if (menu < 0)
        return -1;
    close(menu);
    menu = open("assets/menu/fond_wolf3d.png", O_RDONLY);
    if (menu < 0)
        return -1;
    close(menu);
    menu = open("assets/menu/settings.png", O_RDONLY);
    if (menu < 0)
        return -1;
    close(menu);
    return look_menu_p2();
}

//looks if the fonts for wolf3d are existing
int look_fonts(void)
{
    int font;

    font = open("assets/font/Georgia_Bold_Italic.ttf", O_RDONLY);
    if (font < 0)
        return -1;
    close(font);
    font = open("assets/font/Impact.ttf", O_RDONLY);
    if (font < 0)
        return -1;
    close(font);
    return 0;
}
