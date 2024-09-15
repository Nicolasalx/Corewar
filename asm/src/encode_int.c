/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** program_encoding
*/

#include "asm.h"
#include <unistd.h>
#include <sys/types.h>
#include <stdint.h>

static ssize_t little_to_big_endian(ssize_t value, size_t size)
{
    ssize_t result = 0;
    uint8_t *value_ptr = (uint8_t *) &value;
    uint8_t *result_ptr = (uint8_t *) &result;

    for (size_t i = 0; i < size; ++i) {
        result_ptr[i] = value_ptr[size - i - 1];
    }
    return result;
}

void encode_int(int *value, size_t size)
{
    if (is_little_endian) {
        *value = little_to_big_endian(*value, size);
    }
}
