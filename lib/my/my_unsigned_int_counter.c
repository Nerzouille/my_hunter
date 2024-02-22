/*
** EPITECH PROJECT, 2023
** unsigned int counter
** File description:
** counter of unsigned int
*/

int my_unsigned_int_counter(unsigned int nb)
{
    if (nb < 0) {
        nb *= -1;
        return 1 + my_unsigned_int_counter(nb);
    }
    if (nb < 10) {
        return 1;
    } else {
        return 1 + my_unsigned_int_counter(nb / 10);
    }
}
