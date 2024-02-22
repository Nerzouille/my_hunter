/*
** EPITECH PROJECT, 2023
** my_strncat
** File description:
** Task3 Day7
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;

    for (i; dest[i] != '\0'; i++);
    for (int j = 0; j < nb; j++) {
        dest[i + j] = src[j];
    }
    return (dest);
}
