/*
** EPITECH PROJECT, 2022
** MY_GETNBR
** File description:
** Permet de passer d'un nombre sous la forme d'un char a un int
*/

#include <stdio.h>

int my_getnbr(char const *str)
{
    int i = 0;
    int nbr = 0;
    int is_neg = 0;

    if (str[i] == '-') {
    is_neg = 1;
    i++;
    }
    while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9')) {
    nbr += str[i] -48;
    nbr *= 10;
    i++;
    }
    nbr /= 10;
    return (is_neg == 1 ? -nbr : nbr);
}
