/*
** EPITECH PROJECT, 2023
** count e f c
** File description:
** sources
** int flagschecker(char flag, va_list arg);
*/

#include <stdio.h>
#include "my.h"
#include <stdarg.h>

int count_rec_base(unsigned long nb, char const *base, int count)
{
    int sbase = my_strlen(base);

    if (nb < 1){
        return 0;
    } else {
        count = count_rec_base(nb / sbase, base, count) + 1;
        return count;
    }
}

int my_putnbr_base_count(unsigned long nb, char const *base)
{
    int count = 0;

    if (nb < 0){
        nb = nb * - 1;
        count++;
    }
    count = count_rec_base(nb, base, count);
    return count;
}

int my_sci_count(double num, int prec, int isneg)
{
    int i;
    int count;
    int expcount = my_int_counter(exponent(num, 0));

    if (expcount == 1) {
        expcount++;
    }
    if (num < 0) {
        num *= -1;
        my_sci_count(num, prec, 1);
    } else {
        for (i = 0; num > 10; i++) {
            num /= 10;
        }
        count = my_count_float(num, prec) + isneg;
        return count + 2 + expcount;
    }
}

int my_count_float(double nb, int prec)
{
    unsigned long long bef_p;
    long long intnb = (long long)nb;
    int count = my_int_counter(intnb) + prec;

    if (prec > 0) {
        count++;
    }
    return count;
}

int adjustwidth(int width, char flag, int prec, va_list Warg)
{
    char adj = ' ';

    if (flag == 'c') {
        for (int i = 0; i < (width - 1); i++){
            my_putchar(adj);
        }
        va_arg(Warg, void *);
        return width - 1;
    }
    if (flag == 'd' || flag == 'i') {
        return addthiccness(width - my_int_counter(va_arg(Warg, int)), adj);
    }
    if (flag == 'e' || flag == 'E') {
        return addthiccness(width - my_sci_count(va_arg(Warg, double),
        prec, 0), adj);
    }
    if (flag == 'o' || flag == 'x' || flag == 'X') {
        return conversionwidth(flag, Warg, prec, width);
    }
    return adjustwidth2(width, flag, prec, Warg);
}
