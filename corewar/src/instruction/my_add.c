/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** my_add
*/

#include "my_importall.h"
#include "op.h"
#include "corewar.h"

void my_add(champion_t *champion, inst_t *instruction)
{
    if (not is_valid_instruction_arg(instruction)) {
        return;
    }
    champion->reg[instruction->arg[THIRD_ARG] - 1] =
        champion->reg[instruction->arg[FIRST_ARG] - 1] +
        champion->reg[instruction->arg[SECONDE_ARG] - 1];
    compute_carry(champion, champion->reg[instruction->arg[THIRD_ARG] - 1]);
}
