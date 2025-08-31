/*
** EPITECH PROJECT, 2022
** MY_SWAP
** File description:
** ce programme inverse les valeurs des pointeurs
*/

int my_swap (int *a, int *b)
{
    int val;
    val = *a;

    int val2;
    val2 = *b;

    *b = val;
    *a = val2;
    return (0);
}
