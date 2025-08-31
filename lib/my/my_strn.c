/*
** EPITECH PROJECT, 2023
** MY_STRN
** File description:
** Boucle comptant le nombre de '\n'
*/

int my_strn (char const *str)
{
    int n = 0;
    while (str[n] != '\n') {
        n++;
    }
    return (n);
}
