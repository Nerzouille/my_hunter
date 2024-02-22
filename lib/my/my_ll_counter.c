/*
** EPITECH PROJECT, 2023
** int counter
** File description:
** counter of int
*/

int my_ll_counter(long long nb)
{
    if (nb < 0) {
        nb *= -1;
        return 1 + my_ll_counter(nb);
    }
    if (nb < 10) {
        return 1;
    } else {
        return 1 + my_ll_counter(nb / 10);
    }
}
