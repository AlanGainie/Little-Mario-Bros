/*
** EPITECH PROJECT, 2022
** my_putfloat2.c
** File description:
** putfloat third try
*/

#include <stdio.h>
#include "../../include/my.h"

long long int my_compute_power_it(int nb, int p)
{
    long long int powered = 1;
    if (p < 0) {
        powered = 0;
    }
    while (p != 0) {
        powered *= nb;
        p --;
    }
    return powered;
}

int  my_putfloat(float f, int precision)
{
    int count = 0;
    int intpart = f;
    long long int powered = my_compute_power_it(10, precision);
    long long int  decipart = (f - intpart) * powered;
    if (f < 0) {
        my_putchar('-');
        count ++;
        intpart *= -1;
        decipart *= -1;
    }
    count += my_put_nbr(intpart);
    my_putchar('.');
    count ++;
    count += my_put_nbr(decipart);
    return count;
}
