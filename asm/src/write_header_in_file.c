/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** write_header_in_file
*/

#include "asm.h"
#include <unistd.h>

void write_header_in_file(int fd, header_t *header)
{
    int tmp_prog_size = header->prog_size;

    encode_int(&header->magic, sizeof(int));
    encode_int(&header->prog_size, sizeof(int));
    write(fd, header, sizeof(header_t));
    header->prog_size = tmp_prog_size;
    header->magic = COREWAR_EXEC_MAGIC;
}
