/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** execute_instruction
*/

#include "corewar.h"
#include "my_importall.h"
#include "op.h"

void physically_exec_instruction(champion_t *champion, inst_t *instruction)
{
    instruction_func[instruction->num - 1](champion, instruction);
}

void execute_instruction(champion_t *champion)
{
    inst_t instruction = {0};

    if (not is_instruction_exist(GET_DATA(champion->pc_ptr, core_t)->data)) {
        return;
    }
    get_instruction(champion->pc_ptr, &instruction);
    physically_exec_instruction(champion, &instruction);
    if (upd_champion_pc[instruction.num - 1]) {
        update_champion_pc(champion, &instruction);
    }
    set_cooldown_next_instruction(champion);
}
