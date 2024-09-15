/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** is_champion_alive
*/

#include "op.h"
#include "my_importall.h"
#include "corewar.h"

bool no_champion_is_alive(void)
{
    for (int i = 0; i < nb_champion; ++i) {
        if (head_all_champion[i] != NULL) {
            return false;
        }
    }
    return true;
}

bool only_one_champion_left(void)
{
    int nb_champion_alive = 0;

    for (int i = 0; i < nb_champion; ++i) {
        if (head_all_champion[i] != NULL) {
            ++ nb_champion_alive;
        }
    }
    if (nb_champion_alive > 1) {
        return false;
    }
    for (int i = 0; i < nb_champion; ++i) {
        if (head_all_champion[i] != NULL) {
            last_champion_killed = i;
            return true;
        }
    }
    return false;
}
