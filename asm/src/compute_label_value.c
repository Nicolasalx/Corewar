/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** compute_label_value
*/

#include "asm.h"

static int get_reference_label_pos(char *name_label)
{
    node_t *current = head_label;

    if (head_label == NULL) {
        print(RED("Undefined label: "), name_label, "\n");
        my_exit(84);
    }
    do {
        if (my_strcmp(name_label, GET_DATA(current, label_t)->name) == 0) {
            return GET_DATA(current, label_t)->pos;
        }
        current = current->next;
    } while (current != head_label);
    print(RED("Undefined label: "), name_label, "\n");
    my_exit(84);
    return -1;
}

static node_t *label_node_ptr(int mem_label_pos)
{
    node_t *current = head_prog;

    if (head_prog == NULL) {
        return NULL;
    }
    for (int i = 0; i < mem_label_pos; ++i) {
        current = current->next;
    }
    return current;
}

static void compute_label_delta_size(int ref_label_pos,
    int mem_label_pos, int index_arg)
{
    int delta = ref_label_pos - mem_label_pos;
    node_t *mem_label = label_node_ptr(mem_label_pos);
    int *size = &GET_DATA(mem_label, inst_t)->arg[index_arg];

    if (delta >= 0) {
        for (int i = 0; i < delta; ++i) {
            *size += GET_DATA(mem_label, inst_t)->size;
            mem_label = mem_label->next;
        }
    } else {
        for (int i = 0; i > delta; --i) {
            mem_label = mem_label->prev;
            *size -= GET_DATA(mem_label, inst_t)->size;
        }
    }
}

void compute_label_value(void)
{
    node_t *current = head_label_to_fill;
    int ref_label_pos;

    if (head_label_to_fill == NULL) {
        return;
    }
    do {
        ref_label_pos = get_reference_label_pos(
            GET_DATA(current, mem_label_t)->name);
        compute_label_delta_size(ref_label_pos,
            GET_DATA(current, mem_label_t)->pos,
            GET_DATA(current, mem_label_t)->arg_num);
        current = current->next;
    } while (current != head_label_to_fill);
}
