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
#include <time.h>

int anima(struct anima *an)
{
    an->id = 'a';
    an->fiposition = (sfVector2f){0, 250};
    an->texture = sfTexture_createFromFile("./sources/im/fred_s.png", NULL);
}

int animb(struct anima *an)
{
    an->id = 'b';
    an->fiposition = (sfVector2f){640, 50};
    an->texture = sfTexture_createFromFile("./sources/im/foxy_s.png", NULL);
}

void def_anima(struct anima *an, struct play *play)
{
    if (play->nb_anim == 0)
        anima(an);
    if (play->nb_anim == 1)
        animb(an);
    an->speed = 15;
    an->sprite = sfSprite_create();
    sfSprite_setTexture(an->sprite, an->texture, sfTrue);
    sfSprite_setScale(an->sprite, (sfVector2f){0.75, 0.75});
    sfSprite_setPosition(an->sprite, an->fiposition);
    an->timer = sfClock_create();
    an->time = sfClock_getElapsedTime(an->timer);
    an->rect = (sfIntRect){0, 400, 200, 200};
    an->life = 1;
    play->nb_anim++;
}

int speedy_a(struct play *play)
{
    if (play->score == 40) {
        play->sp_min = 40;
        play->sp_max = 55;
    }
    if (play->score == 45) {
        play->sp_min = 55;
        play->sp_max = 65;
    }
    if (play->score == 50) {
        play->sp_min = 70;
        play->sp_max = 85;
    }
    if (play->score == 60) {
        play->sp_min = 100;
        play->sp_max = 110;
    }
}

int speed_a(struct play *play)
{
    if (play->score == 5) {
        if (play->fred_pres == 0) {
            play->fred_pres = 1;
            play->b = malloc(sizeof(struct anima) * 1);
            def_anima(play->b, play);
        }
        play->sp_min = 16;
        play->sp_max = 35;
    }
    if (play->score == 10) {
        play->sp_min = 20;
        play->sp_max = 35;
    }
    if (play->score == 30) {
        play->sp_min = 25;
        play->sp_max = 40;
    }
    speedy_a(play);
}
