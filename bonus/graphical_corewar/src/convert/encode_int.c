/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** encode_int
*/

#include "corewar.h"
#include "my_importall.h"

void encode_int(int *value, size_t size)
{
    if (is_little_endian) {
        *value = little_to_big_endian(*value, size);
    }
}
