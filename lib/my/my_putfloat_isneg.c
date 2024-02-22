/*
** EPITECH PROJECT, 2023
** my put float
** File description:
** my put float
*/

#include "my.h"
#include <stdio.h>
#include <stdlib.h>

int putfloat_isneg(double *nb, long long *intnb, long double *decnb)
{
    if (*nb < 0) {
        my_putchar('-');
        *nb *= -1;
        *intnb *= -1;
    }
    *decnb = *nb - *intnb;
}
