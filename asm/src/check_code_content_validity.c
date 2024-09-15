/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** check_code_content_validity
*/

#include "asm.h"

void check_code_content_validity(char **file_content)
{
    for (int i = 0; file_content[i] != NULL; ++i) {
        if (not my_str_only_cont(file_content[i], VALID_CODE_CONTENT)) {
            print_error(SYNTAX_ERROR_MSG, file_content[i], "\n");
            my_exit(84);
        }
    }
}
