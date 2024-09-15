/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** create_window
*/

#include "graphical.h"

sfRenderWindow *gr_window;

void create_window(void)
{
    gr_window = sfRenderWindow_create((sfVideoMode) {1920, 1080, 32},
        "Corewar", sfClose, NULL);
    if (!gr_window) {
        print_error(RED("Fail to create render window"));
        my_exit(84);
    }
    sfRenderWindow_setFramerateLimit(gr_window, FRAME_RATE);
}
