/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** write_program_in_file
*/

#include "asm.h"
#include <unistd.h>
#include <fcntl.h>

static void my_revbyte(unsigned char *byte)
{
    unsigned char byte_cpy = *byte;
    int rev_i = 0;

    for (int i = 7; i >= 0; --i) {
        if (get_bit_value(byte_cpy, i)) {
            set_bit_to_one(byte, rev_i);
        } else {
            set_bit_to_zero(byte, rev_i);
        }
        ++ rev_i;
    }
}

static unsigned char encode_arg_type(int nb_arg, int *arg_type)
{
    unsigned char code_arg_type = 0;

    for (int i = 0; i < nb_arg; ++i) {
        switch (arg_type[i]) {
        case T_REG:
            set_bit_to_one(&code_arg_type, 1 + (2 * i));
            break;
        case T_DIR:
            set_bit_to_one(&code_arg_type, 0 + (2 * i));
            break;
        case T_IND:
            set_bit_to_one(&code_arg_type, 0 + (2 * i));
            set_bit_to_one(&code_arg_type, 1 + (2 * i));
            break;
        }
    }
    my_revbyte(&code_arg_type);
    return code_arg_type;
}

static void write_result_in_file(const char *src_file_name,
    unsigned char *program, int program_size, header_t *header)
{
    int fd = open(get_result_file_name(src_file_name),
        O_WRONLY | O_TRUNC | O_CREAT, 0644);

    if (fd == -1) {
        print_fatal_error_and_exit(OPEN_FAIL);
    }
    write_header_in_file(fd, header);
    write(fd, program, program_size);
}

static void compute_program_value(node_t *current, unsigned char **index)
{
    int tmp = 0;
    unsigned char arg_type;

    my_memcpy(*index, &GET_DATA(current, inst_t)->num, 1);
    ++ *index;
    if (GET_DATA(current, inst_t)->has_diff_arg) {
        arg_type = encode_arg_type(GET_DATA(current, inst_t)->nb_arg,
            GET_DATA(current, inst_t)->arg_type);
        my_memcpy(*index, &arg_type, 1);
        ++ *index;
    }
    for (int i = 0; i < GET_DATA(current, inst_t)->nb_arg; ++i) {
        tmp = GET_DATA(current, inst_t)->arg[i];
        encode_int(&GET_DATA(current, inst_t)->arg[i],
            GET_DATA(current, inst_t)->size_arg[i]);
        my_memcpy(*index, &GET_DATA(current, inst_t)->arg[i],
            GET_DATA(current, inst_t)->size_arg[i]);
        *index += GET_DATA(current, inst_t)->size_arg[i];
        GET_DATA(current, inst_t)->arg[i] = tmp;
    }
}

void write_program_in_file(int program_size,
    const char *src_file_name, header_t *header)
{
    unsigned char *program = my_malloc(sizeof(unsigned char) * program_size);
    node_t *current = head_prog;
    unsigned char *index = program;

    if (head_prog == NULL) {
        write_result_in_file(src_file_name, program, program_size, header);
        return;
    }
    compute_label_value();
    do {
        compute_program_value(current, &index);
        current = current->next;
    } while (current != head_prog);
    write_result_in_file(src_file_name, program, program_size, header);
}
