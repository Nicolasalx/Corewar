/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** my_live
*/

#include "my_importall.h"
#include "op.h"
#include "corewar.h"

void my_live(champion_t *champion, inst_t *instruction)
{
    if (not is_valid_instruction_arg(instruction)) {
        return;
    }
    if (ref_champion[champion->champion_index].num == instruction->arg[0]) {
        ++ ref_champion[champion->champion_index].alive;
    }
    if (instruction->arg[FIRST_ARG] >= 0
        && instruction->arg[FIRST_ARG] < nb_champion) {
        ++ ref_champion[instruction->arg[FIRST_ARG]].alive;
    }
}
