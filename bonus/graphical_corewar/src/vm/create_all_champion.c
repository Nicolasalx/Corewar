/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** create_all_champion
*/

#include "op.h"
#include "my_importall.h"
#include "corewar.h"

static node_t *get_pc_ptr(int pc, node_t *vm)
{
    node_t *current = vm;

    for (int i = 0; i < pc; ++i) {
        current = current->next;
    }
    return current;
}

void create_all_champion(node_t *vm)
{
    champion_t *champion;

    for (int i = 0; i < nb_champion; ++i) {
        champion = my_malloc(sizeof(champion_t));
        champion->carry = false;
        champion->cooldown = 0;
        champion->champion_index = i;
        champion->pc = ref_champion[i].load_address;
        champion->pc_ptr = get_pc_ptr(ref_champion[i].load_address, vm);
        my_memset(champion->reg, 0, sizeof(int) * REG_NUMBER);
        champion->reg[0] = ref_champion[i].num;
        append_node(&head_all_champion[i], create_node(champion));
    }
}
