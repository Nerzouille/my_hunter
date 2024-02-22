/*
** EPITECH PROJECT, 2023
** socre finish
** File description:
** score my_hunter
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "../include/my.h"
#include "game.h"

int init_stxt(struct score *fin, struct play *play)
{
    fin->text = sfText_create();
    fin->texths = sfText_create();
    fin->font = sfFont_createFromFile("./sources/im/fnaf.ttf");
    sfText_setString(fin->text, string_fscore("Your score: ",
        string_score(play->score)));
    sfText_setString(fin->texths, string_fscore("Best score: ",
        string_score(play->hs)));
    sfText_setFont(fin->text, fin->font);
    sfText_setFont(fin->texths, fin->font);
    sfText_setCharacterSize(fin->text, 50);
    sfText_setCharacterSize(fin->texths, 50);
    sfText_setPosition(fin->text, (sfVector2f){250.0f, 275.0f});
    sfText_setPosition(fin->texths, (sfVector2f){250.0f, 375.0f});
}

int init_s(struct score *fin, struct play *play)
{
    sfVector2f position = {0, 0};

    if (play->score > play->hs) {
        play->hs = play->score;
        wbs(play);
    }
    fin->buffer = sfSoundBuffer_createFromFile("sources/songs/"
    "mb.ogg");
    fin->sound = sfSound_create();
    sfSound_setBuffer(fin->sound, fin->buffer);
    sfSound_setVolume(fin->sound, 25.0f);
    sfSound_play(fin->sound);
    fin->texture = sfTexture_createFromFile("./sources"
    "/im/lose.jpg", NULL);
    fin->sprite = sfSprite_create();
    sfSprite_setTexture(fin->sprite, fin->texture, sfTrue);
    sfSprite_setPosition(fin->sprite, position);
    init_stxt(fin, play);
}

int score_destroy(struct score *fin)
{
    sfSprite_destroy(fin->sprite);
    sfText_destroy(fin->text);
    sfText_destroy(fin->texths);
    sfFont_destroy(fin->font);
    sfTexture_destroy(fin->texture);
    sfSound_destroy(fin->sound);
    sfSoundBuffer_destroy(fin->buffer);
}

static int spacebar(sfEvent event, struct score *fin)
{
    if (event.key.code == sfKeySpace)
        fin->end = 1;
}

int score(sfRenderWindow *wind, sfEvent event,
    struct game *game, struct play *play)
{
    struct score fin = {.end = 0};

    init_s(&fin, play);
    while (sfRenderWindow_isOpen(wind)) {
        sfRenderWindow_clear(wind, sfBlack);
        sfRenderWindow_drawSprite(wind, fin.sprite, NULL);
        sfRenderWindow_drawText(wind, fin.text, NULL);
        sfRenderWindow_drawText(wind, fin.texths, NULL);
        sfRenderWindow_display(wind);
        while (sfRenderWindow_pollEvent(wind, &event)) {
            closer(event, wind);
            spacebar(event, &fin);
        }
        if (fin.end == 1)
            break;
    }
    score_destroy(&fin);
}
