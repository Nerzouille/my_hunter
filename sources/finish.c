/*
** EPITECH PROJECT, 2023
** finish game
** File description:
** wind finish my hunter
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "../include/my.h"
#include "game.h"

int init_f(struct finish *fn)
{
    sfVector2f position = {0, 0};

    fn->buffer = sfSoundBuffer_createFromFile("sources/songs/"
    "fnaf_j.ogg");
    fn->sound = sfSound_create();
    sfSound_setBuffer(fn->sound, fn->buffer);
    sfSound_setVolume(fn->sound, 65.0f);
    sfSound_play(fn->sound);
    fn->texture = sfTexture_createFromFile("./sources"
    "/im/screamer.png", NULL);
    fn->sprite = sfSprite_create();
    sfSprite_setTexture(fn->sprite, fn->texture, sfTrue);
    sfSprite_setPosition(fn->sprite, position);
    fn->timer = sfClock_create();
    fn->time = sfClock_getElapsedTime(fn->timer);
    fn->second = fn->time.microseconds / 100000;
    fn->texture_size = sfTexture_getSize(fn->texture);
    fn->rect = (sfIntRect){0, 0, fn->texture_size.x, 722};
}

int anim_f(struct finish *fn, sfRenderWindow *wind)
{
    fn->time = sfClock_getElapsedTime(fn->timer);
    fn->second = fn->time.microseconds / 10000;
    if (fn->second > 1) {
        sfClock_restart(fn->timer);
        fn->rect.left += fn->rect.width;
    }
    if (fn->rect.left >= fn->texture_size.x) {
        fn->rect.left = 0;
        fn->rect.top += fn->rect.height;
        if (fn->rect.top >= fn->texture_size.y) {
            return 1;
        }
    }
    return 0;
}

int finish(sfRenderWindow *wind, sfEvent event,
    struct game *game, struct play *play)
{
    struct finish fn = {.end = 0};

    init_f(&fn);
    while (sfRenderWindow_isOpen(wind)) {
        while (sfRenderWindow_pollEvent(wind, &event)) {
            closer(event, wind);
        }
        fn.end = anim_f(&fn, wind);
        sfSprite_setTextureRect(fn.sprite, fn.rect);
        sfRenderWindow_clear(wind, sfBlack);
        sfRenderWindow_drawSprite(wind, fn.sprite, NULL);
        sfRenderWindow_display(wind);
        if (fn.end == 1)
            break;
    }
    sfSprite_destroy(fn.sprite);
    sfTexture_destroy(fn.texture);
    score(wind, event, game, play);
}
