/*
** EPITECH PROJECT, 2022
** MY
** File description:
** emacs
*/

#include <stdarg.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#ifndef MY_H_
#define MY_H_

#define MILLION = 1000000.0f;
typedef struct intarray
{
    unsigned int col;
    unsigned int ligne;
} intarray_t;

typedef struct sprite
{
    char *picture;
    sfVector2f position;
    sfVector2f decoupage;
    sfIntRect rect;
    sfClock *clock;

} sprite_t;

int my_putchar(char c);
int my_put_nbr(int nb);
int my_conv_flags(const char format, va_list list);
char **array_dup(char **src);
int array_size(char **array);
int my_count_word(char *str);
char **my_countchar(char *str, char **tab);
int my_disp_flags(const char format, va_list list);
int my_fake_flags(const char format, va_list list);
int my_fake_flags01(const char format, va_list list);
int my_fake_flags02(const char format, va_list list);
int my_fake_flags03(const char format, va_list list);
int my_getnbr(char const *str);
int my_printf(const char *format, ...);
int my_putfloat(float f, int precision);
int my_putnbr_base(int nbr, char const *base);
int my_putstr(char const *str);
char *my_sort_word_array(char *tab);
char **my_str_to_word_array(char *str);
int **my_strarray_to_int_array(intarray_t *intarray, char **str);
char *my_strcat(char *dest, char const *src);
char **my_strconcat(char *str);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);
int my_strn(char const *str);
char *my_strncpy(char *dest, char const *src, int n);
int my_swap(int *a, int *b);
float volume(float vol);
sfSprite *createSprite(sfVector2f setPossition, char *img, sfVector2f setScale, sfIntRect setRect);
int window(void);

#endif
