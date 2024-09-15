/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** check_arg_validity
*/

#include "asm.h"

static void print_usage(void)
{
    print("USAGE\n"
        "\t./asm file_name[.s]\n"
        "DESCRIPTION\n"
        "\tfile_name file in assembly language"
        "to be converted into file_name.cor, an"
        "executable in the Virtual Machine.\n");
}

void check_arg_validity(int argc, const char **argv)
{
    if (argc != 2) {
        print_usage();
        my_exit(84);
    }
    if (my_strcmp(argv[1], "-h") == 0) {
        print_usage();
        my_exit(0);
    }
}
