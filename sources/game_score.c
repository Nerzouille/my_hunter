/*
** EPITECH PROJECT, 2023
** wind game
** File description:
** wind my hunter
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "../include/my.h"
#include "game.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

char *string_score(int score)
{
    int temp = score;
    int nbr = temp;
    int size = 1;
    int i;
    char *number = (char *)malloc(size + 1);

    for (; temp > 0; size++)
        temp /= 10;
    if (number == NULL) {
        return NULL;
    }
    for (i = 0; i < size + 1; i++)
        number[i] = '0';
    for (i = size - 1; nbr > 0; i--) {
        number[i] = ((nbr % 10) + '0');
        nbr /= 10;
    }
    number[size] = '\0';
    return number;
}

char *string_fscore(char *str, char *nbr)
{
    char *dest = malloc(sizeof(char) * (my_strlen(str) + my_strlen(nbr)));
    int i = 0;
    int j = 0;

    for (i; str[i] != '\0'; i++)
        dest[i] = str[i];
    i = 0;
    while (str[i] != '\0')
        i++;
    while (nbr[j] != '\0') {
        dest[i] = nbr[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return dest;
}

int rbs(struct play *play)
{
    FILE *file = fopen("./sources/score/hs.txt", "r");
    char buffer[100];
    char hs[100];
    size_t bytesRead;

    if (file == NULL) {
        return 1;
    }
    bytesRead = fread(buffer, 1, sizeof(buffer), file);
    my_strncpy(hs, buffer, bytesRead);
    hs[bytesRead] = '\0';
    fclose(file);
    play->hs = my_getnbr(hs);
}

int wbs(struct play *play)
{
    FILE *file = fopen("./sources/score/hs.txt", "r+");
    char *data = string_score(play->hs);

    fwrite(data, sizeof(char), my_strlen(data), file);
}
