/*
** EPITECH PROJECT, 2023
** my ull counter
** File description:
** count ull
*/

#include "my.h"

int my_ull_counter(unsigned long long nb)
{
    if (nb < 0) {
        return 1 + my_ull_counter(nb * -1);
    }
    if (nb < 10) {
        return 1;
    } else {
        return 1 + my_ull_counter(nb / 10);
    }
}
