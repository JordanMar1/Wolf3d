/*
** EPITECH PROJECT, 2025
** G-ING-210-LIL-2-1-wolf3d-fabien.skotarek
** File description:
** get_name
*/

#include "../include/wolf.h"

// getenv for file's content
char *get_name(char *elem, char **content)
{
    for (int i = 0; content[i] != NULL; i++) {
        if (strcmp(content[i], elem) == 0)
            return content[i + 1];
    }
    return NULL;
}
