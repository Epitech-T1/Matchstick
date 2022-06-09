/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** matchstick
*/

#ifndef MATCHSTICK_H_
#define MATCHSTICK_H_

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "my.h"

typedef struct matchstick
{
    char **map;
    int matches;
    int size;
    int match;
    int line;
    int exit;
    int rm_mat;
} matchstick_t;

void display_map(matchstick_t *game);
char **gen_map(matchstick_t *game);
int matchstick(matchstick_t *game);
int vrf_line(matchstick_t *game, char *str);
int vrf_matches(matchstick_t *game, char *str);
int ia_turn(matchstick_t *game);
int nbr_per_line(matchstick_t *game);
int nbr_match(matchstick_t *game);
void lost(matchstick_t *game);
char **remove_matches_map(matchstick_t *game);

#endif /* !MATCHSTICK_H_ */
