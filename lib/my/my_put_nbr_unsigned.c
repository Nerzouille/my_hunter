/*
** EPITECH PROJECT, 2023
** my put nbr unsigned
** File description:
** my put nbr unsigned
*/

#include <unistd.h>
#include "my.h"

int recursive_u(unsigned int n)
{
    unsigned int n2;

    if (n < 10) {
        my_putchar(48 + n);
    } else {
        n2 = n / 10;
        recursive_u(n2);
        n = n % 10;
        my_putchar(48 + n);
    }
}

int my_put_nbr_unsigned(unsigned int nb)
{
    if (nb < 0) {
        nb = 4294967295 + nb;
    }
    recursive_u(nb);
}
