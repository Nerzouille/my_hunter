/*
** EPITECH PROJECT, 2023
** my_compute_square_root
** File description:
** Task05 of Day5
*/
#include "my.h"

int test_special_cases(int nb)
{
    if (nb <= 0) {
        return (0);
    } else if (nb == 1) {
        return (1);
    }
}

int sqroot(int nb, int test_index)
{
    while (test_index != nb) {
        if (my_compute_power_rec(test_index, 2) == nb) {
            return (test_index);
        }
        test_index++;
    }
    return (0);
}

int my_compute_square_root(int nb)
{
    int test_index = 1;

    if (nb <= 1) {
        test_special_cases(nb);
    } else {
        return (sqroot(nb, test_index));
    }
}
