/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** main
*/

#include "../include/matchstick.h"

matchstick_t *init_struct(void)
{
    matchstick_t *game = malloc(sizeof(matchstick_t));

    game->matches = 0;
    game->size = 0;
    game->map = NULL;
    game->exit = 0;
    return (game);
}

int check(int argc, char **argv, matchstick_t *game)
{
    int mal = 0;

    if (argc != 3)
        return (84);
    game->size = my_getnbr(argv[1]);
    game->matches = my_getnbr(argv[2]);
    mal = game->size * 2;
    if (game->size < 2 || game->size > 99)
        return (84);
    if (game->matches < 1)
        return (84);
    game->map = malloc(sizeof(char *) * (game->size + 23));
    for (int i = 0; i < game->size + 3; i++)
        game->map[i] = malloc(sizeof(char) * (mal + 3));
    game->map[game->size + 2] = NULL;
    matchstick(game);
    return (game->exit);
}

int main(int ac, char **av)
{
    matchstick_t *game = init_struct();

    return (check(ac, av, game));
}