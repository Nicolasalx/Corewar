/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** lauch_vm
*/

#include "op.h"
#include "my_importall.h"
#include "corewar.h"

static void compute_cooldown(void)
{
    champion_t *champion;

    for (int i = 0; i < nb_champion; ++i) {
        champion = GET_DATA(head_all_champion[i], champion_t);
        if (is_instruction_exist(GET_DATA(champion->pc_ptr, core_t)->data)) {
            champion->cooldown = op_tab[
                GET_DATA(champion->pc_ptr, core_t)->data - 1].nbr_cycles;
        }
    }
}

static void print_winner(void)
{
    if (no_champion_is_alive() || only_one_champion_left()) {
        if (last_champion_killed == -1) {
            print("The player ", INT(ref_champion[nb_champion - 1].num), "(",
            ref_champion[nb_champion - 1].header.prog_name,
            ")has won.\n");
        } else {
            print("The player ", INT(ref_champion[last_champion_killed].num),
            "(", ref_champion[last_champion_killed].header.prog_name,
            ")has won.\n");
        }
    }
}

void lauch_vm(int nb_cycle)
{
    node_t *head_vm = NULL;

    ini_vm(&head_vm);
    create_all_champion(head_vm);
    place_champion_in_vm();
    compute_cooldown();
    if (nb_cycle == -1) {
        nb_cycle = MAX_INT;
    }
    lauch_simulation(nb_cycle);
    if (nb_cycle != MAX_INT) {
        dump_mem_vm(head_vm);
    }
    print_winner();
}
