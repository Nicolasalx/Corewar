/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** get_instruction
*/

#include "corewar.h"
#include "my_importall.h"
#include "op.h"

static void get_instruction_param(node_t **core, inst_t *instruction)
{
    unsigned char mem[MAX_ARG_SIZE] = {0};

    for (int i = 0; i < instruction->nb_arg; ++i) {
        my_memset(mem, 0, MAX_ARG_SIZE);
        if (instruction->size_arg[i] == 1) {
            instruction->arg[i] = GET_DATA((*core), core_t)->data;
        } else {
            instruction->arg[i] = decode_int(
                core_to_mem(*core, mem, instruction->size_arg[i]),
                instruction->size_arg[i]);
        }
        for (int j = 0; j < instruction->size_arg[i]; ++j) {
            (*core) = (*core)->next;
            ++ instruction->size;
        }
    }
}

void get_instruction(node_t *core, inst_t *instruction)
{
    instruction->num = GET_DATA(core, core_t)->data;
    instruction->nb_arg = op_tab[instruction->num - 1].nbr_args;
    core = core->next;
    ++ instruction->size;
    if (op_tab[instruction->num - 1].take_diff_arg) {
        get_avanced_param_type(core, instruction);
        core = core->next;
        ++ instruction->size;
    } else {
        get_simple_param_type(instruction);
    }
    get_instruction_param(&core, instruction);
}
