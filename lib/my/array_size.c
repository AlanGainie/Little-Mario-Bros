/*
** EPITECH PROJECT, 2023
** B-PSU-200-REN-2-1-minishell1-yaouen.le-danvic
** File description:
** array_size
*/

#include <stdlib.h>
#include "my.h"

int array_size(char **array)
{
    int size = 0;
    for(; array[size] != NULL; size++);
    return(size);
}