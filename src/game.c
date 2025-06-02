/*
** EPITECH PROJECT, 2025
** G-ING-210-LIL-2-1-wolf3d-fabien.skotarek
** File description:
** game
*/

#include "../include/struct.h"
#include "../include/wolf.h"

// looks if the player and the end exists in the map
static int is_file_err(player_t *player)
{
    if (player->pos_x == -1 || player->pos_y == -1)
        return 1;
    if (player->end_x == -1 || player->end_y == -1)
        return 1;
    return 0;
}

static void destroy_game(menu_t *menu, sfClock *clock, wd_t *window,
    data_t *data)
{
    if (menu)
        destroy_menu(menu);
    if (clock)
        sfClock_destroy(clock);
    if (window)
        free_window(window);
    if (data)
        free_data(data);
}

// manage events to close the window
static int manage_events(struct wd *wd, player_t *player)
{
    while (sfRenderWindow_pollEvent(wd->window, &wd->event)) {
        if (wd->event.type == sfEvtClosed ||
            sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(wd->window);
        if (wd->event.type == sfEvtKeyPressed && wd->event.key.code == sfKeyF)
            player->flashlight_on = !player->flashlight_on;
    }
    return 0;
}

// refreshes the window
static void refresh_window(wd_t *wd,
    data_t *data, float frame_time, map_t *map)
{
    float z_buffer[SCREEN_WIDTH];
    sfRenderWindow *window = wd->window;

    sfRenderWindow_clear(window, sfBlack);
    draw_floor_plus_ceiling(window);
    handle_mouse_rotation(window, data->player);
    handle_movement(data->player, frame_time, map);
    render_walls(window, data->player, map, z_buffer);
    if (data->player->weapon) {
        sfRenderWindow_drawSprite(window, data->player->weapon->sprite, NULL);
        display_ammo(window, data->player->weapon->ammo,
            sfRenderWindow_getSize(window));
        handle_change_weapon(data->player, wd->event);
        handle_shoot(data->player, wd);
    }
    draw_minimap(window, map, data->player);
    display_head(wd->head, window,
        data->player->hp, sfRenderWindow_getSize(window));
    sfRenderWindow_display(window);
}

static void manage_old_map(map_t *old_map)
{
    sfMusic_stop(old_map->music);
    free_array(old_map->map);
    free(old_map);
}

static void check_map_transition(data_t *data, wd_t *window,
    sfClock *clock, menu_t *menu)
{
    float dx = data->player->pos_x - data->player->end_x;
    float dy = data->player->pos_y - data->player->end_y;
    float distance = sqrtf(dx * dx + dy * dy);
    map_t *old_map;

    if (distance < 1 && !data->map->next) {
        printf("You Won bravo !!");
        destroy_game(menu, clock, window, data);
        exit(0);
    }
    if (distance < 1 && data->map->next) {
        old_map = data->map;
        data->map = data->map->next;
        manage_old_map(old_map);
        change_player_stat(data->player, data->map);
        if (is_file_err(data->player) == 1) {
            destroy_game(menu, clock, window, data);
            exit(84);
        }
    }
}

static void game_loop(sfClock *clock, wd_t *window, data_t *data, menu_t *menu)
{
    int menu_status = 0;
    float frame_time;

    while (sfRenderWindow_isOpen(window->window)) {
        frame_time = sfTime_asSeconds(sfClock_restart(clock));
        if (menu_status != 1) {
            menu_status = handle_menu_events(window->window, menu,
                window);
            draw_menu(window->window, menu);
        } else {
            play_music(window, data);
            manage_events(window, data->player);
            sfRenderWindow_setMouseCursorVisible(window->window, sfFalse);
            refresh_window(window, data,
                frame_time, data->map);
            check_map_transition(data, window, clock, menu);
        }
    }
}

//creates the window
int launch_game(int game_status, char *filepath)
{
    sfClock *clock = sfClock_create();
    wd_t *window = create_window(game_status);
    menu_t *menu = create_menu(window->window);
    data_t *data = create_data(filepath, window->window);
    obj_t *head = create_head_obj();

    if (!data)
        return 84;
    if (!data->player || !data->map) {
        free_data(data);
        return 84;
    }
    window->head = head;
    change_player_stat(data->player, data->map);
    if (is_file_err(data->player) == 1 || check_bounds(data->map) == 1)
        return 84;
    game_loop(clock, window, data, menu);
    destroy_game(menu, clock, window, data);
    return 0;
}
