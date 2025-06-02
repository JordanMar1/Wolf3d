/*
** EPITECH PROJECT, 2025
** G-ING-210-LIL-2-1-wolf3d-fabien.skotarek
** File description:
** create_player
*/

#include "../include/wolf.h"
#include "../include/struct.h"

// checks if the spawn exists and gives the data to the player
static void check_cell(map_t *map, player_t *player, int y)
{
    if (!map || !map->map || !map->map[y] || !player)
        return;
    for (int x = 0; map->map[y][x] != '\0'; x++) {
        if (map->map[y][x] == 'S') {
            player->pos_x = x + 0.5f;
            player->pos_y = y + 0.5f;
        }
        if (map->map[y][x] == 'D') {
            player->end_x = x + 0.5f;
            player->end_y = y + 0.5f;
        }
    }
}

// changes player's position according to the file given
void change_player_stat(player_t *player, map_t *map)
{
    player->pos_x = -1;
    player->pos_y = -1;
    player->end_x = -1;
    player->end_y = -1;
    for (int y = 0; map->map[y] != NULL; y++)
        check_cell(map, player, y);
}

// give statistics for the player
void give_player_stat(player_t *player)
{
    player->end_x = -1;
    player->end_y = -1;
    player->pos_x = -1;
    player->pos_y = -1;
    player->dirX = -1;
    player->dirY = 0;
    player->flashlight_on = 0;
    player->planeX = 0;
    player->planeY = 0.66;
    player->angle = 0.0f;
    player->hp = 100;
    player->max_hp = 150;
    player->min_hp = 0;
    player->money = 0;
    player->weapon = NULL;
}
