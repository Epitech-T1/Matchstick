/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** map
*/

#include "../include/matchstick.h"

void display_map(matchstick_t *game)
{
    for (int i = 0; game->map[i] != NULL; i++) {
        my_putstr(game->map[i]);
        my_putchar('\n');
    }
    my_putchar('\n');
    return;
}

void gen_map_next(matchstick_t *game, int x, int y)
{
    int k;

    for (k = 0; y <= game->size; k++) {
        x = (game->size - k);
        for (;x < (game->size * 2); x++) {
            if (x < (game->size + k + 1))
                game->map[y][x] = '|';
        }
        y++;
    }
}

char **gen_map(matchstick_t *game)
{
    int x = 0;
    int y = 1;
    int j;

    for (int i = 0; i != (game->size + 2); i++) {
        for (j = 0; j != (game->size * 2 + 1); j++) {
            if (i == 0 || i == game->size + 1)
                game->map[i][j] = '*';
            else {
                game->map[i][j] = ' ';
                game->map[i][0] = '*';
                game->map[i][game->size * 2] = '*';
            }
        }
        game->map[i][j] = '\0';
    }
    gen_map_next(game, x, y);
    return (game->map);
}