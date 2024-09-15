/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** lauch_simulation
*/

#include "op.h"
#include "my_importall.h"
#include "corewar.h"
#include "graphical.h"

static void simulate_each_champion(node_t **current)
{
    if (GET_DATA(*current, champion_t)->cooldown <= 0) {
        execute_instruction(GET_DATA(*current, champion_t));
    } else {
        -- GET_DATA(*current, champion_t)->cooldown;
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
            simulate_each_champion(&current);
            if (current != NULL) {
                current = current->next;
            }
        } while (current != NULL && current != head_all_champion[i]);
    }
}

void lauch_simulation(node_t *head_vm, int nb_cycle)
{
    int cycle_num = 0;
    int check_alive = 0;
    int nb_live = NBR_LIVE;
    int count_frame = 0;
    sfEvent event;
    mouse_button_pressed = false;

    while (sfRenderWindow_isOpen(gr_window)) {
        mouse_button_pressed = false;
        while (sfRenderWindow_pollEvent(gr_window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(gr_window);
            }
            mouse_pos = sfMouse_getPositionRenderWindow(gr_window);
            if (event.type == sfEvtMouseButtonPressed) {
                mouse_button_pressed = true;
            }
        sfRenderWindow_clear(gr_window, sfBlack);
        game_menu();
        if (game_activated == true) {
            count_frame = 0;
            while (count_frame < NB_CYCLE_PER_FRAME) {
                if (cycle_num > nb_cycle) {
                    sfRenderWindow_close(gr_window);
                }
                simulate_all_champion();
                if (check_dead_champion(&check_alive, &nb_live)) {
                    sfRenderWindow_close(gr_window);
                }
                ++ cycle_num;
                ++ count_frame;
            }
            update_visualization(head_vm, cycle_num);
        }
        sfRenderWindow_display(gr_window);
    }
    sfRenderWindow_destroy(gr_window);
}
