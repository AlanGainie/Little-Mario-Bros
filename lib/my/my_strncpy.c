/*
** EPITECH PROJECT, 2022
** MY_STRNCPY
** File description:
** Cette foncton copie n caractère puis le met dans une autre variable
*/

char *my_strncpy (char *dest, char const *src, int n)
{
    int i = 0;

    while (i < n && src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
