/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** get_label
*/

#include "asm.h"

static bool is_unique_label(char *new_label)
{
    node_t *current = head_label;

    if (head_label == NULL) {
        return true;
    }
    do {
        if (my_strcmp(new_label, GET_DATA(current, label_t)->name) == 0) {
            return false;
        }
        current = current->next;
    } while (current != head_label);
    return true;
}

bool get_label(char *first_arg, int size_first_arg)
{
    label_t *label = my_malloc(sizeof(label_t));

    if (first_arg[size_first_arg - 1] != ':') {
        return false;
    }
    first_arg[size_first_arg - 1] = '\0';
    if (not is_unique_label(first_arg)) {
        print_error(RED("Multiple definition of the same label: "), first_arg);
        my_exit(84);
    }
    if (not my_str_only_cont(first_arg, LABEL_CHARS)) {
        print_error(RED("Invalid label name: "), first_arg);
        my_exit(84);
    }
    label->name = first_arg;
    label->pos = current_pos_in_prog;
    append_node(&head_label, create_node(label));
    return true;
}
