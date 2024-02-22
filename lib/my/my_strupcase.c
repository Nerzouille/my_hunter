/*
** EPITECH PROJECT, 2023
** my_strupcase
** File description:
** task08 of Day6
*/

char *my_strupcase(char *str)
{
    for (int letter = 0; str[letter] != '\0'; letter++){
        if (str[letter] >= 'a' && str[letter] <= 'z' ){
            str[letter] = str[letter] - 32;
        }
    }
    return (str);
}
