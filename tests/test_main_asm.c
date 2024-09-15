/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** asm_main_test
*/

#include "asm.h"

int test_main_asm(int argc, const char *argv[])
{
    check_arg_validity(argc, argv);
    lauch_compilation(argv[1]);
    free_all_alloc();
    return 0;
}
