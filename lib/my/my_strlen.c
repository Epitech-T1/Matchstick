/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** main.c
*/

#include "../../include/my.h"

int my_strlen(char const *str)
{
    int n = 0;

    while (str[n] != '\0')
        n++;
    return (n);
}

