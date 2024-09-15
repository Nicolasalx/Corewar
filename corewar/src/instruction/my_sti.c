/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** sti
*/

#include "my_importall.h"
#include "op.h"
#include "corewar.h"

void my_sti(champion_t *champion, inst_t *instruction)
{
    if (not is_valid_instruction_arg(instruction)) {
        return;
    }
    compute_instruction_arg_value(
        champion, instruction, SECONDE_ARG, OP_REG_SIZE);
    compute_instruction_arg_value(
        champion, instruction, THIRD_ARG, OP_REG_SIZE);
    write_int_in_core(pc_arithm(champion->pc_ptr,
        (instruction->arg[SECONDE_ARG]
        + instruction->arg[THIRD_ARG]) % IDX_MOD),
        champion->champion_index,
        champion->reg[instruction->arg[FIRST_ARG] - 1],
        OP_REG_SIZE);
}
