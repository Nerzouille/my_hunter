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

int m_random(int min, int max)
{
    int randint = rand();

    return (randint % (max - min) + min);
}

int p_mousevent(sfEvent event, struct game *game,
    struct anima *an, struct play *play)
{
    sfVector2f spritepos = sfSprite_getPosition(an->sprite);

    if (event.type == sfEvtMouseMoved) {
        game->cursx = event.mouseMove.x;
        game->cursy = event.mouseMove.y;
    }
    if (event.type == sfEvtMouseButtonPressed) {
        if (game->cursx <= spritepos.x + 200
        && game->cursx >= spritepos.x
        && game->cursy <= spritepos.y + 200
        && game->cursy >= spritepos.y) {
            an->life = 0;
            play->score++;
        }
    }
    speed_a(play);
}

static int init_p(struct play *play)
{
    play->buffer = sfSoundBuffer_createFromFile("sources/songs"
    "/fnaf.ogg");
    play->sound = sfSound_create();
    sfSound_setBuffer(play->sound, play->buffer);
    sfSound_setVolume(play->sound, 25.0f);
    play->bg = sfTexture_createFromFile("./sources/im/bgame.jpg", 0);
    play->bg_sprite = sfSprite_create();
    play->a = malloc(sizeof(struct anima) * 1);
    def_anima(play->a, play);
    play->text = sfText_create();
    play->font = sfFont_createFromFile("./sources/im/fnaf.ttf");
    sfText_setString(play->text, string_score(play->score));
    sfText_setFont(play->text, play->font);
    sfText_setCharacterSize(play->text, 50);
    sfText_setPosition(play->text, (sfVector2f){10.0f, 10.0f});
    sfSprite_setTexture(play->bg_sprite, play->bg, sfFalse);
    sfSprite_setScale(play->bg_sprite, (sfVector2f){1, 1});
    sfSound_play(play->sound);
}

static void des_anima(struct anima *an)
{
    an->texture = sfTexture_createFromFile("./sources/im/fred_s.png", NULL);
    an->sprite = sfSprite_create();
}

static int destroy_p(struct play *play)
{
    sfSound_destroy(play->sound);
    sfSoundBuffer_destroy(play->buffer);
    sfText_destroy(play->text);
    sfFont_destroy(play->font);
    sfTexture_destroy(play->bg);
    des_anima(play->a);
    if (play->score >= 5)
        des_anima(play->b);
}

static int draw_p(struct play *play, sfRenderWindow *wind)
{
    sfSprite_setTextureRect(play->a->sprite, play->a->rect);
    if (play->score >= 5)
        sfSprite_setTextureRect(play->b->sprite, play->b->rect);
    sfRenderWindow_clear(wind, sfBlack);
    sfRenderWindow_drawSprite(wind, play->bg_sprite, NULL);
    sfRenderWindow_drawSprite(wind, play->a->sprite, NULL);
    if (play->score >= 5)
        sfRenderWindow_drawSprite(wind, play->b->sprite, NULL);
    sfRenderWindow_drawText(wind, play->text, NULL);
    sfRenderWindow_display(wind);
}

int lunch_p_mousevent(struct play *play, sfEvent event, struct game *game)
{
    p_mousevent(event, game, play->a, play);
        if (play->score >= 5)
            p_mousevent(event, game, play->b, play);
}

int player(sfRenderWindow *wind, sfEvent event, struct game *game)
{
    struct play play = {.death = 0, .score = 0, .speed_ed = 0,
    .sp_min = 12, .sp_max = 30, .nb_anim = 0, .fred_pres = 0};

    rbs(&play);
    init_p(&play);
    srand((unsigned int)time(NULL));
    while (sfRenderWindow_isOpen(wind)) {
        sfText_setString(play.text, string_score(play.score));
        draw_p(&play, wind);
        while (sfRenderWindow_pollEvent(wind, &event)) {
            closer(event, wind);
            lunch_p_mousevent(&play, event, game);
        }
        if (anim(&play, wind) == 1)
            break;
    }
    destroy_p(&play);
    finish(wind, event, game, &play);
}
