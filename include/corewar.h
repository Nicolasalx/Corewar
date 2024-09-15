/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** corewar
*/

#ifndef COREWAR_H_
    #define COREWAR_H_

    #define REG_NUMBER 16

    #define REG_SIZE 1
    #define INDIRECT_SIZE 2
    #define DIRECT_SIZE 4

    #define IDX_REG_SIZE 1
    #define IDX_INDIRECT_SIZE 2
    #define IDX_DIRECT_SIZE 2

    #define NB_BYTE_BY_LINE 32

    #define MAX_NB_CHAMPION 4

    #define MAX_ARG_SIZE 4

    #define FIRST_ARG 0
    #define SECONDE_ARG 1
    #define THIRD_ARG 2

    #include "my_importall.h"
    #include "op.h"
    #include <sys/types.h>

typedef struct {
    int prog_number;
    int load_adress;
    unsigned char *buffer_file;
    int size_file;
} corewar_t;

typedef struct {
    int size_prog;
    unsigned char *stock_info_prog;
} info_champ_t;

typedef struct {
    bool already_find_file;
    bool already_dump;
    int nbr_cycle;
    int nb_champ;
    bool have_load_adress;
    bool have_prog_nb;
} parsing_corewar_t;

typedef struct {
    int prog_number;
    int load_adress;
} tmp_parsing_t;

typedef struct {
    int champion_index;
    int reg[REG_NUMBER];
    int pc;
    node_t *pc_ptr;
    bool carry;
    int cooldown;
} champion_t;

typedef struct {
    int num;
    int load_address;
    header_t header;
    unsigned char *prog;
    int alive;
} ref_champion_t;

typedef enum {
    PLAYER_1,
    PLAYER_2,
    PLAYER_3,
    PLAYER_4,
    NONE_PLAYER
} player_e;

typedef struct {
    unsigned char data;
    int num_player;
    size_t address;
} core_t;

typedef struct {
    int num;
    int nb_arg;
    int arg_type[MAX_ARGS_NUMBER - 1];
    int size_arg[MAX_ARGS_NUMBER - 1];
    int arg[MAX_ARGS_NUMBER - 1];
    size_t size;
} inst_t;

typedef enum {
    LIVE,
    LD,
    ST,
    ADD,
    SUB,
    AND,
    OR,
    XOR,
    ZJMP,
    LDI,
    STI,
    FORK,
    LLD,
    LLDI,
    LFORK,
    AFF
} inst_e;

extern int nb_op;

extern tmp_parsing_t tmp_parsing;
extern header_t header;
extern parsing_corewar_t parsing_corewar;
extern corewar_t corewar;

extern bool is_little_endian;
extern int nb_champion;
extern int last_champion_killed;
extern int cycle_to_die;

extern node_t *head_all_champion[MAX_NB_CHAMPION];
extern ref_champion_t ref_champion[MAX_NB_CHAMPION];

extern char *player_color[];

extern bool upd_champion_pc[];

extern void (*instruction_func[])(champion_t *champion, inst_t *instruction);

void check_arg_validity(node_t *head_corewar);
void ini_champion_data(node_t *head_corewar);

void flags(int argc, const char **argv, node_t **head_corewar);
void get_info_file(const char *filepath, node_t **head_corewar);
void get_nb_prog_number(const char *str);
void get_load_address(const char *str);
void get_nb_cycle(const char *str);

void define_endian_type(void);
ssize_t little_to_big_endian(ssize_t value, size_t size);
int decode_int(unsigned char *mem, size_t size);
void byte_to_hex(unsigned char byte, char *hex);
void int_to_hex(int num, char *hex);
void encode_int(int *value, size_t size);
node_t *pc_arithm(node_t *pc, int op);
void write_int_in_core(node_t *core, int num_player, int value, size_t size);
unsigned char *core_to_mem(node_t *core, unsigned char *mem, size_t size);
int get_int_from_core(node_t *core, size_t size);
void cpy_mem_in_vm(node_t *vm, unsigned char *mem,
    size_t size, int player_index);

void create_ref_champion(node_t *head_corewar);
void create_all_champion(node_t *vm);
void place_champion_in_vm(void);
void ini_vm(node_t **head_vm);
void lauch_vm(int nb_cycle);
void dump_mem_vm(node_t *head_vm);

bool no_champion_is_alive(void);
bool only_one_champion_left(void);
void kill_all_dead_champion(void);
bool check_dead_champion(int *check_alive, int *nb_live);
void lauch_simulation(int nb_cycle);
void declare_alive_champion(void);
bool is_instruction_exist(unsigned char data);
void get_avanced_param_type(node_t *core, inst_t *instruction);
void get_simple_param_type(inst_t *instruction);
void get_instruction(node_t *core, inst_t *instruction);
void execute_instruction(champion_t *champion);
bool is_valid_reg(int reg);
void update_champion_pc(champion_t *champion, inst_t *instruction);
void set_cooldown_next_instruction(champion_t *champion);

void compute_instruction_arg_value(champion_t *champion,
    inst_t *instruction, int arg_num, int size_ind);
bool is_valid_instruction_arg(inst_t *instruction);
void compute_carry(champion_t *champion, int result_op);

void my_live(champion_t *champion, inst_t *instruction);
void my_ld(champion_t *champion, inst_t *instruction);
void my_st(champion_t *champion, inst_t *instruction);
void my_add(champion_t *champion, inst_t *instruction);
void my_sub(champion_t *champion, inst_t *instruction);
void my_and(champion_t *champion, inst_t *instruction);
void my_or(champion_t *champion, inst_t *instruction);
void my_xor(champion_t *champion, inst_t *instruction);
void my_zjmp(champion_t *champion, inst_t *instruction);
void my_ldi(champion_t *champion, inst_t *instruction);
void my_sti(champion_t *champion, inst_t *instruction);
void my_fork(champion_t *champion, inst_t *instruction);
void my_lld(champion_t *champion, inst_t *instruction);
void my_lldi(champion_t *champion, inst_t *instruction);
void my_lfork(champion_t *champion, inst_t *instruction);
void my_aff(champion_t *champion, inst_t *instruction);

#endif /* !COREWAR_H_ */
