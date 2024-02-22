/*
** EPITECH PROJECT, 2023
** my_strcat
** File description:
** Task2 of Day7
*/

char *my_strcat(char *dest, char const *src)
{
    int i = 0;

    for (i; dest[i] != '\0'; i++);
    for (int j = 0; src[j] != '\0'; j++) {
        dest[i + j] = src[j];
    }
    return (dest);
}
