/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** error_handling
*/

#include "../include/matchstick.h"

int vrf_line(matchstick_t *game, char *str)
{
    game->line = my_getnbr(str);
    if (game->line == 0 || game->line > game->size) {
        my_putstr("Error: this line is out of range\n");
        return (1);
    }
    if (game->line == -1) {
        my_putstr("Error: invalid input (positive number expected)\n");
        return (1);
    }
    return (0);
}

int vrf_matches(matchstick_t *game, char *str)
{
    game->match = my_getnbr(str);
    if (game->match == 0) {
        my_putstr("Error: you have to remove at least one match\n");
        return (1);
    }
    if (game->match > game->matches) {
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr(game->matches);
        my_putstr(" matches per turn\n");
        return (1);
    }
    if (game->match == -1) {
        my_putstr("Error: invalid input (positive number expected)\n");
        return (1);
    }
    return (0);
}