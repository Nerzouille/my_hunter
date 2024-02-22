/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** my_putstr
*/

#include <unistd.h>
#include "my.h"

int my_putstr(char const *str)
{
    for (int index = 0; str[index] != '\0'; index++) {
        my_putchar(str[index]);
    }
}
