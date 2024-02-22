/*
** EPITECH PROJECT, 2023
** functions of printf
** File description:
** eh voui fille
*/
#include "my.h"

int flag_char(char flag, va_list arg, int *prec)
{
    if (flag == 'c') {
        my_putchar(va_arg(arg, int));
        return 1;
    }
    return 0;
}

int *precision(const char *format, int i, int *tab_prec)
{
    char c = format[i];
    int def = 1;

    for (i; (c < 'a' || c > 'z') && (c < 'A' || c > 'Z'); i++) {
        c = format[i];
        if (c == '%') {
            break;
        }
        if (c == '.') {
            def = 0;
            tab_prec[0] = lookahead(format, i + 1);
        }
    }
    if (def == 1) {
        tab_prec[0] = 6;
    } else {
        tab_prec[1] = 1;
    }
    return tab_prec;
}
