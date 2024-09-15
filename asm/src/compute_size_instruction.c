/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** compute_size_instruction
*/

#include "asm.h"

void compute_size_instruction(inst_t *instruction)
{
    instruction->size = 0;
    instruction->size += 1;
    instruction->size += instruction->has_diff_arg;
    for (int i = 0; i < instruction->nb_arg; ++i) {
        instruction->size += instruction->size_arg[i];
    }
}
