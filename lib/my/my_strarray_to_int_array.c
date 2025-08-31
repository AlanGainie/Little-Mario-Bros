/*
** EPITECH PROJECT, 2023
** MY_STR_TO_INT_ARRAY
** File description:
** Lis un des char et les transforme en pointeur de pointeur
*/

#include <unistd.h>
#include <stdlib.h>
#include "../../include/my.h"

int **my_strarray_to_int_array(intarray_t *intarray, char **str)
{
    int i = 0;
    int j = 0;
    int nbr = 0;
    int len = my_strlen(str[0]);
    int **stockint = 0;

    for (; str[nbr] != NULL; nbr++);
    intarray->col = nbr - 1;
    intarray->ligne = len;
    stockint = malloc(sizeof(int*) * nbr);
    for (i = 0; i < nbr - 1; i++){
        stockint[i] = malloc(sizeof(int) * len);
        for (j = 0; j < len; j++){
            stockint[i][j] = (str[i] != NULL && str[i][j] == '1') ? 1 : 0;
        }
    }
    return (stockint);
}
