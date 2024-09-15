/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** place_champion_in_vm
*/

#include "op.h"
#include "my_importall.h"
#include "corewar.h"

void cpy_mem_in_vm(node_t *vm, unsigned char *mem,
    size_t size, int player_index)
{
    node_t *current = vm;

    for (size_t i = 0; i < size; ++i) {
        GET_DATA(current, core_t)->data = mem[i];
        GET_DATA(current, core_t)->num_player = player_index;
        current = current->next;
    }
}

void place_champion_in_vm(void)
{
    for (int i = 0; i < nb_champion; ++i) {
        cpy_mem_in_vm(GET_DATA(head_all_champion[i], champion_t)->pc_ptr,
        ref_champion[i].prog, ref_champion[i].header.prog_size, i);
    }
}
