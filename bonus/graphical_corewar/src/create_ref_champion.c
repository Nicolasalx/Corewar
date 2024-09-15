/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** create_ref_champion
*/

#include "corewar.h"
#include "my_importall.h"

static void get_header_champion(node_t *current, header_t *header)
{
    my_memcpy(header,
        GET_DATA(current, corewar_t)->buffer_file, sizeof(header_t));
    header->magic = little_to_big_endian(header->magic, sizeof(int));
    header->prog_size = little_to_big_endian(header->prog_size, sizeof(int));
}

static void get_prog_champion(node_t *current, ref_champion_t *ref_champion)
{
    if (ref_champion->header.magic != COREWAR_EXEC_MAGIC) {
        print_error(BOLD_RED("Invalid file.\n"));
        my_exit(84);
    }
    if (GET_DATA(current, corewar_t)->size_file -
        (int) sizeof(header_t) != ref_champion->header.prog_size) {
        print_error(BOLD_RED("Corrupted file content.\n"));
        my_exit(84);
    }
    ref_champion->prog = my_malloc(
        sizeof(unsigned char) * ref_champion->header.prog_size);
    my_memcpy(ref_champion->prog,
        &GET_DATA(current, corewar_t)->buffer_file[sizeof(header_t)],
        ref_champion->header.prog_size);
}

void create_ref_champion(node_t *head_corewar)
{
    node_t *current = head_corewar;

    for (int i = 0; i < nb_champion; ++i) {
        ref_champion[i].num = GET_DATA(current, corewar_t)->prog_number;
        ref_champion[i].load_address =
            GET_DATA(current, corewar_t)->load_adress;
        get_header_champion(current, &ref_champion[i].header);
        get_prog_champion(current, &ref_champion[i]);
        ref_champion[i].alive = 0;
        ref_champion[i].nb_proc = 1;
        current = current->next;
    }
}
