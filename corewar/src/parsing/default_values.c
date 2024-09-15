/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** default_values.c
*/

#include "corewar.h"

corewar_t corewar = {
    .load_adress = -1,
    .prog_number = 0,
    .buffer_file = NULL,
    .size_file = 0
};

info_champ_t info_champ = {
    .size_prog = 0,
    .stock_info_prog = NULL
};

parsing_corewar_t parsing_corewar = {
    .have_load_adress = false,
    .already_dump = false,
    .already_find_file = false,
    .have_prog_nb = false,
    .nb_champ = 0,
    .nbr_cycle = -1
};

tmp_parsing_t tmp_parsing = {
    .load_adress = 0,
    .prog_number = 0
};
