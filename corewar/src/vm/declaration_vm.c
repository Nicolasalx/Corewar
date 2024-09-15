/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** declaration_vm
** to see all possible color:
** https://misc.flogisoft.com/bash/tip_colors_and_formatting
*/

#include "corewar.h"

int nb_champion;

ref_champion_t ref_champion[MAX_NB_CHAMPION] = {0};

node_t *head_all_champion[MAX_NB_CHAMPION] = {0};

int last_champion_killed = -1;
int cycle_to_die = CYCLE_TO_DIE;

char *player_color[] = {
    [PLAYER_1] = "\e[92m",
    [PLAYER_2] = "\e[93m",
    [PLAYER_3] = "\e[96m",
    [PLAYER_4] = "\e[95m",
    [NONE_PLAYER] = "\e[0m"
};

bool upd_champion_pc[] = {
    [LIVE] = true,
    [LD] = true,
    [ST] = true,
    [ADD] = true,
    [SUB] = true,
    [AND] = true,
    [OR] = true,
    [XOR] = true,
    [ZJMP] = false,
    [LDI] = true,
    [STI] = true,
    [FORK] = true,
    [LLD] = true,
    [LLDI] = true,
    [LFORK] = true,
    [AFF] = true
};

void (*instruction_func[])(champion_t *champion, inst_t *instruction) = {
    [LIVE] = my_live,
    [LD] = my_ld,
    [ST] = my_st,
    [ADD] = my_add,
    [SUB] = my_sub,
    [AND] = my_and,
    [OR] = my_or,
    [XOR] = my_xor,
    [ZJMP] = my_zjmp,
    [LDI] = my_ldi,
    [STI] = my_sti,
    [FORK] = my_fork,
    [LLD] = my_lld,
    [LLDI] = my_lldi,
    [LFORK] = my_lfork,
    [AFF] = my_aff
};
