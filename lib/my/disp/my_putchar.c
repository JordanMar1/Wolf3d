/*
** EPITECH PROJECT, 2025
** lib
** File description:
** disp_functions
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
