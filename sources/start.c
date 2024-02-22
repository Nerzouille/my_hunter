/*
** EPITECH PROJECT, 2023
** wind start
** File description:
** wind my hunter
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "../include/my.h"
#include "game.h"

int mousevent(sfEvent event, struct game *game,
    sfVector2f spritepos, struct menu *menu)
{
    int col = 0;

    if (event.type == sfEvtMouseMoved) {
        game->cursx = event.mouseMove.x;
        game->cursy = event.mouseMove.y;
    }
    if (event.type == sfEvtMouseButtonPressed) {
        if (game->cursx <= spritepos.x + 284
        && game->cursx >= spritepos.x
        && game->cursy <= spritepos.y + 136
        && game->cursy >= spritepos.y) {
            col = 1;
            spritepos.x = -20;
        }
        return bouton_menu(col, menu, game);
    }
}

int draw_menu(struct menu *menu, sfSprite *bg, sfRenderWindow *wind)
{
    sfRenderWindow_clear(wind, sfBlack);
    sfRenderWindow_drawSprite(wind, bg, NULL);
    sfRenderWindow_drawSprite(wind, menu->slogo, NULL);
    sfRenderWindow_drawSprite(wind, menu->sstart, NULL);
    sfRenderWindow_display(wind);
}

int func(struct game *game, struct menu *menu, sfEvent event)
{
    if (game->scene == 0)
        menu->starting = mousevent(event, game, menu->spritepos, menu);
    return 0;
}

int closer(sfEvent event, sfRenderWindow *wind)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(wind);
    return 0;
}

int start(sfRenderWindow *wind, sfEvent event,
    sfSprite *bg, struct game *game)
{
    struct menu menu = {.spritepos = {555, 413}, .logpos = {410, 120}};

    menu.starting = 0;
    init_menu(&menu);
    game->cursx = event.mouseMove.x;
    game->cursy = event.mouseMove.y;
    while (sfRenderWindow_isOpen(wind)) {
        draw_menu(&menu, bg, wind);
        while (sfRenderWindow_pollEvent(wind, &event)) {
            closer(event, wind);
            func(game, &menu, event);
        }
        if (menu.starting == 1) {
            sfRenderWindow_clear(wind, sfBlack);
            break;
        }
    }
    destroy_men(&menu);
    player(wind, event, game);
}
