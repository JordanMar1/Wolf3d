/*
** EPITECH PROJECT, 2025
** string
** File description:
** my_rev_str
*/

#include "../../../include/wolf.h"

char *my_rev_str(char *str)
{
    int first_u = 0;
    int len = my_strlen(str);
    char keeper;
    int last_u;
    int occ = 1;

    while (first_u < len / 2) {
        keeper = str[first_u];
        last_u = len - occ;
        str[first_u] = str[last_u];
        str[last_u] = keeper;
        first_u++;
        occ++;
    }
    return (str);
}
