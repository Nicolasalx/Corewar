/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** ini_champion_data
*/

#include "corewar.h"
#include "my_importall.h"

static bool is_number_taken(node_t *head_corewar, int num)
{
    node_t *current = head_corewar;
    int nb_equality = 0;

    if (head_corewar == NULL) {
        return false;
    }
    do {
        if (GET_DATA(current, corewar_t)->prog_number == num) {
            ++ nb_equality;
        }
        if (nb_equality >= 1) {
            return true;
        }
        current = current->next;
    } while (current != head_corewar);
    return false;
}

static int get_champion_num(node_t *head_corewar)
{
    static int num = 0;

    ++ num;
    while (is_number_taken(head_corewar, num)) {
        ++ num;
    }
    return num;
}

void ini_champion_data(node_t *head_corewar)
{
    node_t *current = head_corewar;
    int load_address = 0;

    if (head_corewar == NULL) {
        return;
    }
    do {
        if (GET_DATA(current, corewar_t)->prog_number == 0) {
            GET_DATA(current, corewar_t)->prog_number =
                get_champion_num(head_corewar);
        }
        if (GET_DATA(current, corewar_t)->load_adress == 0) {
            GET_DATA(current, corewar_t)->load_adress = load_address;
        }
        GET_DATA(current, corewar_t)->load_adress =
            GET_DATA(current, corewar_t)->load_adress % MEM_SIZE;
        load_address += MEM_SIZE / parsing_corewar.nb_champ;
        current = current->next;
    } while (current != head_corewar);
}
