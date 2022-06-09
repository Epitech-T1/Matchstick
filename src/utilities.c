/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** utilities
*/

#include "../include/matchstick.h"

char **remove_matches_map(matchstick_t *game)
{
    for (int i = my_strlen(game->map[0]) - 1; i > 0; i--) {
        if (game->map[game->line][i] == '|') {
            game->map[game->line][i] = ' ';
            game->match--;
        }
        if (game->match == 0)
            return (game->map);
    }
}

int nbr_match(matchstick_t *game)
{
    int len = 0;

    for (int i = 1; game->map[i] != NULL; i++)
        for (int j = 0; game->map[i][j] != '\0'; j++)
            if (game->map[i][j] == '|')
                len++;
    return (len);
}