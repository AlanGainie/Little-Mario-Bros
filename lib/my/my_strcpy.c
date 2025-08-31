/*
** EPITECH PROJECT, 2022
** MY_STRCPY
** File description:
** Cette fonction copie une chaine de charactère puis remplace une autre avec
*/

char *my_strcpy (char *dest, char const *src)
{
    int i;

    i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
