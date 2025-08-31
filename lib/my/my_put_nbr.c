/*
** EPITECH PROJECT, 2022
** MY_PUT_NBR
** File description:
** Fonction qui affiche un nombre
*/

void my_putchar(char c);

int my_put_nbr(int nb)
{
    int i = 1;

    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    while ((nb / i) >= 10) {
        i = i * 10;
    }
    while (i > 0) {
        my_putchar((nb / i) % 10 + '0');
        i = i / 10;
    }
}
