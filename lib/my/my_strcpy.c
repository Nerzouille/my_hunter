/*
** EPITECH PROJECT, 2023
** my_strcpy
** File description:
** Task01 of Day6
*/

#include "my.h"

int leonard(char const *str)
{
    int index;

    for (index = 0; str[index] != '\0'; index++);
    return (index);
}

char *my_strcpy(char *dest, char const *src)
{
    for (int i = 0; i < leonard(src); i++) {
        dest[i] = src[i];
    }
    dest[leonard(src)] = '\0';
    return (dest);
}
