/*
** EPITECH PROJECT, 2022
** MY_PUTCHAR
** File description:
** Affiche un caractère
*/

#include <unistd.h>

int my_putchar(char c)
{
    write(1, &c, 1);
}
