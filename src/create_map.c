/*
** EPITECH PROJECT, 2025
** G-ING-210-LIL-2-1-wolf3d-fabien.skotarek
** File description:
** create_map
*/

#include "../include/struct.h"
#include "../include/wolf.h"

// randomly gives an ennemy
char is_ennemy(map_t *map, int height, int length)
{
    int i = rand() % 10;

    if (map->map[height][length] == 'W')
        return 'W';
    if (i == 0)
        return 'E';
    return ' ';
}

// Fills the map randomly
map_t *create_valid_map(map_t *map)
{
    for (int i = 1; i < map->height - 1; i++) {
        for (int j = 1; j < map->length - 1; j++) {
            map->map[i][j] = is_ennemy(map, i, j);
        }
    }
    return map;
}
