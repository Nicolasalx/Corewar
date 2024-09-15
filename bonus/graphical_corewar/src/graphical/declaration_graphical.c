/*
** EPITECH PROJECT, 2023
** graphical_corewar
** File description:
** declaration_graphical
*/

#include "graphical.h"

gr_vm_t gr_vm;
sfFont *gr_font;

sfColor gr_player_color[] = {
    {0, 255, 0, 255},
    {255, 255, 0, 255},
    {0, 255, 255, 255},
    {255, 0, 255, 255},
    {255, 255, 255, 255}
};

size_t NB_CYCLE_PER_FRAME = 10;
