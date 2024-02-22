/*
** EPITECH PROJECT, 2023
** my put unsigned long long
** File description:
** put ull
*/

#include <unistd.h>
#include "my.h"

int my_put_ull(unsigned long long nb)
{
    unsigned long long n2;
    int count = 0;

    if (nb < 10) {
        my_putchar(48 + nb);
        count++;
    } else {
        n2 = nb / 10;
        my_put_ull(n2);
        nb = nb % 10;
        my_putchar(48 + nb);
        count++;
    }
    return count;
}
