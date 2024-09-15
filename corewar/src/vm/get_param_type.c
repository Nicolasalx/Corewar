/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** get_param_type
*/

#include "corewar.h"
#include "my_importall.h"
#include "op.h"

static void get_all_bit_value(bool *result, unsigned char c)
{
    int rev_i = 7;

    for (int i = 0; i < 8; ++i) {
        result[rev_i] = get_bit_value(c, i);
        -- rev_i;
    }
}

void get_avanced_param_type(node_t *core, inst_t *instruction)
{
    bool result[8] = {0};

    get_all_bit_value(result, GET_DATA(core, core_t)->data);
    for (int i = 0; i < 3; ++i) {
        if (result[(i * 2)] == 0 && result[(i * 2) + 1] == 1) {
            instruction->arg_type[i] = T_REG;
            instruction->size_arg[i] = REG_SIZE;
        }
        if (result[(i * 2)] == 1 && result[(i * 2) + 1] == 0) {
            instruction->arg_type[i] = T_DIR;
            instruction->size_arg[i] =
                (op_tab[instruction->num - 1].take_index) ?
                IDX_DIRECT_SIZE : DIRECT_SIZE;
        }
        if (result[(i * 2)] == 1 && result[(i * 2) + 1] == 1) {
            instruction->arg_type[i] = T_IND;
            instruction->size_arg[i] = INDIRECT_SIZE;
        }
    }
}

void get_simple_param_type(inst_t *instruction)
{
    for (int i = 0; i < instruction->nb_arg; ++i) {
        instruction->arg_type[i] = op_tab[instruction->num - 1].type[i];
        if (instruction->arg_type[i] == T_REG) {
            instruction->size_arg[i] = REG_SIZE;
        }
        if (instruction->arg_type[i] == T_DIR) {
            instruction->size_arg[i] =
                (op_tab[instruction->num - 1].take_index) ?
                IDX_DIRECT_SIZE : DIRECT_SIZE;
        }
        if (instruction->arg_type[i] == T_IND) {
            instruction->size_arg[i] = INDIRECT_SIZE;
        }
    }
}
