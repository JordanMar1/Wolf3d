/*
** EPITECH PROJECT, 2025
** librairy/disp
** File description:
** my_putnbr
*/

#include "../../../include/wolf.h"

int len_nb(int i)
{
    int len = 0;

    while (i > 0) {
        i /= 10;
        len++;
    }
    if (len == 0)
        return len;
    return len + 1;
}

void my_putnbr(int nb)
{
    int div = 1;

    if (nb < 0) {
        my_putchar('-');
        my_putnbr(nb * -1);
        return;
    }
    if (len_nb(nb) == 0) {
        my_putchar('0');
        return;
    }
    while (nb / div >= 10)
        div *= 10;
    while (div > 0) {
        my_putchar((nb / div) % 10 + '0');
        div /= 10;
    }
}
