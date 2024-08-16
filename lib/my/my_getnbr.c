/*
** EPITECH PROJECT, 2022
** my_getnbr.c
** File description:
** funcion which
*/

#include <stdio.h>

int my_getnbr(char const *str)
{
    int i = 0;
    int neg = 1;
    long num = 0;
    while (str[i] == '+' || str[i] == '-')
        neg *= str[i++] == '+' ? 1 : -1;
    while (str[i] != '\0'){
        if (str[i] > 47 && str[i] < 58){
            num = num * 10 + str[i] - 48;
        } else {
            break;
        }
        i++;
    }
    if (num < -2147483648 || num > 2147483647){
        return 0;
    }
    return num * neg;
}

/*
 * while body
        if (str[i] == '+' || str[i] == '-'){
            neg *= str[i] == '+' ? 1 : -1;
        } else if (str[i] > 47 && str[i] < 58){
            num = num * 10 + str[i] - 48;
        } else {
            break;
        }
        i++;
*/
/*
int main (void)
{
    char *str1 = "42";
    char *str2 = "+---+--++---+---+---+-42";
    char *str3 = "42a43";
    char *str4 = "11000000000000000000000042";
    char *str5 = "-1000000000000000000000042";
    printf("%d\n", my_getnbr(str1));
    printf("%d\n", my_getnbr(str2));
    printf("%d\n", my_getnbr(str3));
    printf("%d\n", my_getnbr(str4));
    printf("%d\n", my_getnbr(str5));
}
*/
