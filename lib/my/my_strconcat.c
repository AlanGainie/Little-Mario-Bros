/*
** EPITECH PROJECT, 2023
** B-PSU-200-REN-2-1-minishell1-yaouen.le-danvic
** File description:
** my_strconcat
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

/*void alpha(char *str)
{
    int i = 0;
    while(str[i]) {
        if(str[i] == )
        i++;
    }
    retrun (0);
}
*/

char **my_strconcat(char *str)
{
    int i = 0;
    int j = 0;
    char **tab = NULL;
    int count = 0;
    int len = my_strlen(str);
    tab = malloc(sizeof(char*) * (len + 1));
    for(int i = 0; i < len; i++){
        j = i;
        if(str[i] == ' ' && str[j + 1] != ' ')
            i++;
            j++;
        tab[i] = malloc(sizeof(char) * len);
    }
    while(str[i] != '\0') {
        if(str[i] == ' '){
            tab[i][j] = '\0';
            i++;
        }
        tab[i][j] = str[i];
        j++;
    }
    tab[i] = NULL;
    return (tab);
}
