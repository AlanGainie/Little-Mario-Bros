/*
** EPITECH PROJECT, 2023
** MY_COUNTCHAR
** File description:
** Comptes les char
*/

#include <stdlib.h>
#include "my.h"

char **my_countchar(char *str, char **tab)
{
    int j = my_strn(str);
    int a = 0;
    int i = my_strlen(str);
    int k = 0;
    j = my_strn(str + j + 1);
    while (i != 0) {
        if (str[i] == '\n' && a != 0){
            tab[j] = malloc(sizeof(char) * (a + 1));
            a = 0;
            j--;
        } else {
            a++;
        }
        i--;
    }
    j = my_count_word(str);
    tab[j + 1] = NULL;
    return (tab);
}
