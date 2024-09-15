/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** my_and
*/

#include "my_importall.h"
#include "op.h"
#include "corewar.h"

void my_and(champion_t *champion, inst_t *instruction)
{
    if (not is_valid_instruction_arg(instruction)) {
        return;
    }
    compute_instruction_arg_value(
        champion, instruction, FIRST_ARG, OP_REG_SIZE);
    compute_instruction_arg_value(
        champion, instruction, SECONDE_ARG, OP_REG_SIZE);
    champion->reg[instruction->arg[THIRD_ARG] - 1] =
    instruction->arg[FIRST_ARG] & instruction->arg[SECONDE_ARG];
    compute_carry(champion, champion->reg[instruction->arg[THIRD_ARG] - 1]);
}
