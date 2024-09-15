/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** interprete_program
*/

#include "asm.h"
#include <unistd.h>
#include <sys/types.h>

size_t current_pos_in_prog = {0};

node_t *head_prog = {NULL};
node_t *head_label = {NULL};
node_t *head_label_to_fill = {NULL};

static void interpre_instruction(char **arg,
    int *size_arg, int nb_arg, inst_t *instruction)
{
    bool has_label = get_label(arg[0], size_arg[0]);

    if (nb_arg > 1 && has_label) {
        ++ arg;
        -- nb_arg;
        get_instruction(arg, nb_arg, instruction);
    }
    if (nb_arg == 1 && not has_label) {
        print_error(RED("Unknow instruction: "), arg[0], "\n");
        my_exit(84);
    }
    if (nb_arg > 1) {
        if (not has_label) {
            get_instruction(arg, nb_arg, instruction);
        }
        append_node(&head_prog, create_node(instruction));
        ++ current_pos_in_prog;
    }
}

static void interpret_line(char *line)
{
    int nb_arg = count_nb_word(line, ARG_SEPARATOR);
    int *size_arg = count_size_word(line, ARG_SEPARATOR, nb_arg);
    char **arg = my_str_to_word(line, ARG_SEPARATOR, nb_arg, size_arg);
    inst_t *instruction = my_malloc(sizeof(inst_t));

    if (nb_arg < 1) {
        print_error(SYNTAX_ERROR_MSG, line);
        my_exit(84);
    }
    interpre_instruction(arg, size_arg, nb_arg, instruction);
}

void interpret_program(char **file_content)
{
    for (int i = 0; file_content[i] != NULL; ++i) {
        interpret_line(file_content[i]);
    }
}
