/*
** EPITECH PROJECT, 2023
** my_strncpy
** File description:
** Task02 of Day6
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    for (i; i < n; i++) {
        if (src[i] == '\0') {
            dest[i] = '\0';
            return (dest);
        }
        dest[i] = src[i];
    }
    return (dest);
}
