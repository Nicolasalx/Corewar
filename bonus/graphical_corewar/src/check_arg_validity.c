/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** check_arg_validity
*/

#include "corewar.h"
#include "my_importall.h"

static void is_number_taken(node_t *head_corewar, int num)
{
    node_t *current = head_corewar;
    int nb_equality = 0;

    if (head_corewar == NULL) {
        return;
    }
    do {
        if (GET_DATA(current, corewar_t)->prog_number != 0
        && GET_DATA(current, corewar_t)->prog_number == num) {
            ++ nb_equality;
        }
        if (nb_equality >= 2) {
            print_error("There is two program with the same number.\n");
            my_exit(84);
        }
        current = current->next;
    } while (current != head_corewar);
}

void check_arg_validity(node_t *head_corewar)
{
    node_t *current = head_corewar;

    if (parsing_corewar.nb_champ < 2 || parsing_corewar.nb_champ > 4) {
        print_error("Invalid number of champion.\n");
        my_exit(84);
    }
    if (head_corewar == NULL) {
        return;
    }
    do {
        is_number_taken(head_corewar,
            GET_DATA(current, corewar_t)->prog_number);
        current = current->next;
    } while (current != head_corewar);
}
