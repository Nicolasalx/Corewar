/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** detect_flags.c
*/

#include "corewar.h"
#include <fcntl.h>
#include <unistd.h>

static void help_option(void)
{
    print("USAGE:\n\n"
    "./corewar [-dump nbr_cycle] [[-n prog_number] [-a load_address]"
    "prog_name] ...\n\n"
    "DESCRIPTION\n\n"
    "-dump:\n"
    "nbr_cycle dumps the memory after the nbr_cycle execution\n"
    "(if the round isn't already over) with the following format:"
    " 32 bytes/line\n"
    "in hexadecimal (A0BCDEFE1DD3...)\n\n"
    "-n:\n"
    "prog_number sets the next program's number. By default, the first"
    " free number\n"
    "in the parameter order\n\n"
    "-a:\n"
    "load_address sets the next program's loading address. When no address is"
    "specified, optimize the addresses so that the processes are as far"
    "away from each other as possible. The addresses are MEM_SIZE modulo.\n");
}

static void choose_flags(const char **argv, int *i, node_t **head_corewar)
{
    if (my_strcmp(argv[*i], "-dump") == 0) {
        get_nb_cycle(argv[*i + 1]);
        ++ *i;
        return;
    }
    if (my_strcmp(argv[*i], "-n") == 0) {
        get_nb_prog_number(argv[*i + 1]);
        ++*i;
        return;
    }
    if (my_strcmp(argv[*i], "-a") == 0) {
        get_load_address(argv[*i + 1]);
        ++*i;
        return;
    }
    if (my_strcmp(argv[*i], "-h") == 0) {
        help_option();
        return;
    }
    get_info_file(argv[*i], head_corewar);
}

void flags(int argc, const char **argv, node_t **head_corewar)
{
    if (argc < 2) {
        my_puterror("Invalid number of argument.\n");
        my_exit(84);
    }
    for (int i = 1; i < argc; ++i) {
        choose_flags(argv, &i, head_corewar);
    }
    if (parsing_corewar.already_find_file == false) {
        my_puterror("No file find.\n");
        my_exit(84);
    }
    if (parsing_corewar.have_load_adress == true) {
        my_puterror("You have not same number of load adress than file.\n");
        my_exit(84);
    }
    if (parsing_corewar.have_prog_nb == true) {
        my_puterror("You have not same number of prog number than file.\n");
        my_exit(84);
    }
}
