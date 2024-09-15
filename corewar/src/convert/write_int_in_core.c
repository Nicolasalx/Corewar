/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** write_int_in_core
*/

#include "my_importall.h"
#include "corewar.h"

void write_int_in_core(node_t *core, int num_player, int value, size_t size)
{
    unsigned char mem[MAX_ARG_SIZE] = {0};

    encode_int(&value, size);
    my_memcpy(mem, &value, size);

    for (size_t i = 0; i < size; ++i) {
        GET_DATA(core, core_t)->data = mem[i];
        GET_DATA(core, core_t)->num_player = num_player;
        core = core->next;
    }
}
