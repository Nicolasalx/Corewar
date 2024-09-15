/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** my_lfork
*/

#include "my_importall.h"
#include "op.h"
#include "corewar.h"

static void cpy_champion_state(champion_t *new_champion,
    champion_t *champion, inst_t *instruction)
{
    new_champion->carry = champion->carry;
    new_champion->champion_index = champion->champion_index;
    new_champion->pc_ptr = pc_arithm(champion->pc_ptr, instruction->arg[FIRST_ARG]);
    new_champion->pc = GET_DATA(new_champion->pc_ptr, core_t)->address;
    my_memcpy(new_champion->reg, champion->reg, sizeof(int) * REG_NUMBER);
    append_node(&head_all_champion[champion->champion_index],
        create_node(new_champion));
    cpy_mem_in_vm(new_champion->pc_ptr,
        ref_champion[champion->champion_index].prog,
        ref_champion[champion->champion_index].header.prog_size,
        champion->champion_index);
}

void my_lfork(champion_t *champion, inst_t *instruction)
{
    champion_t *new_champion;

    if (not is_valid_instruction_arg(instruction)) {
        return;
    }
    ++ ref_champion[champion->champion_index].nb_proc;
    new_champion = my_malloc(sizeof(champion_t));
    cpy_champion_state(new_champion, champion, instruction);
    if (is_instruction_exist(GET_DATA(champion->pc_ptr, core_t)->data)) {
        new_champion->cooldown = op_tab[
            GET_DATA(new_champion->pc_ptr, core_t)->data - 1].nbr_cycles;
    }
}
