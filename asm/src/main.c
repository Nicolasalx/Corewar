/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "asm.h"

int main(int argc, const char *argv[])
{
    check_arg_validity(argc, argv);
    lauch_compilation(argv[1]);
    free_all_alloc();
    return 0;
}
