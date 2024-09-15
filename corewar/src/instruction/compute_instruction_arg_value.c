/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** compute_instruction_arg_value
*/

#include "my_importall.h"
#include "op.h"
#include "corewar.h"

static void compute_reg(int i, champion_t *champion,
    inst_t *instruction)
{
    if (instruction->arg_type[i] == T_REG) {
        instruction->arg[i] = champion->reg[instruction->arg[i] - 1];
    }
}

static void compute_ind(int i, champion_t *champion,
    inst_t *instruction, int size_ind)
{
    if (instruction->arg_type[i] == T_IND) {
        if (op_tab[instruction->num - 1].apply_mod) {
            instruction->arg[i] = get_int_from_core(pc_arithm(
            champion->pc_ptr, instruction->arg[i] % IDX_MOD), size_ind);
        } else {
            instruction->arg[i] = get_int_from_core(pc_arithm(
            champion->pc_ptr, instruction->arg[i]), size_ind);
        }
    }
}

void compute_instruction_arg_value(champion_t *champion,
    inst_t *instruction, int arg_num, int size_ind)
{
    compute_reg(arg_num, champion, instruction);
    compute_ind(arg_num, champion, instruction, size_ind);
}
