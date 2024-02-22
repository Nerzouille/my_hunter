/*
** EPITECH PROJECT, 2023
** str swap
** File description:
** swap str
*/

void my_str_swap(char **a, char **b)
{
    char *temp = *a;

    *a = *b;
    *b = temp;
}
