/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** kill_all_dead_champion
*/

#include "op.h"
#include "my_importall.h"
#include "corewar.h"

static void kill_dead_champion(int i)
{
    if (head_all_champion[i] == NULL) {
        return;
    }
    if (ref_champion[i].alive) {
        ref_champion[i].alive = 0;
    } else {
        last_champion_killed = i;
        free_linked_list(&head_all_champion[i]);
    }
}

void kill_all_dead_champion(void)
{
    for (int i = 0; i < nb_champion; ++i) {
        kill_dead_champion(i);
    }
}
