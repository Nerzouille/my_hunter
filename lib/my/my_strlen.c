/*
** EPITECH PROJECT, 2023
** my_strlen
** File description:
** my_strlen
*/

#include <unistd.h>

int my_strlen(char const *str)
{
    int index;

    for (index = 0; str[index] != '\0'; index++);
    return (index);
}
