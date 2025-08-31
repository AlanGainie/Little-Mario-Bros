/*
** EPITECH PROJECT, 2022
** my_flags_conv.c
** File description:
** flags to convert
*/

#include "../../include/my.h"
#include <stdarg.h>
#include <stdio.h>

int my_conv_flags(const char format, va_list list)
{
    int count = 0;
    char *str;
    switch (format) {
    case 'x': count += my_putnbr_base(va_arg(list, int), "0123456789abcdef");
        break;
    case 'X': count += my_putnbr_base(va_arg(list, int), "0123456789ABCDEF");
        break;
    case 'p' : count += my_putstr("0x");
        count += my_putnbr_base(va_arg(list, long int), "0123456789abcdef");
        break;
    case 'f': count += my_putfloat(va_arg(list, double), 5);
        break;
    case 'b': count += my_putnbr_base(va_arg(list, int), "01");
        break;
    case 'o': count += my_putnbr_base(va_arg(list, int), "01234567");
        break;
    case 'u': count+= my_put_nbr(va_arg(list, int));
        break;
    }
    return count;
}
