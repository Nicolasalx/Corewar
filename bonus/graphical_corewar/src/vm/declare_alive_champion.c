/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** declare_alive_champion
*/

#include "corewar.h"
#include "my_importall.h"

void declare_alive_champion(void)
{
    for (int i = 0; i < nb_champion; ++i) {
        if (head_all_champion[i] != NULL) {
            print("The player ", INT(ref_champion[i].num),
            "(", ref_champion[i].header.prog_name, ")is alive.\n");
        }
    }
}
