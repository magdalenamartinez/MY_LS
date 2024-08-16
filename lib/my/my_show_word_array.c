/*
** EPITECH PROJECT, 2022
** my_show_word_array.c
** File description:
** funcion which
*/

#include <stdio.h>

char *my_strdup(char const *str);
int my_strlen(char const *str);
int my_putstr(char const *str);

int  my_show_word_array(char * const * tab)
{
    char *str;
    int i = 0;

    while (tab[i] != '\0'){
        str = my_strdup(tab[i]);
        str[my_strlen(tab[i])] = '\n';
        my_putstr(str);
        i++;
    }
    return 0;
}
