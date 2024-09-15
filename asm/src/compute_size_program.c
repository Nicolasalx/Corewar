/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** compute_size_program
*/

#include "asm.h"

size_t compute_size_program(void)
{
    node_t *current = head_prog;
    size_t program_size = 0;

    if (head_prog == NULL) {
        return program_size;
    }
    do {
        program_size += GET_DATA(current, inst_t)->size;
        current = current->next;
    } while (current != head_prog);
    return program_size;
}
