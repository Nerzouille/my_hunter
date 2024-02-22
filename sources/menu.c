/*
** EPITECH PROJECT, 2023
** menu utilities
** File description:
** menu utilities
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "../include/my.h"
#include "game.h"

int destroy_men(struct menu *menu)
{
    sfSound_destroy(menu->sound);
    sfSoundBuffer_destroy(menu->buffer);
    sfTexture_destroy(menu->start);
    sfSprite_destroy(menu->sstart);
    sfTexture_destroy(menu->logo);
    sfSprite_destroy(menu->slogo);
}

int bouton_menu(int col, struct menu *menu, struct game *game)
{
    if (col == 1) {
        game->scene++;
        return 1;
    }
    return 0;
}

int init_menu(struct menu *menu)
{
    menu->buffer = sfSoundBuffer_createFromFile("sources/songs/whistle.ogg");
    menu->sound = sfSound_create();
    menu->start = sfTexture_createFromFile("sources/im/arrow.png", 0);
    menu->sstart = sfSprite_create();
    menu->logo = sfTexture_createFromFile("sources/im/logo.png", 0);
    menu->slogo = sfSprite_create();
    sfSound_setBuffer(menu->sound, menu->buffer);
    sfSound_setVolume(menu->sound, 25.0f);
    sfSound_play(menu->sound);
    sfSprite_setTexture(menu->sstart, menu->start, sfTrue);
    sfSprite_setTexture(menu->slogo, menu->logo, sfTrue);
    sfSprite_setScale(menu->sstart, (sfVector2f){0.6, 0.6});
    sfSprite_setScale(menu->slogo, (sfVector2f){0.6, 0.6});
    sfSprite_setPosition(menu->sstart, menu->spritepos);
    sfSprite_setPosition(menu->slogo, menu->logpos);
}
