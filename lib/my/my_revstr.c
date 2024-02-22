/*
** EPITECH PROJECT, 2023
** my_revstr
** File description:
** Task03 of Day6
*/

#include "my.h"

char *my_revstr(char *str)
{
    int right = my_strlen(str) - 1;
    int temp;

    for (int index = 0; index < right; index++){
        temp = str[index];
        str[index] = str[right];
        str[right] = temp;
        right--;
    }
    return (str);
}
