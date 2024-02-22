/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "../include/my.h"
#include "game.h"

int help_txt(void)
{
    char *help_t = "Introducing the my_hunter project,\nAn"
    " interactive game where entities traverse the screen,"
    "\nChallenging you to swiftly click and shoot them before they"
    " reach the end,\nReminiscent of the gameplay in Dunk Hunt.\n";

    my_putstr(help_t);
    return 0;
}

int args(int argc, char **argv, struct game *game)
{
    if (argc == 2 && (my_strcmp("-h", argv[1]) == 0)) {
        help_txt();
        return 0;
    }
    if (argc == 2 && (my_strcmp("-d", argv[1]) == 0)) {
        game->dbg = 1;
        return 0;
    }
    if (argc == 3 && ((my_strcmp("-h", argv[1]) == 0
    || my_strcmp("-h", argv[2]) == 0) && (my_strcmp("-d", argv[1]) == 0
    || my_strcmp("-d", argv[2]) == 0))) {
        help_txt();
        game->dbg = 1;
        return 0;
    }
    return 0;
}

int main(int argc, char **argv)
{
    struct game game = {.bg_path = "sources/im/bg.png", .dbg = 0, .scene = 0};
    sfVideoMode mode = {1280, 720, 32};
    sfRenderWindow *wind = sfRenderWindow_create(mode,
    "Dunk Hunt", sfResize | sfClose, 0);
    sfTexture *bg = sfTexture_createFromFile(game.bg_path, 0);
    sfSprite *bg_sprite = sfSprite_create();
    sfEvent event;

    args(argc, argv, &game);
    sfRenderWindow_setFramerateLimit(wind, 60);
    sfSprite_setTexture(bg_sprite, bg, sfFalse);
    sfSprite_setScale(bg_sprite, (sfVector2f){1.76, 1.76});
    start(wind, event, bg_sprite, &game);
    sfTexture_destroy(bg);
    sfRenderWindow_destroy(wind);
    return 0;
}
