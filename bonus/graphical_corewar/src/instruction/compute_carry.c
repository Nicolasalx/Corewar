/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** compute_carry
*/

#include "my_importall.h"
#include "op.h"
#include "corewar.h"

void compute_carry(champion_t *champion, int result_op)
{
    if (result_op) {
        champion->carry = false;
    } else {
        champion->carry = true;
    }
}