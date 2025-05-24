/*
** EPITECH PROJECT, 2025
** disp
** File description:
** my_putstrerr
*/

#include <unistd.h>

void my_putstrerr(char *error_message)
{
    write(2, error_message, my_strlen(error_message));
}
