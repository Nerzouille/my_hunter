/*
** EPITECH PROJECT, 2023
** print pointer
** File description:
** print adresse pointer
** int flagschecker(char flag, va_list arg);
*/

#include <unistd.h>
#include <stdio.h>
#include "my.h"

int my_print_pointer(void *ptr)
{
    my_putstr("0x");
    return my_putnbr_base(ptr, "0123456789abcdef") + 2;
}
