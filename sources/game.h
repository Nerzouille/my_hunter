/*
** EPITECH PROJECT, 2023
** struct game
** File description:
** game files struc and fonctions
*/

#include <SFML/Graphics.h>
#include <stdio.h>
#include <SFML/Audio.h>
#include "../include/my.h"

#ifndef STRUC_H_
    #define STRUC_H_

    #include <sys/stat.h>

struct game{
    int scene;
    int dbg;
    int cursx;
    int cursy;
    char *bg_path;
};

struct menu{
    sfSoundBuffer *buffer;
    sfSound *sound;
    sfTexture *start;
    sfSprite *sstart;
    sfTexture *logo;
    sfSprite *slogo;
    sfVector2f spritepos;
    sfVector2f logpos;
    int starting;
};

struct anima{
    char id;
    float wtime;
    sfVector2f fiposition;
    int speed;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f position;
    sfClock *timer;
    sfTime time;
    float second;
    sfIntRect rect;
    int life;
};

struct play{
    int hs;
    int nb_anim;
    int fred_pres;
    int score;
    int sp_min;
    int sp_max;
    int speed_ed;
    int death;
    sfFont *font;
    sfText *text;
    sfSoundBuffer *buffer;
    sfSound *sound;
    sfTexture *bg;
    sfSprite *bg_sprite;
    struct anima *a;
    struct anima *b;
};

struct finish{
    int end;
    sfSoundBuffer *buffer;
    sfSound *sound;
    sfTexture* texture;
    sfSprite* sprite;
    sfClock *timer;
    sfTime time;
    sfIntRect rect;
    sfVector2u texture_size;
    float second;
};

struct score{
    int end;
    sfFont *font;
    sfText *text;
    sfText *texths;
    sfSoundBuffer *buffer;
    sfSound *sound;
    sfTexture* texture;
    sfSprite* sprite;
};

int rbs(struct play *play);
int wbs(struct play *play);
char *string_score(int score);
char *string_fscore(char *str, char *nbr);
int m_random(int min, int max);
int anim(struct play *play, sfRenderWindow *wind);
void def_anima(struct anima *an, struct play *play);
int speed_a(struct play *play);
int closer(sfEvent event, sfRenderWindow *wind);
int player(sfRenderWindow *wind, sfEvent event, struct game *game);
int destroy_men(struct menu *menu);
int bouton_menu(int col, struct menu *menu, struct game *game);
int init_menu(struct menu *menu);
int run_wind(sfRenderWindow *wind, sfEvent event,
    sfSprite *bg, struct game *game);
int start(sfRenderWindow *wind, sfEvent event,
    sfSprite *bg, struct game *game);
int finish(sfRenderWindow *wind, sfEvent event,
    struct game *game, struct play *play);
int score(sfRenderWindow *wind, sfEvent event,
    struct game *game, struct play *play);

#endif /* !STRUC_H_ */
