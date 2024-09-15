/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** my_st
*/

#include "my_importall.h"
#include "op.h"
#include "corewar.h"

void my_st(champion_t *champion, inst_t *instruction)
{
    if (not is_valid_instruction_arg(instruction)) {
        return;
    }
    if (instruction->arg_type[SECONDE_ARG] == T_IND) {
        write_int_in_core(pc_arithm(champion->pc_ptr,
            instruction->arg[SECONDE_ARG] % IDX_MOD),
            champion->champion_index,
            champion->reg[instruction->arg[FIRST_ARG] - 1],
            OP_REG_SIZE);
    } else {
        champion->reg[instruction->arg[SECONDE_ARG] - 1] =
            champion->reg[instruction->arg[FIRST_ARG] - 1];
    }
}
