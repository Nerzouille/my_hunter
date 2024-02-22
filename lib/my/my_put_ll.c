/*
** EPITECH PROJECT, 2023
** my put ll
** File description:
** my put ll
*/

#include <unistd.h>
#include "my.h"

int recursiveputll(long long n)
{
    int n2;

    if (n < 10) {
        my_putchar(48 + n);
    } else {
        n2 = n / 10;
        recursiveputll(n2);
        n = n % 10;
        my_putchar(48 + n);
    }
}

int my_put_ll(long long nb)
{
    if (nb < 0) {
        nb = nb * -1;
        my_putchar(45);
    }
    recursiveputll(nb);
}
