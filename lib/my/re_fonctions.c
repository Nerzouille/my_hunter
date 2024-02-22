/*
** EPITECH PROJECT, 2023
** functions of printf
** File description:
** eh voui garcon
*/
#include "my.h"

int addthiccness(int diff, char adjuster)
{
    for (int i = 0; i < diff; i++) {
        my_putchar(adjuster);
    }
    return diff;
}

int exponent(double num, int addminus)
{
    int i = 0;

    if (num < 0) {
        num *= -1;
    }
    if (addminus == 0) {
        for (i; num > 10; i++) {
            num /= 10;
        }
    } else {
        for (i; num < 1; i++) {
            num *= 10;
        }
    }
    return i;
}

int my_put_sci(char flag, int nb, int exp, int addminus)
{
    int count = 0;

    my_putchar(flag);
    if (addminus == 1) {
        my_putchar('-');
    } else {
        my_putchar('+');
    }
    if (exp < 10) {
        my_putchar('0');
        my_put_nbr(exp);
        count += 2;
    } else {
        my_put_nbr(exp);
        count++;
    }
    return 2 + count;
}

int sci_notation(double num, int prec, char flag, int nb)
{
    int count;
    int isneg = 0;
    double intactnum = num;
    int addminus = 0;

    if (num < 0) {
        my_putchar('-');
        num *= -1;
        isneg = 1;
    }
    if (num < 1) {
        addminus = 1;
        num = scinot_div_neg(num);
    } else {
        num = scinot_div(num);
    }
    count = my_put_float(num, prec) + isneg;
    count += my_put_sci(flag, nb, exponent(intactnum, addminus), addminus);
    return count;
}

int my_flag_putstr(char const *str, int prec)
{
    int index = 0;

    for (index; str[index] != '\0'
    && index < prec; index++) {
        my_putchar(str[index]);
    }
    return index;
}
