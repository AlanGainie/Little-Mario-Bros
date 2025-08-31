/*
** EPITECH PROJECT, 2022
** MY_COUNT_WORD
** File description:
** Comptes les '\n'
*/

int my_count_word(char *str)
{
    int word = 0;
    int i = 0;
    while (str[i] != '\0'){
        if (str[i] == '\n' && str[i] == ' ')
            word++;
        i++;
    }
    return (word - 1);
}
