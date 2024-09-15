/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** check_dead_champion
*/

#include "op.h"
#include "my_importall.h"
#include "corewar.h"

bool check_dead_champion(int *check_alive, int *nb_live)
{
    if (cycle_to_die < 0) {
        return true;
    }
    if (*check_alive >= cycle_to_die) {
        kill_all_dead_champion();
        declare_alive_champion();
        if (no_champion_is_alive() || only_one_champion_left()) {
            return true;
        }
        *check_alive = 0;
        -- *nb_live;
        if (*nb_live < 0) {
            cycle_to_die -= CYCLE_DELTA;
        }
    }
    ++ *check_alive;
    return false;
}
