/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "corewar.h"
#include "my_importall.h"

int main(int argc, const char **argv)
{
    node_t *head_corewar = NULL;

    define_endian_type();
    flags(argc, argv, &head_corewar);
    check_arg_validity(head_corewar);

    nb_champion = parsing_corewar.nb_champ;
    ini_champion_data(head_corewar);
    create_ref_champion(head_corewar);
    lauch_vm(parsing_corewar.nbr_cycle);
    free_all_alloc();
    return 0;
}
