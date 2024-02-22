/*
** EPITECH PROJECT, 2023
** my_strcapitalize
** File description:
** Task10 of Day6
*/

#include "my.h"

char lwrcs(char *str, int i)
{
    if (str[i + 1] >= 'A' && str[i + 1] <= 'Z') {
        str[i + 1] += 32;
    }
    if (str[i - 1] >= 'a' && str[i - 1] <= 'z') {
        str[i] += 32;
    }
}

char notaletter(char *str, int i)
{
    if (str[i] >= '0' && str[i] <= '9') {
        if (str[i + 1] >= 'A' && str[i + 1] <= 'Z') {
            str[i + 1] += 32;
        }
    } else if (str[i + 1] >= 'a' && str[i + 1] <= 'z') {
        str[i + 1] -= 32;
    }
}

char *my_strcapitalize(char *str)
{
    if (str[0] >= 'a' && str[0] <= 'z') {
        str[0] -= 32;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 'A' || str[i] > 'Z' && str[i] < 'a' || str[i] > 'z') {
            notaletter(str, i);
        }
        if (str[i] >= 'A' && str[i] <= 'Z') {
            lwrcs(str, i);
        }
    }
    return (str);
}
