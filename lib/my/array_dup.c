/*
** EPITECH PROJECT, 2023
** B-PSU-200-REN-2-1-minishell1-yaouen.le-danvic
** File description:
** array_copy
*/

#include <stdlib.h>
#include "my.h"

char **array_dup(char **src)
{
    char **dest = NULL;
    int len = 0;
    if(src == NULL)
        return (NULL);
    len = array_size(src);
    dest = malloc(sizeof(char*) * (len + 1));
    for(int i = 0; i < len; i++){
        dest[i] = malloc(sizeof(char) * (my_strlen(src[i]) + 1));
        dest[i] = my_strcpy(dest[i], src[i]);
        dest[i][my_strlen(src[i])] = '\0';
    }
    dest[len] = NULL;
    return (dest);
}
