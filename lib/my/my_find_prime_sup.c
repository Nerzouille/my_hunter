/*
** EPITECH PROJECT, 2023
** my_find_prime_sup
** File description:
** Task07 of Day5
*/
#include "my.h"

int my_find_prime_sup(int nb)
{
    for (nb; my_is_prime(nb) == 0; nb++);
    return nb;
}
