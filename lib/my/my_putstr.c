/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** main.c
*/

#include "../../include/my.h"

int my_putstr(char const *str)
{
    int z = 0;

    while (str[z] != '\0') {
        my_putchar(str[z]);
            z = z + 1;
    }
    return (0);
}