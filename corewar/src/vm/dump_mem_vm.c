/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** dump_mem_vm
*/

#include "my_importall.h"
#include "corewar.h"

static void print_index_byte(int index_byte)
{
    char index_byte_hex[sizeof(int) * 2];

    int_to_hex(index_byte, index_byte_hex);
    print_buffer(index_byte_hex, sizeof(int) * 2);
    print_buffer("  ", 2);
}

static bool is_pc(node_t *current_cor)
{
    node_t *current = NULL;
    bool result = false;

    for (int i = 0; i < nb_champion; ++i) {
        if (head_all_champion[i] == NULL) {
            continue;
        }
        current = head_all_champion[i];
        do {
            result = result ? result :
            (GET_DATA(current, champion_t)->pc_ptr == current_cor);
            current = current->next;
        } while (current != head_all_champion[i]);
    }
    return result;
}

static void print_byte_of_vm(node_t *current, char *hex)
{
    if (is_pc(current)) {
        print_buffer(INVERT_COLOR, my_strlen(INVERT_COLOR));
    }
    print_buffer(player_color[GET_DATA(current, core_t)->num_player],
        my_strlen(player_color[GET_DATA(current, core_t)->num_player]));
    print_buffer(hex, 2);
    print_buffer(RESET_COLOR, my_strlen(RESET_COLOR));
}

static void print_mem_vm(node_t *current, int *i, int *index_byte)
{
    char hex[2];

    byte_to_hex(GET_DATA(current, core_t)->data, hex);
    if (*i == 0) {
        print_index_byte(*index_byte);
        print_byte_of_vm(current, hex);
    } else {
        if (*i % 8 == 0) {
            print_buffer(" ", 1);
        }
        print_buffer(" ", 1);
        print_byte_of_vm(current, hex);
    }
    ++ *index_byte;
    ++ *i;
    if (*i >= NB_BYTE_BY_LINE) {
        *i = 0;
        print_buffer("\n", 1);
    }
}

void dump_mem_vm(node_t *head_vm)
{
    node_t *current = head_vm;
    int i = 0;
    int index_byte = 0;

    if (head_vm == NULL) {
        return;
    }
    do {
        print_mem_vm(current, &i, &index_byte);
        current = current->next;
    } while (current != head_vm);
    flush_buffer();
}
