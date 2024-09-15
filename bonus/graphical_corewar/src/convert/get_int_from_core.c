/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** get_int_from_core
*/

#include "corewar.h"
#include "my_importall.h"

int get_int_from_core(node_t *core, size_t size)
{
    unsigned char mem[MAX_ARG_SIZE] = {0};

    if (size == 1) {
        return GET_DATA(core, core_t)->data;
    } else {
        return decode_int(core_to_mem(core, mem, size), size);
    }
}
