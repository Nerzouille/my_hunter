/*
** EPITECH PROJECT, 2023
** my_strstr
** File description:
** task05 of Day6
*/

#include "my.h"

int my_len(char const *str)
{
    int index;

    for (index = 0; str[index] != '\0'; index++);
    return (index);
}

int haystack(char *str, char const *to_find, int CharAt)
{
    for (int find_index = 0; to_find[find_index] != '\0'; find_index++) {
        if (str[CharAt] == to_find[find_index]) {
            CharAt++;
        } else {
            return (0);
        }
    }
    return (1);
}

int sub_strstr(char *str, char const *to_find, int i)
{
    if (str[i] == to_find[0]) {
        if (haystack(str, to_find, i) == 1) {
            return (1);
        }
    }
}

char *my_strstr(char *str, char const *to_find)
{
    int str_length = my_len(str);
    int to_find_len = my_len(to_find);

    if (str_length == 0 || str_length < to_find_len) {
        return ('\0');
    }
    if (to_find_len == 0) {
        return (str);
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (sub_strstr(str, to_find, i) == 1) {
            return (&(str[i]));
        }
    }
    return ('\0');
}
