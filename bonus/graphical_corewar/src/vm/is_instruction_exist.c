/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** is_instruction_exist
*/

#include "my_importall.h"
#include "op.h"

bool is_instruction_exist(unsigned char data)
{
    if (data >= 1 && data <= nb_op) {
        return true;
    }
    return false;
}
