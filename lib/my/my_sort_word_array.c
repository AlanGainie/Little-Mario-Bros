/*
** EPITECH PROJECT, 2022
** MY_SORT_WORD_ARRAY
** File description:
** Lis un des char et les transforme en pointeur de pointeur
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "../../include/my.h"

char *my_sort_word_array (char *tab)
{
    struct stat stats;
    int size = 0;
    char *buffer = NULL;
    int f;
    char *str;
    f = open(tab, O_RDONLY);
    if (f == -1)
        return (NULL);
    if (stat(tab, &stats) == -1)
        return (NULL);
    size = stats.st_size;
    buffer = malloc(sizeof(char) * size + 1);
    read(f, buffer, size);
    if (buffer == NULL){
        free (buffer);
        return (NULL);
    }
    close(f);
    buffer[size] = '\0';
    return (buffer);
}
