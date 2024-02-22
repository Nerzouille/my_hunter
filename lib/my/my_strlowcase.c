/*
** EPITECH PROJECT, 2023
** my_strlowcase
** File description:
** Task09 of Day6
*/

char *my_strlowcase(char *str)
{
    for (int letter = 0; str[letter] != '\0'; letter++){
        if (str[letter] >= 'A' && str[letter] <= 'Z' ){
            str[letter] = str[letter] + 32;
        }
    }
    return (str);
}
