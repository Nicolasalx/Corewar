/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** is_empty_line
*/

#include "asm.h"

bool is_empty_line(char *str)
{
    int nb_word = count_nb_word(str, " \t\n");

    if (nb_word == 0) {
        return true;
    }
    return false;
}
