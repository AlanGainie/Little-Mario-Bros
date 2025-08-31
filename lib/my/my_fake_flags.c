/*
** EPITECH PROJECT, 2022
** my_fake_flags.c
** File description:
** all non existants one
*/
#include "../../include/my.h"

int my_fake_flags(const char format, va_list list)
{
    int count = 0;
    count += my_fake_flags01(format, list);
    count += my_fake_flags02(format, list);
    count += my_fake_flags03(format, list);
}

int my_fake_flags01(const char format, va_list list)
{
    int count = 0;
    switch (format) {
    case 'r': count += my_putchar('%');
        count += my_putchar('r');
        break;
    case 'R': count += my_putchar('%');
        count += my_putchar('R');
        break;
    case 'T': count += my_putchar('%');
        count += my_putchar('T');
        break;
    case 'y': count += my_putchar('%');
        count += my_putchar('y');
        break;
    case 'Y': count += my_putchar('%');
        count += my_putchar('Y');
        break;
    }
    return count;
}

int my_fake_flags02(const char format, va_list list)
{
    int count = 0;
    switch (format) {
    case 'u': count += my_putchar('%');
        count += my_putchar('u');
        break;
    case 'Q': count += my_putchar('%');
        count += my_putchar('Q');
        break;
    case 'H': count += my_putchar('%');
        count += my_putchar('H');
        break;
    case 'J': count += my_putchar('%');
        count += my_putchar('J');
        break;
    case 'k': count += my_putchar('%');
        count += my_putchar('k');
        break;
    }
    return count;
}

int my_fake_flags03(const char format, va_list list)
{
    int count = 0;
    switch (format) {
    case 'K': count += my_putchar('%');
        count += my_putchar('K');
        break;
    case 'M': count += my_putchar('%');
        count += my_putchar('M');
        break;
    case 'w': count += my_putchar('%');
        count += my_putchar('w');
        break;
    case 'W': count += my_putchar('%');
        count += my_putchar('W');
        break;
    case 'v': count += my_putchar('%');
        count += my_putchar('v');
        break;
    }
    return count;
}
