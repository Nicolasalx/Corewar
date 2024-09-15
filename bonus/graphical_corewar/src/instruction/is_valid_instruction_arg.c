/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** is_valid_instruction_arg
*/

#include "my_importall.h"
#include "op.h"
#include "corewar.h"

bool is_valid_instruction_arg(inst_t *instruction)
{
    for (int i = 0; i < instruction->nb_arg; ++i) {
        if (not (instruction->arg_type[i] & op_tab[instruction->num - 1].type[i])) {
            return false;
        }
        if (instruction->arg_type[i] == T_REG
        && not is_valid_reg(instruction->arg[i])) {
            return false;
        }
    }
    return true;
}
