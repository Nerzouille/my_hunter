/*
** EPITECH PROJECT, 2023
** flags
** File description:
** flags file for myprintf
*/

#include <stdio.h>
#include "my.h"
#include <stdarg.h>

int flags_conversions(char flag, va_list arg, int *prec, int count)
{
    int *ptr;

    if (flag == 'o') {
        return my_putnbr_base(va_arg(arg, int), "01234567");
    }
    if (flag == 'X') {
        return my_putnbr_base(va_arg(arg, int), "0123456789ABCDEF");
    }
    if (flag == 'x') {
        return my_putnbr_base(va_arg(arg, int), "0123456789abcdef");
    }
    if (flag == 'f' || flag == 'F') {
        return my_put_float(va_arg(arg, double), prec[0]);
    }
    if (flag == 'p') {
        ptr = va_arg(arg, void *);
        return my_print_pointer(ptr);
    }
    return (flag_char(flag, arg, prec));
}

int flagschecker4(char flag, va_list arg, int *prec, int count)
{
    int c1;
    int c2;
    int nb;
    double num;

    if (flag == 'c') {
        return flag_char(flag, arg, prec);
    }
    if (flag == 'G'){
        num = va_arg(arg, double);
        c1 = my_sci_count(num, prec[0], 0);
        c2 = my_count_float(num, prec[0]);
        if (c1 < c2) {
            return sci_notation(num, prec[0], 'E', nb);
        }
        return my_put_float(num, prec[0]);
    }
    return (flags_conversions(flag, arg, prec, count));
}

int flagschecker3(char flag, va_list arg, int *prec, int count)
{
    int c1;
    int c2;
    int nb;
    double num;

    if (flag == 'g'){
        num = va_arg(arg, double);
        c1 = my_sci_count(num, prec[0], 0);
        c2 = my_count_float(num, prec[0]);
        if (c1 < c2) {
            return sci_notation(num, prec[0], 'e', nb);
        }
        return my_put_float(num, prec[0]);
    }
    if (flag == 'n') {
        *(va_arg(arg, int *)) = count;
    }
    return (flagschecker4(flag, arg, prec, count));
}

int flagschecker2(char flag, va_list arg, int *prec, int count)
{
    int nb;
    double num;

    if (flag == '%') {
        my_putchar('%');
        return 1;
    }
    if (flag == 'e' || flag == 'E') {
        return sci_notation(va_arg(arg, double), prec[0], flag, nb);
    }
    if (flag == 'u') {
        nb = (va_arg(arg, int));
        my_put_nbr_unsigned(nb);
        return my_int_counter(nb);
    }
    return (flagschecker3(flag, arg, prec, count));
}

int flagschecker(char flag, va_list arg, int *prec, int count)
{
    char *str;
    int nb;

    if (flag == 'i' || flag == 'd') {
        nb = (va_arg(arg, int));
        my_put_nbr(nb);
        return my_int_counter(nb);
    }
    if (flag == 's') {
        str = va_arg(arg, char *);
        if (prec[1] == 1) {
            return my_putstrn(str, prec[0]);
        } else {
            my_putstr(str);
            return my_strlen(str);
        }
    }
    return (flagschecker2(flag, arg, prec, count));
}
