/*
** EPITECH PROJECT, 2022
** compares.c
** File description:
** compares.c
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "../../include/my.h"

int compare1(char a, va_list l, int n, char *s)
{
    int m = 0; int c = pre_hag(s, a); pre_space(s, a);
    int z = pre_zero(s, a); int e = pre_num(s, a);
    int pos = pre_pos(s, a); int p = pre_pre(s, a); int num;
    switch (a) {
        case 'd': case 'i':
            m = va_arg(l, int); n += my_put_nbr(m, e, z, pos);
            break;
        case 'u':
            printf("u\n");
            num = va_arg(l, int);
            if (num < 0) {
                n += my_putstr("4294962729");
            } else {
                n += my_put_nbr_u(num, e, z, pos);
            }
            break;
        default:
            n = compare2(a, l, n, s); break;
    }
    return n;
}

int compare2(char a, va_list list, int n, char *s)
{
    double numf = 0;
    int z = pre_zero(s, a);
    int e = pre_num(s, a); int pos = pre_pos(s, a);
    int p = pre_pre(s, a); int sp = pre_space(s, a);
    switch (a) {
        case 'e':
            numf = va_arg(list, double);
            n += my_put_exp(numf);
            break;
        case 'E':
            numf = va_arg(list, double);
            n += my_put_exp_may(numf);
            break;
        default:
            n = compare3(a, list, n, s);
            break;
    }
    return n;
}

int compare3(char a, va_list list, int n, char *s)
{
    double numf = 0.0;
    int z = pre_zero(s, a);
    int e = pre_num(s, a); int pos = pre_pos(s, a);
    int p = pre_pre(s, a); int sp = pre_space(s, a);
    switch (a) {
        case 'g':
            numf = va_arg(list, double);
            n += my_put_float_exp(numf, s, a);
            break;
        case 'G':
            numf = va_arg(list, double);
            n += my_put_float_exp_may(numf, s, a);
            break;
        default:
            n = compare4(a, list, n, s);
            break;
    }
    return n;
}

int compare4(char a, va_list list, int n, char *s)
{
    char *str; int z = pre_zero(s, a);
    int e = pre_num(s, a); int pos = pre_pos(s, a);
    int p = pre_pre(s, a); int sp = pre_space(s, a);
    switch (a) {
        case 'c':
            my_putchar(va_arg(list, int)); n++;
            break;
        case 's':
            str = va_arg(list, char *);
            if (str == NULL) {
                n += my_putstr("(null)");
            } else {
                n += my_putstr(str);
            }
            break;
        default:
            n  = compare5(a, list, n, s); break;
    }
    return n;
}

int compare5(char a, va_list list, int n, char *s)
{
    int num = 0; char *str; int *pointer;
    int z = pre_zero(s, a);
    int e = pre_num(s, a); int po = pre_pos(s, a);
    int p = pre_pre(s, a); int sp = pre_space(s, a);
    switch (a) {
        case 'p':
            num = va_arg(list, long int); pointer = &num;
            my_putstr("0x");
            my_put_hexa(my_getnbr(pointer), z, e, po);
            break;
        case 'n':
            pointer = malloc(sizeof(int *));
            *pointer = va_arg(list, int); pointer = &n;
            break;
        default:
            n = compare6(a, list, n, s);
            break;
    }
    return n;
}
