/*
** EPITECH PROJECT, 2023
** printf
** File description:
** project of CPool
** int flagschecker(char flag, va_list arg);
*/

#include <stdio.h>
#include "my.h"
#include <stdarg.h>
#include <stdlib.h>

int lookahead(const char *format, int i)
{
    int units_nb = 0;
    int prec = 0;
    int temp;

    for (i; format[i] >= '0' && format[i] <= '9'; i++) {
        units_nb++;
    }
    i -= units_nb;
    for (units_nb; units_nb != 0; units_nb--) {
        prec = prec * 10 + (format[i] - 48);
        i++;
        if (format[i] > 57 || format[i] < 48) {
            return prec;
        }
    }
}

int indexlevel(const char *format, int i)
{
    int c = format[i];

    if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z')) {
        for (i; (c < 'a' || c > 'z') && (c < 'A' || c > 'Z'); i++) {
            c = format[i];
        }
    } else {
        i++;
    }
    return i;
}

int thiccness(int width, char flag, va_list Warg, int prec)
{
    if (width != 0) {
        return adjustwidth(width, flag, prec, Warg);
    } else {
        va_arg(Warg, void *);
        return 0;
    }
}

int sub_myprintf(const char *format, int *package, va_list arg, va_list Warg)
{
    int width;
    int *tab_prec = malloc(sizeof(int) * 2);
    int i = package[0] + 1;
    int count = package[1];
    int minus_symbol = (format[i] == '-');

    if (format[i] == '-' || format[i] == '+' || format[i] == ' '
    || format[i] == '0' || format[i] == '#') {
        i += symbols(format, i);
        count += symbols(format, i);
    }
    width = lookahead(format, i);
    tab_prec = precision(format, i, tab_prec);
    i = indexlevel(format, i) - 1;
    count += (minus_symbol == 1) ? 0 :
    thiccness(width, format[i], Warg, tab_prec[0]);
    count += flagschecker(format[i], arg, tab_prec, count);
    count += (minus_symbol == 0) ? 0 :
    thiccness(width, format[i], Warg, tab_prec[0]);
    return count;
}

int my_printf(const char *format, ...)
{
    unsigned int count = 0;
    va_list arg;
    va_list Warg;
    int package[2];

    va_start(arg, format);
    va_copy(Warg, arg);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] != '%') {
            my_putchar(format[i]);
            count++;
            continue;
        }
        package[0] = i;
        package[1] = count;
        count = sub_myprintf(format, package, arg, Warg);
        i = indexlevel(format, i) - 1;
    }
    va_end(arg);
    return count;
}
