/*
** EPITECH PROJECT, 2023
** my put float
** File description:
** my put float
*/

#include "my.h"
#include <stdio.h>
#include <stdlib.h>

unsigned long long *tab_assign(unsigned long long *tab_dec,
    int perm_prec, unsigned long long dec)
{
    tab_dec[2] = 0;
    if (my_ull_counter(dec) > perm_prec) {
        dec = 0;
        tab_dec[2] = 1;
    }
    tab_dec[0] = dec;
    tab_dec[1] = my_ull_counter(dec);
    return tab_dec;
}

unsigned long long *extract_dec(int prec, long double decnb,
    int count, unsigned long long *tab_dec)
{
    unsigned long long dec;
    unsigned long long dec2;
    int perm_prec = prec;

    while (prec > 0) {
        decnb *= 10;
        dec = (unsigned long long)decnb;
        dec2 = (unsigned long long)(decnb * 10) - dec * 10;
        if (dec2 > 4 && prec == 1) {
            dec += 1;
        }
        prec--;
    }
    tab_dec = tab_assign(tab_dec, perm_prec, dec);
    return tab_dec;
}

void tab_dec_go(unsigned long long *tab_dec, int prec, int prec2)
{
    if (tab_dec[1] < prec2) {
        for (int i = 0; i < prec - tab_dec[1] ||
        tab_dec[2] == 1 && i <= prec - tab_dec[1]; i++) {
            my_putchar('0');
        }
    }
}

int isprec_sup0(int *prec2, long double *decnb, double *nb, long long *intnb)
{
    if (*prec2 > 0) {
        my_putchar('.');
        *decnb = *nb - *intnb;
    }
}

int my_put_float(double nb, int prec)
{
    unsigned long long *tab_dec = malloc(sizeof(unsigned long long) * 3);
    long long intnb = (long long)nb;
    long double decnb;
    int prec2 = prec;
    int count = my_int_counter(intnb) + prec;

    putfloat_isneg(&nb, &intnb, &decnb);
    tab_dec = extract_dec(prec, decnb, count, tab_dec);
    if (tab_dec[2] == 1) {
        intnb++;
        prec--;
    }
    my_put_nbr(intnb);
    isprec_sup0(&prec2, &decnb, &nb, &intnb);
    tab_dec_go(tab_dec, prec, prec2);
    if (prec2 > 0) {
        my_put_ull(tab_dec[0]);
        count++;
    }
    return count;
}
