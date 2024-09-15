/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** is_little_endian
*/

#include <stdint.h>
#include <stdbool.h>

bool is_little_endian = {false};

void define_endian_type(void)
{
    uint16_t value = 0x01;
    uint8_t *byte_ptr = (uint8_t *) &value;

    is_little_endian = (*byte_ptr == 0x01);
}
