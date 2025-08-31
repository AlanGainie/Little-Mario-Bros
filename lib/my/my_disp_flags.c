/*
** EPITECH PROJECT, 2022
** my_mini_printf.c
** File description:
** final try
*/
#include "../../include/my.h"
#include <stdarg.h>
#include <stdio.h>

int my_disp_flags(const char format, va_list list)
{
    int count = 0;
    switch (format) {
    case 's': count += my_putstr(va_arg(list, char *));
        break;
    case 'i': count += my_put_nbr(va_arg(list, int));
        break;
    case 'c': count += my_putchar(va_arg(list, int));
        break;
    case 'd': count += my_put_nbr(va_arg(list, int));
        break;
    case '%': count += my_putchar('%');
        break;
    case 'n': int *nb = va_arg(list, int *);
        *nb = count;
    }
    return count;
}
