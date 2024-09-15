/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** get_info_file
*/

#include "corewar.h"
#include "my_importall.h"
#include <fcntl.h>
#include <unistd.h>

static void verif_size_file_and_buffer(int size_file)
{
    if (size_file <= 0) {
        my_puterror("The file is empty.\n");
        my_exit(84);
    }
    if (size_file < (int) sizeof(header_t)) {
        print_error(BOLD_RED("Corrupted file content.\n"));
        my_exit(84);
    }
}

static void check_arg_with_stat(const char *filepath)
{
    if (is_a_dir(filepath) == true) {
        print_error(filepath, ": is not a file.\n");
        my_exit(84);
    }
}

static void get_buffer_file(const int fd, const char *filepath,
    node_t **head_corewar)
{
    int value_file = 0;
    corewar_t *corewar = my_calloc(sizeof(corewar_t));

    check_arg_with_stat(filepath);
    corewar->size_file = my_filelen(filepath);
    corewar->buffer_file =
        my_malloc(sizeof(unsigned char) * (corewar->size_file));
    verif_size_file_and_buffer(corewar->size_file);
    value_file = read(fd, corewar->buffer_file, corewar->size_file);
    if (value_file == -1) {
        my_puterror("Failed to read.\n");
        my_exit(84);
    }
    corewar->load_adress = tmp_parsing.load_adress;
    corewar->prog_number = tmp_parsing.prog_number;

    append_node(head_corewar, create_node(corewar));
}

void get_info_file(const char *filepath, node_t **head_corewar)
{
    int fd = open(filepath, O_RDONLY);

    if (fd == -1) {
        my_puterror("Failed to open file.\n");
        my_exit(84);
    }
    get_buffer_file(fd, filepath, head_corewar);

    parsing_corewar.nb_champ += 1;
    parsing_corewar.already_find_file = true;
    parsing_corewar.have_load_adress = false;
    parsing_corewar.have_prog_nb = false;
    tmp_parsing.load_adress = 0;
    tmp_parsing.prog_number = 0;
    close(fd);
}
