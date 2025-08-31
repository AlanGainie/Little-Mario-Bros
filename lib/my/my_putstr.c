/*
** EPITECH PROJECT, 2022
** MY_PUTSTR
** File description:
** Permet d'afficher une chaine de caractère
*/

void my_putchar (char c);

int my_putstr(char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
}
