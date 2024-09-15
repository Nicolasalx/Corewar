/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** my_zjmp
*/

#include "my_importall.h"
#include "op.h"
#include "corewar.h"

void my_zjmp(champion_t *champion, inst_t *instruction)
{
    if (champion->carry == true) {
        champion->pc_ptr =
            pc_arithm(champion->pc_ptr, instruction->arg[FIRST_ARG] % IDX_MOD);
    }
}
