/*
** EPITECH PROJECT, 2025
** G-ING-210-LIL-2-1-wolf3d-fabien.skotarek
** File description:
** my_len_arr
*/

#include <stddef.h>

int my_len_arr(char **arr)
{
    int i = 0;

    if (!arr)
        return 0;
    for (; arr[i] != NULL; i++);
    return i;
}
