/*
** EPITECH PROJECT, 2022
** my_printf.c
** File description:
** first try of printf
*/

#include <stdarg.h>
#include "../../include/my.h"

int my_printf(const char *format, ...)
{
    int count = 0;
    int i = 0;
    va_list list;
    va_start(list, format);
    while (format[i] != '\0') {
        if (format[i] == '%') {
            i ++;
            count += my_conv_flags(format[i], list);
            count += my_disp_flags(format[i], list);
            count += my_fake_flags(format[i], list);
        } else {
            my_putchar(format[i]);
            count++;
            }
        i ++;
    }
    va_end(list);
    return count;
}
