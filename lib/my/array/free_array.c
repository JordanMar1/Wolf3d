/*
** EPITECH PROJECT, 2029
** count_words
** File description:
** free array
*/

#include <stdlib.h>

void free_array(char **arr)
{
    if (!arr)
        return;
    for (int i = 0; arr[i] != NULL; i++) {
        free(arr[i]);
    }
    free(arr);
}

void free_int_array(int *arr)
{
    if (!arr)
        return;
    free(arr);
}
