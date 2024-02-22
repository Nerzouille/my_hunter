/*
** EPITECH PROJECT, 2023
** width
** File description:
** width
*/

#include "my.h"

int my_intcomp(int nb1, int nb2)
{
    if (nb1 > nb2) {
        return nb2;
    } else if (nb1 <= nb2) {
        return nb1;
    }
}

int my_count_pointer(void *ptr)
{
    return my_putnbr_base_count((unsigned long)ptr, "0123456789abcdef") + 2;
}

int conversionwidth(char flag, va_list Warg, int prec, int width)
{
    if (flag == 'o') {
        return addthiccness(width - my_putnbr_base_count(va_arg(Warg, int),
        "012345678"), ' ');
    }
    if (flag == 'x') {
        return addthiccness(width - my_putnbr_base_count(va_arg(Warg, int),
        "0123456789abcdef"), ' ');
    }
    if (flag == 'X') {
        return addthiccness(width - my_putnbr_base_count(va_arg(Warg, int),
        "0123456789ABCDEF"), ' ');
    }
    return 0;
}

int adjustwidth2(int width, char flag, int prec, va_list Warg)
{
    if (flag == 'p') {
        return addthiccness(width -
        my_count_pointer(va_arg(Warg, void *)), ' ');
    }
    if (flag == 's') {
        return addthiccness(width -
        my_intcomp(my_strlen(va_arg(Warg, char *)), prec), ' ');
    }
    if (flag == 'u') {
        return addthiccness(width -
        my_unsigned_int_counter(va_arg(Warg, unsigned int)), ' ');
    }
    if (flag == 'f' || flag == 'F') {
        return addthiccness(width -
        my_count_float(va_arg(Warg, double), prec), ' ');
    }
    return 0;
}
