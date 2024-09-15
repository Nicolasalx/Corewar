/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** set_cooldown_next_instruction
*/

#include "corewar.h"
#include "my_importall.h"
#include "op.h"

void set_cooldown_next_instruction(champion_t *champion)
{
    if (not is_instruction_exist(GET_DATA(champion->pc_ptr, core_t)->data)) {
        return;
    }
    champion->cooldown = op_tab[
        GET_DATA(champion->pc_ptr, core_t)->data - 1].nbr_cycles;
}
