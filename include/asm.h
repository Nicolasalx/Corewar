/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** asm
*/

#ifndef ASM_H_
    #define ASM_H_

    #include "my_importall.h"
    #include "op.h"
    #include <sys/types.h>

    #define LINE_IS_VALID 0
    #define LINE_IS_INVALID 1

    #define SYNTAX_ERROR_MSG RED("Syntax error: ")
    #define WARNING_MSG BOLD_MAGENTA("warning: ")
    #define INVALID_ARG_MSG RED("Invalid arg: ")
    #define INVALID_VALUE_MSG RED("Invalid value: ")

    #define REG_SIZE 1
    #define INDIRECT_SIZE 2
    #define DIRECT_SIZE 4

    #define IDX_REG_SIZE 1
    #define IDX_INDIRECT_SIZE 2
    #define IDX_DIRECT_SIZE 2

    #define REG_CHAR 'r'

    #define DEFAULT_LABEL_VALUE 0

    #define RESULT_FILE_EXTENSION ".cor"

typedef struct {
    header_t header;
} champion_t;

typedef struct {
    int num;
    int nb_arg;
    bool is_index;
    bool has_diff_arg;
    int arg_type[MAX_ARGS_NUMBER - 1];
    int arg[MAX_ARGS_NUMBER - 1];
    size_t size_arg[MAX_ARGS_NUMBER - 1];
    size_t size;
} inst_t;

typedef struct {
    char *name;
    size_t pos;
} label_t;

typedef struct {
    char *name;
    size_t pos;
    int arg_num;
} mem_label_t;

extern bool is_little_endian;
extern size_t current_pos_in_prog;

extern node_t *head_prog;
extern node_t *head_label;
extern node_t *head_label_to_fill;

void check_arg_validity(int argc, const char **argv);
void lauch_compilation(const char *file_path);
char **get_file_content(const char *file_path);
void remove_all_comment(char **file_content);
void find_champion_name(char *line, bool *name_found, char *prog_name);
void find_champion_comment(char *line,
    bool *comment_found, char *comment);
void get_champion_header(char **file_content, header_t *header);
bool is_empty_line(char *str);
void remove_useless_line(char ***file_content);
void check_code_content_validity(char **file_content);
void define_endian_type(void);
bool get_label(char *first_arg, int size_first_arg);
void interpret_program(char **file_content);
void compute_size_instruction(inst_t *instruction);
void get_instruction(char **arg, int nb_arg, inst_t *instruction);
void get_instruction_arg_value(char *arg,
    int num_arg, int type, inst_t *instruction);
size_t compute_size_program(void);
void write_program_in_file(int program_size,
    const char *src_file_name, header_t *header);
void write_header_in_file(int fd, header_t *header);
void encode_int(int *value, size_t size);
void compute_label_value(void);
char *get_result_file_name(const char *src_file_name);

#endif /* !ASM_H_ */
