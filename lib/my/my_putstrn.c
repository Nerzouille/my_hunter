/*
** EPITECH PROJECT, 2023
** my_putstrn
** File description:
** my_putstrn
*/

#include <unistd.h>
#include "my.h"

int my_putstrn(char const *str, int n)
{
    int i = 0;
    int count = 0;

    for (i; str[i] != '\0' && i < n; i++) {
        my_putchar(str[i]);
        count ++;
    }
    return count;
}
