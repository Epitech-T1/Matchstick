/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** ia
*/

#include "../include/matchstick.h"

int ia_line(matchstick_t *game)
{
    if (game->line < 1 || game->line > game->size)
        return (1);
    return (0);
}

int ia_matches(matchstick_t *game)
{
    if (game->match < 1 || game->match > game->size)
        return (1);
    if (game->match > game->rm_mat)
        return (1);
    return (0);
}

int ia_turn(matchstick_t *game)
{
    my_putstr("AI's turn...\n");
    do {
        do {
            game->line = random()/1000000;
        } while (ia_line(game) != 0);
        game->match = random()/1000000;
        game->rm_mat = nbr_per_line(game);
    } while (ia_matches(game));
    my_putstr("AI removed ");
    my_put_nbr(game->match);
    remove_matches_map(game);
    my_putstr(" match(es) from line ");
    my_put_nbr(game->line);
    my_putchar('\n');
    display_map(game);
    return (0);
}

void lost(matchstick_t *game)
{
    if (nbr_match(game) == 0) {
        my_putstr("You lost, too bad...\n");
        game->exit = 1;
        return;
    }
    ia_turn(game);
    if (nbr_match(game) == 0) {
        my_putstr("I lost... snif... but I'll get you next time!!\n");
        game->exit = 2;
        return;
    }
}