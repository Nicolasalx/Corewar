/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** my_lldi
*/

#include "my_importall.h"
#include "op.h"
#include "corewar.h"

void my_lldi(champion_t *champion, inst_t *instruction)
{
    int s;

    if (not is_valid_instruction_arg(instruction)) {
        return;
    }
    compute_instruction_arg_value(
        champion, instruction, FIRST_ARG, OP_IND_SIZE);
    compute_instruction_arg_value(
        champion, instruction, SECONDE_ARG, OP_IND_SIZE);
    s = instruction->arg[FIRST_ARG] + instruction->arg[SECONDE_ARG];

    champion->reg[instruction->arg[THIRD_ARG] - 1] = get_int_from_core(
        pc_arithm(champion->pc_ptr, s), OP_REG_SIZE);
    compute_carry(champion, champion->reg[instruction->arg[THIRD_ARG] - 1]);
}
