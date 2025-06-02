/*
** EPITECH PROJECT, 2025
** wolf3dwactest
** File description:
** add_map
*/

#include "../include/wolf.h"
#include "../include/struct.h"

// adds a new map to the linked list
static void add_new_map(map_t **map, map_t *new_map)
{
    map_t *tmp;

    if (!map || !new_map)
        return;
    if (!*map) {
        *map = new_map;
        return;
    }
    tmp = *map;
    while (tmp && tmp->next)
        tmp = tmp->next;
    tmp->next = new_map;
    new_map->last = tmp;
}

// inits stats from map
static void init_map_stats(map_t *map, char **object)
{
    char *content = get_name("\ncontent", object);

    if (content) {
        map->map = my_str_to_word_array(content, "\n");
        if (!map->map)
            return;
        map->height = my_len_arr(map->map);
        map->length = strlen(map->map[0]);
    }
    content = get_name("\nmusic", object);
    if (content)
        map->music = sfMusic_createFromFile(content);
}

// creates a node for the linked list
static map_t *create_map(int id, char **object)
{
    map_t *map = malloc(sizeof(map_t));

    if (!map)
        return NULL;
    map->next = NULL;
    map->last = NULL;
    map->map = NULL;
    map->music = NULL;
    map->id = id;
    init_map_stats(map, object);
    if (!map->map) {
        free_map(map);
        return NULL;
    }
    return map;
}

//adds a map to the data
void add_map(char **object, data_t *data)
{
    static int id = 0;
    map_t *new_map;

    if (!object || !data || !data->player)
        return;
    new_map = create_map(id, object);
    if (!new_map)
        return;
    add_new_map(&data->map, new_map);
    id++;
}
