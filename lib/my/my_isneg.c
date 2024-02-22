/*
** EPITECH PROJECT, 2023
** my_isneg
** File description:
** my_isneg
*/

#include <unistd.h>

int my_isneg(int n)
{
    if (n >= 0) {
        write(1, "P", 1);
    } else {
        write(1, "N", 1);
    }
}
