/*
** EPITECH PROJECT, 2022
** aux.c
** File description:
** aux
*/
#include "../../include/my_ls.h"
int counter_function(char *str)
{
    int counter = 0; int i = 0;
    while (str[i] != '\0') {
        counter++; i++;
    }
    return counter;
}
