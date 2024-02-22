/*
** EPITECH PROJECT, 2023
** functions of printf
** File description:
** sci notation sub file
*/
#include "my.h"

double scinot_div_neg(double num)
{
    while (num < 1) {
        num *= 10;
    }
    return num;
}

double scinot_div(double num)
{
    while (num > 10) {
        num /= 10;
    }
    return num;
}
