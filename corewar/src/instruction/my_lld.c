/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** my_lld
*/

#include "my_importall.h"
#include "op.h"
#include "corewar.h"

void my_lld(champion_t *champion, inst_t *instruction)
{
    if (not is_valid_instruction_arg(instruction)) {
        return;
    }
    compute_instruction_arg_value(
        champion, instruction, FIRST_ARG, OP_REG_SIZE);
    champion->reg[instruction->arg[SECONDE_ARG] - 1] =
        instruction->arg[FIRST_ARG];
    compute_carry(champion, instruction->arg[FIRST_ARG]);
}
