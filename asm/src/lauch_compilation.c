/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** lauch_compilation
*/

#include "asm.h"

void lauch_compilation(const char *file_path)
{
    char **file_content = get_file_content(file_path);
    champion_t champion = {0};

    remove_all_comment(file_content);
    get_champion_header(file_content, &champion.header);
    remove_useless_line(&file_content);
    check_code_content_validity(file_content);
    define_endian_type();
    interpret_program(file_content);
    champion.header.prog_size = compute_size_program();
    write_program_in_file(champion.header.prog_size,
        file_path, &champion.header);
}
