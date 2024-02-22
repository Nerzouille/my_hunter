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

static int death(struct anima *an, struct play *play)
{
    if (sfSprite_getPosition(an->sprite).x >= 1200) {
        play->death = 1;
    }
}

int sprite_mov(struct anima *an)
{
    if (an->rect.left >= 400) {
        an->rect.left = 0;
        an->rect.top += an->rect.height;
        if (an->rect.top >= 600) {
            an->rect.top = 400;
        }
    }
}

int anim_anim(struct anima *an, struct play *play)
{
    an->time = sfClock_getElapsedTime(an->timer);
    an->second = an->time.microseconds / 10000;
    if (an->life == 0) {
        an->life = 1;
        an->speed = m_random(play->sp_min, play->sp_max);
        sfSprite_move(an->sprite, (sfVector2f){
            (sfSprite_getPosition(an->sprite).x + 200) * -1,
            m_random(-sfSprite_getPosition(an->sprite).y,
            520 - sfSprite_getPosition(an->sprite).y)});
    }
    if (an->second > 10) {
        sfClock_restart(an->timer);
        an->rect.left += an->rect.width;
        sfSprite_move(an->sprite, (sfVector2f){an->speed, 0});
    }
    sprite_mov(an);
    death(an, play);
}

int anim(struct play *play, sfRenderWindow *wind)
{
    anim_anim(play->a, play);
    if (play->score >= 5)
        anim_anim(play->b, play);
    if (play->death == 1) {
        sfRenderWindow_clear(wind, sfBlack);
        return 1;
    }
    return 0;
}
