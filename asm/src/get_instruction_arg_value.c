/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** get_instruction_arg_value
*/

#include "asm.h"

static void get_reg_arg(char *arg, int num_arg, inst_t *instruction)
{
    if (my_strlen(arg) < 2) {
        print_error(INVALID_ARG_MSG, arg, "\n");
        my_exit(84);
    }
    ++ arg;
    instruction->arg[num_arg] = my_get_nb(arg);
    instruction->size_arg[num_arg] = REG_SIZE;
    if (not my_str_only_cont(arg, NUM_CHAR)
        || instruction->arg[num_arg] < 1 || instruction->arg[num_arg] > 16) {
        print_error(RED("Invalid register number: "),
        "r", INT(instruction->arg[num_arg]), "\n");
        my_exit(84);
    }
    instruction->size_arg[num_arg] = REG_SIZE;
}

static void get_dir_arg(char *arg, int num_arg, inst_t *instruction)
{
    ++ arg;
    if (arg[0] == ':') {
        mem_label_t *label = my_malloc(sizeof(mem_label_t));
        instruction->arg[num_arg] = DEFAULT_LABEL_VALUE;
        ++ arg;
        label->name = arg;
        label->pos = current_pos_in_prog;
        label->arg_num = num_arg;
        append_node(&head_label_to_fill, create_node(label));
    } else {
        instruction->arg[num_arg] = my_get_nb(arg);
        if (not my_str_only_cont(arg, NUM_CHAR) ||
            (instruction->arg[num_arg] == 0 && my_strcmp(arg, "0") != 0)) {
            print_error(INVALID_VALUE_MSG, arg, "\n");
            my_exit(84);
        }
    }
    instruction->size_arg[num_arg] =
        instruction->is_index ? IDX_DIRECT_SIZE : DIRECT_SIZE;
}

static void get_ind_arg(char *arg, int num_arg, inst_t *instruction)
{
    if (arg[0] == ':') {
        mem_label_t *label = my_malloc(sizeof(mem_label_t));
        instruction->arg[num_arg] = DEFAULT_LABEL_VALUE;
        ++ arg;
        label->name = arg;
        label->pos = current_pos_in_prog;
        label->arg_num = num_arg;
        append_node(&head_label_to_fill, create_node(label));
    } else {
        instruction->arg[num_arg] = my_get_nb(arg);
        if (not my_str_only_cont(arg, NUM_CHAR)
            || (instruction->arg[num_arg] == 0 && my_strcmp(arg, "0") != 0)) {
            print_error(INVALID_VALUE_MSG, arg, "\n");
            my_exit(84);
        }
    }
    instruction->size_arg[num_arg] = INDIRECT_SIZE;
}

void get_instruction_arg_value(char *arg,
    int num_arg, int type, inst_t *instruction)
{
    if (type == T_REG) {
        get_reg_arg(arg, num_arg, instruction);
    }
    if (type == T_DIR) {
        if (my_strlen(arg) < 2) {
            print_error(INVALID_ARG_MSG, arg, "\n");
            my_exit(84);
        }
        get_dir_arg(arg, num_arg, instruction);
    }
    if (type == T_IND) {
        get_ind_arg(arg, num_arg, instruction);
    }
}
