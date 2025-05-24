/*
** EPITECH PROJECT, 2025
** wolf3dwactest
** File description:
** give_data
*/

#include "../include/struct.h"
#include "../include/wolf.h"

// gives elements to data's structures
void give_data(data_t *data, char **object, sfRenderWindow *window)
{
    if (!object || !data)
        return;
    if (strcmp(object[0], "map") == 0)
        add_map(object, data);
    if (strcmp(object[0], "weapon") == 0)
        add_weapon(object, data, window);
}
