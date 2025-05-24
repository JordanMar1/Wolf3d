/*
** EPITECH PROJECT, 2024
** my_rev_array
** File description:
** reverts elements of an array
*/

#include "array.h"

void my_rev_array(char **arr)
{
    char *word;
    int i = 0;
    int len = 0;

    for (len; arr[len] != NULL; len++);
    while (i != len / 2) {
        word = arr[len - i];
        arr[len - i] = arr[i];
        arr[i] = word;
        i++;
    }
}

void my_rev_int_array(char *arr)
{
    int word;
    int i = 0;
    int len = 0;

    for (len; arr[len] != NULL; len++);
    while (i != len / 2) {
        word = arr[len - i];
        arr[len - i] = arr[i];
        arr[i] = word;
        i++;
    }
}
