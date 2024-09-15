/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** update_champion_pc
*/

#include "corewar.h"
#include "my_importall.h"
#include "op.h"

void update_champion_pc(champion_t *champion, inst_t *instruction)
{
    champion->pc_ptr = pc_arithm(champion->pc_ptr, instruction->size);
    champion->pc = GET_DATA(champion->pc_ptr, core_t)->address;
}
