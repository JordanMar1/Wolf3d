/*
** EPITECH PROJECT, 2025
** G-ING-210-LIL-2-1-wolf3d-fabien.skotarek
** File description:
** check_map_bounds
*/

#include "../include/struct.h"
#include "../include/wolf.h"

static int look_line(char **map, int i)
{
    for (int j = 1; map[i][j + 1] != '\0'; j++) {
        if (map[i][j] == ' ' && ((int)(strlen(map[i + 1])) < j ||
            ((int)(strlen(map[i - 1]))) < j))
            return 1;
        if (map[i][j] == ' ' && map[i + 1][j] == '\0')
            return 1;
    }
    return 0;
}

static int verify_inside(char **map, int height)
{
    for (int i = 1; i < height; i++) {
        if (look_line(map, i) == 1)
            return 1;
    }
    return 0;
}

static int verify_boards(char **map, int height)
{
    int len;

    for (int i = 0; map[0][i] != '\0'; i++) {
        if (map[0][i] != 'W')
            return 1;
    }
    for (int i = 0; map[height - 1][i] != '\0'; i++) {
        if (map[height - 1][i] != 'W')
            return 1;
    }
    for (int y = 1; y < height - 1; y++) {
        len = strlen(map[y]);
        if (len < 2)
            return 1;
        if (map[y][0] != 'W' || map[y][len - 1] != 'W')
            return 1;
    }
    return verify_inside(map, height);
}

//checks if the file has correct bounds
int check_bounds(map_t *map)
{
    map_t *tmp;

    tmp = map;
    while (tmp != NULL) {
        if (verify_boards(map->map, map->height) == 1)
            return 1;
        tmp = tmp->next;
    }
    return 0;
}
