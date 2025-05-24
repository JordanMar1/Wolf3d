/*
** EPITECH PROJECT, 2025
** G-ING-210-LIL-2-1-wolf3d-fabien.skotarek
** File description:
** test
*/

#include "../include/struct.h"
#include "../include/wolf.h"

//create the settings button on menu display
static void create_settings_button(menu_t *menu, sfRenderWindow *window)
{
    sfVector2u win = sfRenderWindow_getSize(window);
    sfVector2f scale = {1, 1};

    menu->settings_texture = sfTexture_createFromFile(
        "./assets/menu/settings.png", NULL);
    if (!menu->settings_texture)
        return;
    menu->settings_button = sfSprite_create();
    if (!menu->settings_button)
        return;
    scale = (win.x < 1800) ? (sfVector2f){0.4, 0.4} : (sfVector2f){0.7, 0.7};
    sfSprite_setTexture(menu->settings_button,
        menu->settings_texture, sfTrue);
    sfSprite_setPosition(menu->settings_button, (sfVector2f){20, 20});
    sfSprite_setScale(menu->settings_button, scale);
}

// creates a background for the menu
sfSprite *create_background(sfTexture **texture, sfRenderWindow *window)
{
    sfSprite *sprite = sfSprite_create();
    sfVector2u tex_size;
    sfVector2f scale = {0, 0};
    sfVector2u window_size = sfRenderWindow_getSize(window);

    if (!sprite)
        return NULL;
    *texture = sfTexture_createFromFile("./assets/menu/fond_wolf3d.png", NULL);
    if (!*texture)
        return NULL;
    sfSprite_setTexture(sprite, *texture, sfTrue);
    tex_size = sfTexture_getSize(*texture);
    scale.x = (float)window_size.x / tex_size.x;
    scale.y = (float)window_size.y / tex_size.y;
    sfSprite_setScale(sprite, scale);
    return sprite;
}

// creates the button in order to play
static void create_play_button(menu_t *menu, sfRenderWindow *window)
{
    sfVector2u window_size = sfRenderWindow_getSize(window);
    sfVector2f scale = {1, 1};

    menu->play_texture = sfTexture_createFromFile(
        "./assets/menu/bouton_play.png", NULL);
    if (!menu->play_texture)
        return;
    menu->play_button = sfSprite_create();
    if (!menu->play_button)
        return;
    if (window_size.x < 1800)
        scale = (sfVector2f){0.5, 0.5};
    sfSprite_setTexture(menu->play_button, menu->play_texture, sfTrue);
    sfSprite_setPosition(menu->play_button,
        (sfVector2f){window_size.x / 4.8, window_size.y / 1.84});
    sfSprite_setScale(menu->play_button, scale);
}

// creates the button in order to quit
static void create_quit_button(menu_t *menu, sfRenderWindow *window)
{
    sfVector2u window_size = sfRenderWindow_getSize(window);
    sfVector2f scale = {0, 0};

    menu->quit_texture = sfTexture_createFromFile(
        "./assets/menu/bouton_quit.png", NULL);
    if (!menu->quit_texture)
        return;
    menu->quit_button = sfSprite_create();
    if (!menu->quit_button)
        return;
    if (window_size.x >= 1800)
        scale = (sfVector2f){0.7, 0.7};
    else
        scale = (sfVector2f){0.3, 0.3};
    sfSprite_setTexture(menu->quit_button, menu->quit_texture, sfTrue);
    sfSprite_setPosition(menu->quit_button,
        (sfVector2f){window_size.x / 1.6, window_size.y / 1.84});
    sfSprite_setScale(menu->quit_button, scale);
}

//creates the data structure menu
menu_t *create_menu(sfRenderWindow *window)
{
    menu_t *menu = malloc(sizeof(menu_t));

    if (!menu)
        return NULL;
    menu->bg_sprite = create_background(&menu->bg_texture, window);
    if (!menu->bg_sprite)
        return NULL;
    create_play_button(menu, window);
    create_quit_button(menu, window);
    create_settings_button(menu, window);
    return menu;
}

//handle the mouse in the menu
static int handle_mouse_click(sfRenderWindow *window, menu_t *menu, wd_t *wd)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    sfFloatRect play_bounds = sfSprite_getGlobalBounds(menu->play_button);
    sfFloatRect quit_bounds = sfSprite_getGlobalBounds(menu->quit_button);
        sfFloatRect settings = sfSprite_getGlobalBounds(menu->settings_button);

    if (sfFloatRect_contains(&play_bounds, mouse.x, mouse.y))
        return 1;
    if (sfFloatRect_contains(&quit_bounds, mouse.x, mouse.y))
        sfRenderWindow_close(window);
    if (sfFloatRect_contains(&settings, mouse.x, mouse.y))
        launch_settings_menu(&window, wd);
    return 0;
}

// handle the events from the menu
int handle_menu_events(sfRenderWindow *window, menu_t *menu, wd_t *wd)
{
    sfEvent event;
    int result = 0;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtMouseButtonPressed &&
            event.mouseButton.button == sfMouseLeft)
            result = handle_mouse_click(window, menu, wd);
    }
    return result;
}

// displays the menu
void draw_menu(sfRenderWindow *window, menu_t *menu)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, menu->bg_sprite, NULL);
    sfRenderWindow_drawSprite(window, menu->play_button, NULL);
    sfRenderWindow_drawSprite(window, menu->quit_button, NULL);
    sfRenderWindow_drawSprite(window, menu->settings_button, NULL);
    sfRenderWindow_display(window);
}

// frees the data structure menu
void destroy_menu(menu_t *menu)
{
    if (!menu)
        return;
    sfTexture_destroy(menu->bg_texture);
    sfSprite_destroy(menu->bg_sprite);
    sfTexture_destroy(menu->play_texture);
    sfSprite_destroy(menu->play_button);
    sfTexture_destroy(menu->quit_texture);
    sfSprite_destroy(menu->quit_button);
    sfTexture_destroy(menu->settings_texture);
    sfSprite_destroy(menu->settings_button);
    free(menu);
}
