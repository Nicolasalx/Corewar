/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** is_valid_reg
*/

#include "my_importall.h"

bool is_valid_reg(int reg)
{
    if (reg < 1 || reg > 16) {
        return false;
    }
    return true;
}
