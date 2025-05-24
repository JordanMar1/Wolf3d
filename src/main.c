/*
** EPITECH PROJECT, 2025
** G-ING-210-LIL-2-1-wolf3d-fabien.skotarek
** File description:
** main
*/

#include "../include/wolf.h"
#include "../include/struct.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stddef.h>


// flag -h
static int display_credits(void)
{
    my_putstr("plafond image: \n");
    my_putstr("Music: \n\n");
    my_putstr("USAGE :  ./wolf3d [file] \n");
    my_putstr("file: -f opens the file that you choose to open the");
    my_putstr(" game, if the file doesn't exist, the original game");
    my_putstr(" launches");
    return 0;
}

// verifies that everything works
static int verify_elements(void)
{
    int music;
    int menu;
    int fonts;

    music = look_music();
    if (music < 0)
        return -1;
    menu = look_menu();
    if (menu < 0)
        return -1;
    fonts = look_fonts();
    return fonts;
}

//looks for the element after flag f
static char *get_filepath(int argc, char **argv, int i)
{
    if (i >= argc)
        return "assets/content/wolf3d.wac";
    return argv[i];
}

static int check_env(char **env)
{
    if (env[0] == NULL)
        return -1;
    if (my_strcmp(env[6], "XDG_SESSION_TYPE=tty") != 0)
        return 0;
    return -1;
}

int main(int argc, char **argv, char **env)
{
    char *filepath = "assets/content/wolf3d.wac";

    for (int i = 0; i < argc; i++) {
        if (my_strcmp(argv[i], "-f") == 0)
            filepath = get_filepath(argc, argv, i + 1);
    }
    if (argc == 2) {
        if (my_strcmp(argv[1], "-h") == 0)
            return display_credits();
    }
    if (verify_elements() == -1 || check_env(env) == -1)
        return 84;
    return launch_game(0, filepath);
}
