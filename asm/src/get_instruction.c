/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** get_instruction
*/

#include "asm.h"
#include <unistd.h>
#include <sys/types.h>

static int get_instruction_num(char *inst)
{
    for (int i = 0; i < nb_op; ++i) {
        if (my_strcmp(inst, op_tab[i].mnemonique) == 0) {
            return op_tab[i].code;
        }
    }
    print_error(RED("Unknow instruction: "), inst, "\n");
    my_exit(84);
    return -1;
}

static int get_arg_type(char *arg)
{
    if (is_digit(arg[0]) || arg[0] == '-' || arg[0] == ':') {
        return T_IND;
    }
    switch (arg[0]) {
    case 'r':
        return T_REG;
        break;
    case '%':
        return T_DIR;
        break;
    }
    print_error(RED("Unknwow type of argument: "), arg, "\n");
    my_exit(84);
    return -1;
}

static void get_instruction_arg(char *arg, int num_arg, inst_t *instruction)
{
    instruction->arg_type[num_arg] = get_arg_type(arg);
    if (op_tab[instruction->num - 1].type[num_arg]
    & instruction->arg_type[num_arg]) {
        get_instruction_arg_value(arg, num_arg,
        instruction->arg_type[num_arg], instruction);
    } else {
        print_error(RED("Incompatible type of argument: "), arg, "\n");
        my_exit(84);
    }
}

void get_instruction(char **arg, int nb_arg, inst_t *instruction)
{
    instruction->num = get_instruction_num(arg[0]);
    instruction->has_diff_arg = op_tab[instruction->num - 1].take_diff_arg;
    instruction->nb_arg = op_tab[instruction->num - 1].nbr_args;
    instruction->is_index = op_tab[instruction->num - 1].take_index;
    if (op_tab[instruction->num - 1].nbr_args != nb_arg - 1) {
        print_error(RED("Invalid number of argument: "), arg[0],
        " expect ", INT(op_tab[instruction->num - 1].nbr_args),
        " arg but get ", INT(nb_arg - 1), " arg.\n");
        my_exit(84);
    }
    for (int i = 1; arg[i] != NULL; ++i) {
        get_instruction_arg(arg[i], i - 1, instruction);
    }
    compute_size_instruction(instruction);
}
