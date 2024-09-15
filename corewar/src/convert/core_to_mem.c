/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** core_to_mem
*/

#include "my_importall.h"
#include "op.h"
#include "corewar.h"

unsigned char *core_to_mem(node_t *core, unsigned char *mem, size_t size)
{
    for (size_t i = 0; i < size; ++i) {
        mem[i] = GET_DATA(core, core_t)->data;
        core = core->next;
    }
    return mem;
}
