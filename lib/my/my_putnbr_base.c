/*
** EPITECH PROJECT, 2022
** my_put_nbr_base.c
** File description:
** first attempt
*/

#include "../../include/my.h"

int my_putnbr_base(int nbr, char const *base)
{
    int base_div = my_strlen(base);
    int nbr2;
    int count;
    if (nbr == 0) {
        count += my_put_nbr(0);
        return count;
    }
    if (nbr < 0) {
        my_putchar('-');
        nbr *= -1;
    }
    nbr2 = nbr % base_div;
    nbr /= base_div;
    if (nbr >= base_div)
        count += my_putnbr_base(nbr, base);
    if (nbr < base_div)
        count += my_putchar(base[nbr]);
    count += my_putchar(base[nbr2]);
    return count;
}
