/*
** EPITECH PROJECT, 2025
** ING
** File description:
** free_data
*/

#include "../include/wolf.h"
#include "../include/struct.h"

// frees a weapon
void free_weapon(weapon_t *weapon)
{
    weapon_t *clone;

    if (!weapon)
        return;
    while (weapon) {
        clone = weapon->next;
        free(weapon);
        weapon = clone;
    }
}

// frees a map
void free_map(map_t *map)
{
    map_t *tmp;

    while (map) {
        tmp = map;
        map = map->next;
        if (tmp->map)
            free_array(tmp->map);
        free(tmp);
    }
}

// frees an enemy
void free_enemy(enemy_t *enemy)
{
    enemy_t *tmp = NULL;

    while (enemy) {
        tmp = enemy->next;
        if (enemy->sprite)
            sfSprite_destroy(enemy->sprite);
        free(enemy);
        enemy = tmp;
    }
}

// frees data
void free_data(data_t *data)
{
    if (!data)
        return;
    if (data->enemy)
        free_enemy(data->enemy);
    if (data->map)
        free_map(data->map);
    if (data->player) {
        if (data->player->weapon)
            free_weapon(data->player->weapon);
        free(data->player);
    }
    if (data->save)
        free(data->save);
    free(data);
}
