/*
** EPITECH PROJECT, 2023
** int counter
** File description:
** counter of int
*/

int my_int_counter(int nb)
{
    if (nb < 0) {
        nb *= -1;
        return 1 + my_int_counter(nb);
    }
    if (nb < 10) {
        return 1;
    } else {
        return 1 + my_int_counter(nb / 10);
    }
}
