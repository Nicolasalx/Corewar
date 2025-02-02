/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** op
*/

#include "op.h"
#include "my_def.h"
#include <stdlib.h>
#include <stdbool.h>

op_t op_tab[] = {
    {"live", 1, false, false, true, {T_DIR}, 1, 10, "alive"},
    {"ld", 2, true, false, true, {T_DIR | T_IND, T_REG}, 2, 5, "load"},
    {"st", 2, true, false, true, {T_REG, T_IND | T_REG}, 3, 5, "store"},
    {"add", 3, true, false, true, {T_REG, T_REG, T_REG}, 4, 10, "addition"},
    {"sub", 3, true, false, true, {T_REG, T_REG, T_REG}, 5, 10, "soustraction"},
    {"and", 3, true, false, true, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR,
    T_REG}, 6, 6, "et (and  r1, r2, r3   r1&r2 -> r3"},
    {"or", 3, true, false, true, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR,
    T_REG}, 7, 6, "ou  (or   r1, r2, r3   r1 | r2 -> r3"},
    {"xor", 3, true, false, true, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR,
    T_REG}, 8, 6, "ou (xor  r1, r2, r3   r1^r2 -> r3"},
    {"zjmp", 1, false, true, true, {T_DIR}, 9, 20, "jump if zero"},
    {"ldi", 3, true, true, true, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
    10, 25, "load index"},
    {"sti", 3, true, true, true, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG},
    11, 25, "store index"},
    {"fork", 1, false, true, true, {T_DIR}, 12, 800, "fork"},
    {"lld", 2, true, false, false, {T_DIR | T_IND, T_REG}, 13, 10, "long load"},
    {"lldi", 3, true, true, false, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
    14, 50, "long load index"},
    {"lfork", 1, false, true, false, {T_DIR}, 15, 1000, "long fork"},
    {"aff", 1, true, false, true, {T_REG}, 16, 2, "aff"}
};

int nb_op = NB_ELEM(op_tab);
