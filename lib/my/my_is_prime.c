/*
** EPITECH PROJECT, 2023
** my_is_prime
** File description:
** Task06 of Day5
*/
#include <unistd.h>

int my_is_prime(int nb)
{
    if (nb < 2) {
        return (0);
    }
    if (nb == 2 || nb == 3 || nb == 5) {
        return (1);
    }
    for (int prime_test = 2; prime_test <= 3; prime_test++) {
        if ((nb % prime_test) == 0) {
            return (0);
        }
    }
    if ((nb % 5) == 0) {
        return (0);
    }
    return (1);
}
