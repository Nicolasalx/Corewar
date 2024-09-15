/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** decode_int
*/

#include "my_importall.h"
#include "corewar.h"
#include <unistd.h>
#include <sys/types.h>
#include <stdint.h>

ssize_t little_to_big_endian(ssize_t value, size_t size)
{
    ssize_t result = 0;
    uint8_t *value_ptr = (uint8_t *) &value;
    uint8_t *result_ptr = (uint8_t *) &result;

    for (size_t i = 0; i < size; ++i) {
        result_ptr[i] = value_ptr[size - i - 1];
    }
    return result;
}

int decode_int(unsigned char *mem, size_t size)
{
    int result = 0;
    short int int_2 = 0;

    my_memcpy(&result, mem, size);
    if (is_little_endian) {
        if (size == 2) {
            int_2 = little_to_big_endian(result, size);
            result = int_2;
        } else {
            result = little_to_big_endian(result, size);
        }
    }
    return result;
}
