/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** matchstick
*/

#include "../include/matchstick.h"

int nbr_per_line(matchstick_t *game)
{
    int len = 0;
    int i;

    for (i = 0; game->map[game->line][i] != '\0'; i++)
        if (game->map[game->line][i] == '|')
            len++;
    return (len);
}

int next(matchstick_t *game, char *str, long size)
{
    my_putstr("Matches: ");
    if (getline(&str, &size, stdin) == -1)
        return (55);
    if (str == NULL)
        return (84);
    if (vrf_matches(game, str) == 1)
        return (input_line(game));
    return (input_line_next(game));
}

int input_line_next(matchstick_t *game)
{
    if (nbr_per_line(game) > 0 && game->match <= nbr_per_line(game)) {
        my_putstr("Player removed ");
        my_put_nbr(game->match);
        remove_matches_map(game);
        my_putstr(" match(es) from line ");
        my_put_nbr(game->line);
        my_putchar('\n');
    } else {
        my_putstr("Error: not enough matches on this line\n");
        return (0);
    }
}

int input_line(matchstick_t *game)
{
    char *str = '\0';
    unsigned long size = 0;

    my_putstr("Line: ");
    if (getline(&str, &size, stdin) == -1)
        return (55);
    if (str == NULL)
        return (84);
    if (vrf_line(game, str) == 1)
        return (input_line(game));
    return (next(game, str, size));
}

int matchstick(matchstick_t *game)
{
    int turn = 0;
    int i = 0;

    game->map = gen_map(game);
    while (turn < 20) {
        display_map(game);
        my_putstr("Your turn:\n");
        i = input_line(game);
        if (i == 84)
            return (84);
        if (i == 55)
            return (0);
        display_map(game);
        lost(game);
        if (game->exit != 0)
            break;
        turn++;
    }
    return (game->exit);
}