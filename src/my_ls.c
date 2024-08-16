/*
** EPITECH PROJECT, 2022
** my_ls.c
** File description:
** my_ls
*/

#include "../include/my_ls.h"
int function(int argc, char **argv)
{
    struct dirent *pd;
    int i = 0; DIR *p; char *name;
    name = malloc(sizeof(name));
    int exist = read_name(argc, argv);
    if (exist == 1) {
        name = argv[argc - 1];
        p = opendir(name);
    } else {
        name = ".";
        p = opendir(name);
    }
    if (p == NULL) {
        my_printf("ls: %s: No such file or directory\n", name);
        return -1;
    } else {
        options(argc, argv, p, name);
    }
    closedir(p);
    return 0;
}

int read_name(int argc, char **argv)
{
    int e = 1;
    if (argv[argc - 1][0] == '-' || argc <= 1) {
        e = 0;
    }
    return e;
}

int options(int argc, char **argv, DIR *p, char *name)
{
    char *str; int n = 0; str = malloc(sizeof(str));
    int i = 0; int enc = 0; char *aux;
    while (argc > i) {
        if (argv[i][0] == '-') {
            str = options_sub2(argv[i], str, n);
            n = counter_n(str);
            enc = 1;
        }
        i++;
    }
    if (enc == 1) {
        options_sub(str,p,name);
    }
    if (enc == 0) {
        aux = malloc(sizeof(aux)); aux = "m";
        options_sub(aux,p,name);
    }
    str = my_str_abc(str); return 0;
}

char* options_sub2(char *st,char *str, int n)
{
    int i = 0;
    while (st[i] != '\0') {
        switch (st[i]) {
            case 'a': str[n] = 'a'; n++; break;
            case 'l': str[n] = 'l'; n++; break;
            case 'r': str[n] = 'r'; n++; break;
            case 'R': str[n] = 'R'; n++; break;
            case 'd': str[n] = 'd'; n++; break;
            case 't': str[n] = 't'; n++; break;
        }
        i++;
    }
    return str;
}

int options_sub(char *str, DIR *p, char *name)
{
    int i = 0; int counter = counter_function(str);
    char **s; int enc = 0; s = malloc(sizeof(str));
    while (str[i] != '\0') {
        switch (str[i]) {
            case 'a': option_a(p); break;
            case 'd': option_d(p,name); break;
            case 'l': option_l(p,name); break;
            case 'r': option_r1(p); break;
            case 'R': option_r2(p,name); break;
            case 't': option_tt(p, name); break;
            default: option_default(p); break;
        }
        i++; enc = 1;
    }
    if (enc == 0) {
        option_default(p);
    }
}
