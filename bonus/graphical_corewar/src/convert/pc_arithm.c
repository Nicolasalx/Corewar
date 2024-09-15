/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** pc_arithm
*/

#include "my_importall.h"

node_t *pc_arithm(node_t *pc, int op)
{
    if (op >= 0) {
        for (int i = 0; i < op; ++i) {
            pc = pc->next;
        }
    } else {
        for (int i = 0; i > op; --i) {
            pc = pc->prev;
        }
    }
    return pc;
}
