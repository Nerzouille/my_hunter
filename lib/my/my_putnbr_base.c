/*
** EPITECH PROJECT, 2023
** my put nbr base
** File description:
** my put nbr base
*/

#include "my.h"

int rec_base(long long nb, char const *base, int count)
{
    int sbase = my_strlen(base);

    if (nb < 1){
        return 0;
    } else {
        count = rec_base(nb / sbase, base, count) + 1;
        my_putchar(base[nb % sbase]);
        return count;
    }
}

int my_putnbr_base(long long nb, char const *base)
{
    int count = 0;

    if (nb < 0){
        my_putchar('-');
        nb = nb * - 1;
        count++;
    }
    count = rec_base(nb, base, count);
    return count;
}
