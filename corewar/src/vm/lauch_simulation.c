/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** lauch_simulation
*/

#include "op.h"
#include "my_importall.h"
#include "corewar.h"

static void simulate_each_champion(node_t *current)
{
    if (GET_DATA(current, champion_t)->cooldown <= 0) {
        execute_instruction(GET_DATA(current, champion_t));
    } else {
        -- GET_DATA(current, champion_t)->cooldown;
    }
}

static void simulate_all_champion(void)
{
    node_t *current = NULL;

    for (int i = 0; i < nb_champion; ++i) {
        current = head_all_champion[i];
        if (head_all_champion[i] == NULL) {
            continue;
        }
        do {
            simulate_each_champion(current);
            current = current->next;
        } while (current != head_all_champion[i]);
    }
}

void lauch_simulation(int nb_cycle)
{
    int cycle_num = 0;
    int check_alive = 0;
    int nb_live = NBR_LIVE;

    while (true) {
        if (cycle_num > nb_cycle) {
            return;
        }
        simulate_all_champion();
        if (check_dead_champion(&check_alive, &nb_live)) {
            return;
        }
        ++ cycle_num;
    }
}
