/*
** EPITECH PROJECT, 2023
** MY_STR_TO_WORD_ARRAY
** File description:
** Lis un des char et les transforme en pointeur de pointeur
*/

#include <unistd.h>
#include <stdlib.h>
#include "../../include/my.h"

char **my_str_to_word_array(char *str)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int len = my_count_word(str);
    char **stock = malloc(sizeof(char*) * (len + 2));
    stock = my_countchar(str, stock);
    for (k; str[k] != '\n'; k++);
    k++;
    while (str[k] != '\0'){
        if (str[k] == '\n'){
            stock[i][j] = '\0';
            i++;
            j = 0;
            k++;
            continue;
        } stock[i][j] = str[k];
        j++;
        k++;
    }
    return (stock);
}
