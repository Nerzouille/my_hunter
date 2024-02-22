/*
** EPITECH PROJECT, 2023
** my get number
** File description:
** return an int based on a string
*/
#include <unistd.h>

int is_letter(char a)
{
    if (a < 48 || a > 57) {
        return 1;
    }
    return 0;
}

int test(char const *str, int i, long *nb, int *letterp)
{
    if (str[i] >= '0' && str[i] <= '9') {
            *nb *= 10;
            *nb += str[i] - '0';
            *letterp = is_letter(str[i + 1]);
        }
}

int my_getnbr(char const *str)
{
    long nb = 0;
    int i = 0;
    int letterp = 0;
    int sign = 1;

    while (str[i] != '\0' && letterp == 0) {
        if (str[i] == '-') {
            sign *= -1;
            continue;
        }
        test(str, i, &nb, &letterp);
        i++;
        if ((nb * sign < -2147483648) || (nb * sign) > 2147483647) {
            return (0);
        }
    }
    return (nb * sign);
}
