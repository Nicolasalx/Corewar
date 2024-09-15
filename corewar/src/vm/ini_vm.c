/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** ini_vm
*/

#include "op.h"
#include "my_importall.h"
#include "corewar.h"

void ini_vm(node_t **head_vm)
{
    core_t *core;
    size_t current_address = 0;

    for (int i = 0; i < MEM_SIZE; ++i) {
        core = my_malloc(sizeof(core_t));
        core->data = 0;
        core->address = current_address;
        core->num_player = NONE_PLAYER;
        append_node(head_vm, create_node(core));
        ++ current_address;
    }
}
