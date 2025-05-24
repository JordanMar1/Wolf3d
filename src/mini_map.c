/*
** EPITECH PROJECT, 2025
** G-ING-210-LIL-2-1-wolf3d-fabien.skotarek
** File description:
** mini_map
*/

#include "../include/struct.h"

//draws a minimap cell
void draw_minimap_cell(sfRenderWindow *window, int x, int y, char type)
{
    sfRectangleShape *cell = sfRectangleShape_create();
    sfVector2f size = {MINIMAP_SCALE, MINIMAP_SCALE};
    sfVector2f position = {
        MINIMAP_MARGIN + x * MINIMAP_SCALE,
        MINIMAP_MARGIN + y * MINIMAP_SCALE
    };

    sfRectangleShape_setSize(cell, size);
    sfRectangleShape_setPosition(cell, position);
    if (type == 'W')
        sfRectangleShape_setFillColor(cell, sfColor_fromRGB(100, 100, 100));
    else
        sfRectangleShape_setFillColor(cell, sfColor_fromRGB(30, 30, 30));
    sfRenderWindow_drawRectangleShape(window, cell, NULL);
    sfRectangleShape_destroy(cell);
}

//draws all the cells of the minimap
void draw_minimap_background(sfRenderWindow *window, map_t *map)
{
    for (int y = 0; map->map[y] != NULL; y++) {
        for (int x = 0; map->map[y][x] != '\0'; x++) {
            draw_minimap_cell(window, x, y, map->map[y][x]);
        }
    }
}

//draws the player on the minimap
void draw_minimap_player(sfRenderWindow *window, player_t *player)
{
    sfCircleShape *player_dot = sfCircleShape_create();
    sfVector2f player_pos = {
        MINIMAP_MARGIN + player->pos_x * MINIMAP_SCALE - MINIMAP_SCALE / 2,
        MINIMAP_MARGIN + player->pos_y * MINIMAP_SCALE - MINIMAP_SCALE / 2
    };

    sfCircleShape_setRadius(player_dot, MINIMAP_SCALE / 2.5f);
    sfCircleShape_setFillColor(player_dot, sfRed);
    sfCircleShape_setPosition(player_dot, player_pos);
    sfRenderWindow_drawCircleShape(window, player_dot, NULL);
    sfCircleShape_destroy(player_dot);
}

//draws the direction of the player on the minimap
void draw_minimap_direction(sfRenderWindow *window, player_t *player)
{
    sfVector2f dir_line_start = {
        MINIMAP_MARGIN + player->pos_x * MINIMAP_SCALE,
        MINIMAP_MARGIN + player->pos_y * MINIMAP_SCALE
    };
    sfVector2f dir_line_end = {
        dir_line_start.x + player->dirX * MINIMAP_SCALE * 2,
        dir_line_start.y + player->dirY * MINIMAP_SCALE * 2
    };
    sfVertex dir[] = {
        {dir_line_start, sfRed, {0, 0}},
        {dir_line_end, sfRed, {0, 0}}
    };

    sfRenderWindow_drawPrimitives(window, dir, 2, sfLines, NULL);
}

//draws all the elements of the minimap
void draw_minimap(sfRenderWindow *window, map_t *map, player_t *player)
{
    draw_minimap_background(window, map);
    draw_minimap_player(window, player);
    draw_minimap_direction(window, player);
}
