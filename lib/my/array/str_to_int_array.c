/*
** EPITECH PROJECT, 2024
** str_to_int_array
** File description:
** converts a string to an ASCII int array and the invert
*/

#include "array.h"

int my_len_int_array(int *x)
{
    int i = 0;

    while (x[i] != NULL) {
        i++;
    }
    return i;
}

int *str_to_int_array(char *str)
{
    int *arr = malloc(sizeof(int) * strlen(str) + 1);
    int i;

    if (arr == NULL)
        return NULL;
    for (i = 0; str[i] != '\0'; i++) {
        arr[i] = (int)str[i];
    }
    arr[i] = NULL;
    return arr;
}

char *int_array_to_str(int *tab)
{
    char *str = malloc(sizeof(char) * my_len_int_array(tab));
    int i = 0;

    if (!str)
        return NULL;
    for (i; tab[i] != NULL; i++) {
        str[i] = (char)tab[i];
    }
    return str;
}
