/*
** EPITECH PROJECT, 2022
** MY_STRLEN
** File description:
** Boucle comptant le nombre de char
*/

int my_strlen(char const *str)
{
    int len = 0;
    while (str[len] != '\0') {
        len = len +1;
    }
    return (len);
}
