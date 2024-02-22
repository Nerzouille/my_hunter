/*
** EPITECH PROJECT, 2023
** my_put_nbr
** File description:
** my_put_nbr
*/

#include <unistd.h>
#include "my.h"

int recursive(int n)
{
    int n2;

    if (n < 10) {
        my_putchar(48 + n);
    } else {
        n2 = n / 10;
        recursive(n2);
        n = n % 10;
        my_putchar(48 + n);
    }
}

int my_put_nbr(int nb)
{
    int fix_out_of_range = 0;

    if (nb < 0) {
        if (nb == -2147483648) {
            fix_out_of_range = 1;
            nb = nb / 10;
        }
        nb = nb * -1;
        my_putchar(45);
    }
    recursive(nb);
    if (fix_out_of_range == 1) {
        my_putchar(56);
    }
}
