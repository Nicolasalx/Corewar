/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** my_aff
*/

#include "my_importall.h"
#include "op.h"
#include "corewar.h"

void my_aff(champion_t *champion, inst_t *instruction)
{
    if (not is_valid_instruction_arg(instruction)) {
        return;
    }
    my_putchar(champion->reg[instruction->arg[FIRST_ARG] - 1] % 256);
}
