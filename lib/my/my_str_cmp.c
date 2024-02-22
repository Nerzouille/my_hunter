/*
** EPITECH PROJECT, 2023
** my_str_cmp
** File description:
** cmp
*/

#include "../../include/my.h"
#include <stdlib.h>

int def_incr_str(const char *str)
{
    if (str[0] == '.') {
        return 1;
    }
    return 0;
}

int comp_strcmp_m(char *a, char *b, char *s1, char *s2)
{
    int i = def_incr_str(s1);
    int j = def_incr_str(s2);

    for (i; s1[i] != '\0' || s2[i] != '\0'; i++) {
        if (a[i] < b[j]) {
            return (-1);
        }
        if (a[i] > b[j]) {
            return (1);
        }
        j++;
    }
    return 0;
}

int my_strcmp_maj(char *s1, char *s2)
{
    char *a;
    char *b;
    int i;

    a = malloc(sizeof(char *) * my_strlen(s1));
    b = malloc(sizeof(char *) * my_strlen(s2));
    my_strcat(a, s1);
    my_strcat(b, s2);
    for (i = 0; i < my_strlen(a); i++) {
        if (a[i] <= 'Z' && a[i] >= 'A')
            a[i] += 32;
        if (b[i] <= 'Z' && b[i] >= 'A')
            b[i] += 32;
    }
    return (comp_strcmp_m(a, b, s1, s2));
}
