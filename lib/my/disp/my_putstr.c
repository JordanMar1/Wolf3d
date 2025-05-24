/*
** EPITECH PROJECT, 2025
** lib
** File description:
** my_putstr
*/

#include "../../../include/wolf.h"
#include <unistd.h>

void my_putstr(char *str)
{
    if (str)
        write(1, str, my_strlen(str));
}
